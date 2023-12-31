/*
 * csp_autoconfig.h
 *
 *  Created on: Nov 2, 2023
 *      Author: spacelab-cute-PC
 */

#ifndef _INCLUDE_CSP_CSP_AUTOCONFIG_H_WAF
#define _INCLUDE_CSP_CSP_AUTOCONFIG_H_WAF

//#define GIT_REV "unknown"
//#define CSP_FREERTOS 1
///* #undef CSP_POSIX */
///* #undef CSP_WINDOWS */
///* #undef CSP_MACOSX */
//#define CSP_DEBUG 1
//#define CSP_VERBOSE 1
///* #undef CSP_USE_RDP */
//#define CSP_USE_CRC32 1
///* #undef CSP_USE_HMAC */
///* #undef CSP_USE_XTEA */
///* #undef CSP_USE_PROMISC */
///* #undef CSP_USE_QOS */
//#define CSP_CONN_MAX 10
//#define CSP_FIFO_INPUT 10
//#define CSP_MAX_BIND_PORT 31
//#define CSP_RDP_MAX_WINDOW 20
//#define CSP_PADDING_BYTES 8
//#define CSP_LOG_LEVEL_DEBUG 1
//#define CSP_LOG_LEVEL_INFO 1
//#define CSP_LOG_LEVEL_WARN 1
//#define CSP_LOG_LEVEL_ERROR 1
//#define CSP_LITTLE_ENDIAN 1
///* #undef CSP_BIG_ENDIAN */
//#define CSP_HAVE_STDBOOL_H 1
//#define CSP_USE_DEBUG_COLOR 0
//
//// #define CSP_POSIX
//// #define CSP_ZEPHYR
//
//#define CSP_HAVE_STDIO 1
//#define CSP_ENABLE_CSP_PRINT 1
//#define CSP_PRINT_STDIO 0
//
//#define CSP_QFIFO_LEN 15
//#define CSP_PORT_MAX_BIND 20
//#define CSP_CONN_RXQUEUE_LEN 16
//#define CSP_BUFFER_SIZE 256
//#define CSP_BUFFER_COUNT 15 //The device number in this CSP pool
//#define CSP_RTABLE_SIZE 10

#define GIT_REV "v1.2-3-g44bcdf7"
#define CSP_FREERTOS 1
/* #undef CSP_POSIX */
/* #undef CSP_WINDOWS */
/* #undef CSP_MACOSX */
#define CSP_DEBUG 1
#define CSP_VERBOSE 1
/* #undef CSP_USE_RDP */
#define CSP_USE_CRC32 1
/* #undef CSP_USE_HMAC */
/* #undef CSP_USE_XTEA */
/* #undef CSP_USE_PROMISC */
/* #undef CSP_USE_QOS */
//#define CSP_CONN_MAX 5
#define CSP_CONN_QUEUE_LENGTH 10
#define CSP_FIFO_INPUT 10
#define CSP_MAX_BIND_PORT 12
//#define CSP_RDP_MAX_WINDOW 20
#define CSP_PADDING_BYTES 8
#define CSP_LOG_LEVEL_DEBUG 1
#define CSP_LOG_LEVEL_INFO 1
#define CSP_LOG_LEVEL_WARN 1
#define CSP_LOG_LEVEL_ERROR 1
#define CSP_LITTLE_ENDIAN 1
/* #undef CSP_BIG_ENDIAN */
#define CSP_HAVE_STDBOOL_H 1
#define CSP_USE_DEBUG_COLOR 0

// #define CSP_POSIX
// #define CSP_ZEPHYR

#define CSP_HAVE_STDIO 1
#define CSP_ENABLE_CSP_PRINT 1
#define CSP_PRINT_STDIO 0

#define CSP_QFIFO_LEN 15
#define CSP_PORT_MAX_BIND 20
#define CSP_CONN_RXQUEUE_LEN 16
#define CSP_CONN_MAX 8
#define CSP_BUFFER_SIZE 256
#define CSP_BUFFER_COUNT 15 //The device number in this CSP pool
#define CSP_RDP_MAX_WINDOW 5
#define CSP_RTABLE_SIZE 10

#endif /* _INCLUDE_CSP_CSP_AUTOCONFIG_H_WAF */
