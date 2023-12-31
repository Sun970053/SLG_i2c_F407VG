
#include <csp/interfaces/csp_if_i2c.h>
#include <csp/csp_id.h>
#include <csp/csp.h>
#include "stm32f4xx_hal.h"

#define CSP_TIMEOUT 1000

extern I2C_HandleTypeDef hi2c1;

int csp_i2c_driver_tx(void * driver_data, csp_packet_t * frame)
{
	/*HAL_StatusTypeDef HAL_I2C_Master_Transmit(I2C_HandleTypeDef *hi2c, uint16_t DevAddress,
												uint8_t *pData, uint16_t Size, uint32_t Timeout)*/
	HAL_I2C_DisableListen_IT(&hi2c1);
	HAL_I2C_Master_Transmit(&hi2c1, (frame->cfpid << 1), frame->frame_begin, frame->frame_length, CSP_TIMEOUT);

	HAL_I2C_EnableListen_IT(&hi2c1);
	//HAL_I2C_Slave_Receive_IT(&hi2c1, isr_rxData, SLAVE_RX_BUFFER_SIZE);
	csp_buffer_free(frame);
	return CSP_ERR_NONE;
}

int csp_i2c_tx(csp_iface_t * iface, uint16_t via, csp_packet_t * packet, int from_me) {

	/* Loopback */
	if (packet->id.dst == iface->addr) {
		csp_qfifo_write(packet, iface, NULL);
		return CSP_ERR_NONE;
	}

    /* Prepend the CSP ID to the packet */
    csp_id_prepend(packet);

	/* Use cfpid to transfer the physical destination address to the driver */
    packet->cfpid = (via != CSP_NO_VIA_ADDRESS) ? via : packet->id.dst;

    /* There is only 7 address bits available on CSP, so use the lower 7 bits for destination */
    packet->cfpid = packet->cfpid & 0x7F;

	/* send frame */
	csp_i2c_interface_data_t * ifdata = iface->interface_data;
	/* TODO */
    //csp_i2c_interface_data_t ifdata;
	ifdata->tx_func = csp_i2c_driver_tx;

	return (ifdata->tx_func)(iface->driver_data, packet);
}

/**
 * When a frame is received, cast it to a csp_packet
 * and send it directly to the CSP new packet function.
 * Context: ISR only
 */
void csp_i2c_rx(csp_iface_t * iface, csp_packet_t * packet, void * pxTaskWoken) {

	/* Validate input */
	if (packet == NULL) {
		return;
	}

	if (packet->frame_length < sizeof(uint32_t)) {
		iface->frame++;
		(pxTaskWoken != NULL) ? csp_buffer_free_isr(packet) : csp_buffer_free(packet);
		return;
	}

	/* Strip the CSP header off the length field before converting to CSP packet */
    csp_id_strip(packet);

	if (packet->frame_length > csp_buffer_data_size()) {  // consistency check, should never happen
		iface->rx_error++;
		(pxTaskWoken != NULL) ? csp_buffer_free_isr(packet) : csp_buffer_free(packet);
		return;
	}

	/* Receive the packet in CSP */
	csp_qfifo_write(packet, iface, pxTaskWoken);
}

int csp_i2c_add_interface(csp_iface_t * iface) {

	if ((iface == NULL) || (iface->name == NULL) || (iface->interface_data == NULL)) {
		return CSP_ERR_INVAL;
	}

	csp_i2c_interface_data_t * ifdata = iface->interface_data;
	if (ifdata->tx_func == NULL) {
		return CSP_ERR_INVAL;
	}

	const unsigned int max_data_size = csp_buffer_data_size();
	if ((iface->mtu == 0) || (iface->mtu > max_data_size)) {
		iface->mtu = max_data_size;
	}

	iface->nexthop = csp_i2c_tx;

	return csp_iflist_add(iface);
}
