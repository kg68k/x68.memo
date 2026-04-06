#ifndef __stdint_h__
#define __stdint_h__

#ifdef __cplusplus
extern "C" {
#endif

typedef long int intptr_t;
typedef long unsigned int uintptr_t;

typedef signed char int8_t;
typedef short int16_t;
typedef int int32_t;

#define INT8_MIN -128
#define INT8_MAX 127
#define INT16_MIN -32768
#define INT16_MAX 32767
#define INT32_MIN -2147483648
#define INT32_MAX 2147483647

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;

#define UINT8_MIN 0
#define UINT8_MAX 255
#define UINT16_MIN 0
#define UINT16_MAX 65535
#define UINT32_MIN 0
#define UINT32_MAX 4294967295

#ifdef __cplusplus
}
#endif

#endif
