# xdev68k
https://github.com/yosshin4004/xdev68k


## 事前定義されるマクロの一覧
xdev68k(WSL/gcc 12.2.0)にて`m68k-elf-gcc -dM -E - < /dev/null` で出力したものです。  
バージョンにより違いがあるかもしれないので注意してください。

```c
#define __ATOMIC_ACQ_REL 4
#define __ATOMIC_ACQUIRE 2
#define __ATOMIC_CONSUME 1
#define __ATOMIC_RELAXED 0
#define __ATOMIC_RELEASE 3
#define __ATOMIC_SEQ_CST 5
#define __BIGGEST_ALIGNMENT__ 2
#define __BYTE_ORDER__ __ORDER_BIG_ENDIAN__
#define __CHAR_BIT__ 8
#define __CHAR16_TYPE__ short unsigned int
#define __CHAR32_TYPE__ long unsigned int
#define __DBL_DECIMAL_DIG__ 17
#define __DBL_DENORM_MIN__ ((double)4.94065645841246544177e-324L)
#define __DBL_DIG__ 15
#define __DBL_EPSILON__ ((double)2.22044604925031308085e-16L)
#define __DBL_HAS_DENORM__ 1
#define __DBL_HAS_INFINITY__ 1
#define __DBL_HAS_QUIET_NAN__ 1
#define __DBL_IS_IEC_60559__ 2
#define __DBL_MANT_DIG__ 53
#define __DBL_MAX__ ((double)1.79769313486231570815e+308L)
#define __DBL_MAX_10_EXP__ 308
#define __DBL_MAX_EXP__ 1024
#define __DBL_MIN__ ((double)2.22507385850720138309e-308L)
#define __DBL_MIN_10_EXP__ (-307)
#define __DBL_MIN_EXP__ (-1021)
#define __DBL_NORM_MAX__ ((double)1.79769313486231570815e+308L)
#define __DEC_EVAL_METHOD__ 2
#define __DECIMAL_DIG__ 21
#define __ELF__ 1
#define __embedded__ 1
#define __FINITE_MATH_ONLY__ 0
#define __FLOAT_WORD_ORDER__ __ORDER_BIG_ENDIAN__
#define __FLT_DECIMAL_DIG__ 9
#define __FLT_DENORM_MIN__ 1.40129846432481707092e-45F
#define __FLT_DIG__ 6
#define __FLT_EPSILON__ 1.19209289550781250000e-7F
#define __FLT_EVAL_METHOD__ 0
#define __FLT_EVAL_METHOD_TS_18661_3__ 0
#define __FLT_HAS_DENORM__ 1
#define __FLT_HAS_INFINITY__ 1
#define __FLT_HAS_QUIET_NAN__ 1
#define __FLT_IS_IEC_60559__ 2
#define __FLT_MANT_DIG__ 24
#define __FLT_MAX__ 3.40282346638528859812e+38F
#define __FLT_MAX_10_EXP__ 38
#define __FLT_MAX_EXP__ 128
#define __FLT_MIN__ 1.17549435082228750797e-38F
#define __FLT_MIN_10_EXP__ (-37)
#define __FLT_MIN_EXP__ (-125)
#define __FLT_NORM_MAX__ 3.40282346638528859812e+38F
#define __FLT_RADIX__ 2
#define __FLT32_DECIMAL_DIG__ 9
#define __FLT32_DENORM_MIN__ 1.40129846432481707092e-45F32
#define __FLT32_DIG__ 6
#define __FLT32_EPSILON__ 1.19209289550781250000e-7F32
#define __FLT32_HAS_DENORM__ 1
#define __FLT32_HAS_INFINITY__ 1
#define __FLT32_HAS_QUIET_NAN__ 1
#define __FLT32_IS_IEC_60559__ 2
#define __FLT32_MANT_DIG__ 24
#define __FLT32_MAX__ 3.40282346638528859812e+38F32
#define __FLT32_MAX_10_EXP__ 38
#define __FLT32_MAX_EXP__ 128
#define __FLT32_MIN__ 1.17549435082228750797e-38F32
#define __FLT32_MIN_10_EXP__ (-37)
#define __FLT32_MIN_EXP__ (-125)
#define __FLT32_NORM_MAX__ 3.40282346638528859812e+38F32
#define __FLT32X_DECIMAL_DIG__ 17
#define __FLT32X_DENORM_MIN__ 4.94065645841246544177e-324F32x
#define __FLT32X_DIG__ 15
#define __FLT32X_EPSILON__ 2.22044604925031308085e-16F32x
#define __FLT32X_HAS_DENORM__ 1
#define __FLT32X_HAS_INFINITY__ 1
#define __FLT32X_HAS_QUIET_NAN__ 1
#define __FLT32X_IS_IEC_60559__ 2
#define __FLT32X_MANT_DIG__ 53
#define __FLT32X_MAX__ 1.79769313486231570815e+308F32x
#define __FLT32X_MAX_10_EXP__ 308
#define __FLT32X_MAX_EXP__ 1024
#define __FLT32X_MIN__ 2.22507385850720138309e-308F32x
#define __FLT32X_MIN_10_EXP__ (-307)
#define __FLT32X_MIN_EXP__ (-1021)
#define __FLT32X_NORM_MAX__ 1.79769313486231570815e+308F32x
#define __FLT64_DECIMAL_DIG__ 17
#define __FLT64_DENORM_MIN__ 4.94065645841246544177e-324F64
#define __FLT64_DIG__ 15
#define __FLT64_EPSILON__ 2.22044604925031308085e-16F64
#define __FLT64_HAS_DENORM__ 1
#define __FLT64_HAS_INFINITY__ 1
#define __FLT64_HAS_QUIET_NAN__ 1
#define __FLT64_IS_IEC_60559__ 2
#define __FLT64_MANT_DIG__ 53
#define __FLT64_MAX__ 1.79769313486231570815e+308F64
#define __FLT64_MAX_10_EXP__ 308
#define __FLT64_MAX_EXP__ 1024
#define __FLT64_MIN__ 2.22507385850720138309e-308F64
#define __FLT64_MIN_10_EXP__ (-307)
#define __FLT64_MIN_EXP__ (-1021)
#define __FLT64_NORM_MAX__ 1.79769313486231570815e+308F64
#define __GCC_ATOMIC_BOOL_LOCK_FREE 1
#define __GCC_ATOMIC_CHAR_LOCK_FREE 1
#define __GCC_ATOMIC_CHAR16_T_LOCK_FREE 1
#define __GCC_ATOMIC_CHAR32_T_LOCK_FREE 1
#define __GCC_ATOMIC_INT_LOCK_FREE 1
#define __GCC_ATOMIC_LLONG_LOCK_FREE 1
#define __GCC_ATOMIC_LONG_LOCK_FREE 1
#define __GCC_ATOMIC_POINTER_LOCK_FREE 1
#define __GCC_ATOMIC_SHORT_LOCK_FREE 1
#define __GCC_ATOMIC_TEST_AND_SET_TRUEVAL 128
#define __GCC_ATOMIC_WCHAR_T_LOCK_FREE 1
#define __GCC_IEC_559 0
#define __GCC_IEC_559_COMPLEX 0
#define __GNUC__ 12
#define __GNUC_EXECUTION_CHARSET_NAME "UTF-8"
#define __GNUC_MINOR__ 2
#define __GNUC_PATCHLEVEL__ 0
#define __GNUC_STDC_INLINE__ 1
#define __GNUC_WIDE_EXECUTION_CHARSET_NAME "UTF-32BE"
#define __GXX_ABI_VERSION 1017
#define __HAVE_SPECULATION_SAFE_VALUE 1
#define __INT_FAST16_MAX__ 0x7fffffff
#define __INT_FAST16_TYPE__ int
#define __INT_FAST16_WIDTH__ 32
#define __INT_FAST32_MAX__ 0x7fffffff
#define __INT_FAST32_TYPE__ int
#define __INT_FAST32_WIDTH__ 32
#define __INT_FAST64_MAX__ 0x7fffffffffffffffLL
#define __INT_FAST64_TYPE__ long long int
#define __INT_FAST64_WIDTH__ 64
#define __INT_FAST8_MAX__ 0x7fffffff
#define __INT_FAST8_TYPE__ int
#define __INT_FAST8_WIDTH__ 32
#define __INT_LEAST16_MAX__ 0x7fff
#define __INT_LEAST16_TYPE__ short int
#define __INT_LEAST16_WIDTH__ 16
#define __INT_LEAST32_MAX__ 0x7fffffffL
#define __INT_LEAST32_TYPE__ long int
#define __INT_LEAST32_WIDTH__ 32
#define __INT_LEAST64_MAX__ 0x7fffffffffffffffLL
#define __INT_LEAST64_TYPE__ long long int
#define __INT_LEAST64_WIDTH__ 64
#define __INT_LEAST8_MAX__ 0x7f
#define __INT_LEAST8_TYPE__ signed char
#define __INT_LEAST8_WIDTH__ 8
#define __INT_MAX__ 0x7fffffff
#define __INT_WIDTH__ 32
#define __INT16_C(c) c
#define __INT16_MAX__ 0x7fff
#define __INT16_TYPE__ short int
#define __INT32_C(c) c ## L
#define __INT32_MAX__ 0x7fffffffL
#define __INT32_TYPE__ long int
#define __INT64_C(c) c ## LL
#define __INT64_MAX__ 0x7fffffffffffffffLL
#define __INT64_TYPE__ long long int
#define __INT8_C(c) c
#define __INT8_MAX__ 0x7f
#define __INT8_TYPE__ signed char
#define __INTMAX_C(c) c ## LL
#define __INTMAX_MAX__ 0x7fffffffffffffffLL
#define __INTMAX_TYPE__ long long int
#define __INTMAX_WIDTH__ 64
#define __INTPTR_MAX__ 0x7fffffffL
#define __INTPTR_TYPE__ long int
#define __INTPTR_WIDTH__ 32
#define __LDBL_DECIMAL_DIG__ 21
#define __LDBL_DENORM_MIN__ 1.82259976594123730126e-4951L
#define __LDBL_DIG__ 18
#define __LDBL_EPSILON__ 1.08420217248550443401e-19L
#define __LDBL_HAS_DENORM__ 1
#define __LDBL_HAS_INFINITY__ 1
#define __LDBL_HAS_QUIET_NAN__ 1
#define __LDBL_IS_IEC_60559__ 0
#define __LDBL_MANT_DIG__ 64
#define __LDBL_MAX__ 1.18973149535723176502e+4932L
#define __LDBL_MAX_10_EXP__ 4932
#define __LDBL_MAX_EXP__ 16384
#define __LDBL_MIN__ 1.68105157155604675313e-4932L
#define __LDBL_MIN_10_EXP__ (-4931)
#define __LDBL_MIN_EXP__ (-16382)
#define __LDBL_NORM_MAX__ 1.18973149535723176502e+4932L
#define __LONG_LONG_MAX__ 0x7fffffffffffffffLL
#define __LONG_LONG_WIDTH__ 64
#define __LONG_MAX__ 0x7fffffffL
#define __LONG_WIDTH__ 32
#define __m68k__ 1
#define __mc68000 1
#define __mc68000__ 1
#define __NO_INLINE__ 1
#define __ORDER_BIG_ENDIAN__ 4321
#define __ORDER_LITTLE_ENDIAN__ 1234
#define __ORDER_PDP_ENDIAN__ 3412
#define __PRAGMA_REDEFINE_EXTNAME 1
#define __PTRDIFF_MAX__ 0x7fffffffL
#define __PTRDIFF_TYPE__ long int
#define __PTRDIFF_WIDTH__ 32
#define __REGISTER_PREFIX__ %
#define __SCHAR_MAX__ 0x7f
#define __SCHAR_WIDTH__ 8
#define __SHRT_MAX__ 0x7fff
#define __SHRT_WIDTH__ 16
#define __SIG_ATOMIC_MAX__ 0x7fffffff
#define __SIG_ATOMIC_MIN__ (-__SIG_ATOMIC_MAX__ - 1)
#define __SIG_ATOMIC_TYPE__ int
#define __SIG_ATOMIC_WIDTH__ 32
#define __SIZE_MAX__ 0xffffffffUL
#define __SIZE_TYPE__ long unsigned int
#define __SIZE_WIDTH__ 32
#define __SIZEOF_DOUBLE__ 8
#define __SIZEOF_FLOAT__ 4
#define __SIZEOF_INT__ 4
#define __SIZEOF_LONG__ 4
#define __SIZEOF_LONG_DOUBLE__ 12
#define __SIZEOF_LONG_LONG__ 8
#define __SIZEOF_POINTER__ 4
#define __SIZEOF_PTRDIFF_T__ 4
#define __SIZEOF_SHORT__ 2
#define __SIZEOF_SIZE_T__ 4
#define __SIZEOF_WCHAR_T__ 4
#define __SIZEOF_WINT_T__ 4
#define __STDC__ 1
#define __STDC_HOSTED__ 1
#define __STDC_UTF_16__ 1
#define __STDC_UTF_32__ 1
#define __STDC_VERSION__ 201710L
#define __UINT_FAST16_MAX__ 0xffffffffU
#define __UINT_FAST16_TYPE__ unsigned int
#define __UINT_FAST32_MAX__ 0xffffffffU
#define __UINT_FAST32_TYPE__ unsigned int
#define __UINT_FAST64_MAX__ 0xffffffffffffffffULL
#define __UINT_FAST64_TYPE__ long long unsigned int
#define __UINT_FAST8_MAX__ 0xffffffffU
#define __UINT_FAST8_TYPE__ unsigned int
#define __UINT_LEAST16_MAX__ 0xffff
#define __UINT_LEAST16_TYPE__ short unsigned int
#define __UINT_LEAST32_MAX__ 0xffffffffUL
#define __UINT_LEAST32_TYPE__ long unsigned int
#define __UINT_LEAST64_MAX__ 0xffffffffffffffffULL
#define __UINT_LEAST64_TYPE__ long long unsigned int
#define __UINT_LEAST8_MAX__ 0xff
#define __UINT_LEAST8_TYPE__ unsigned char
#define __UINT16_C(c) c
#define __UINT16_MAX__ 0xffff
#define __UINT16_TYPE__ short unsigned int
#define __UINT32_C(c) c ## UL
#define __UINT32_MAX__ 0xffffffffUL
#define __UINT32_TYPE__ long unsigned int
#define __UINT64_C(c) c ## ULL
#define __UINT64_MAX__ 0xffffffffffffffffULL
#define __UINT64_TYPE__ long long unsigned int
#define __UINT8_C(c) c
#define __UINT8_MAX__ 0xff
#define __UINT8_TYPE__ unsigned char
#define __UINTMAX_C(c) c ## ULL
#define __UINTMAX_MAX__ 0xffffffffffffffffULL
#define __UINTMAX_TYPE__ long long unsigned int
#define __UINTPTR_MAX__ 0xffffffffUL
#define __UINTPTR_TYPE__ long unsigned int
#define __USER_LABEL_PREFIX__ 
#define __VERSION__ "12.2.0"
#define __WCHAR_MAX__ 0x7fffffffL
#define __WCHAR_MIN__ (-__WCHAR_MAX__ - 1)
#define __WCHAR_TYPE__ long int
#define __WCHAR_WIDTH__ 32
#define __WINT_MAX__ 0xffffffffU
#define __WINT_MIN__ 0U
#define __WINT_TYPE__ unsigned int
#define __WINT_WIDTH__ 32
#define mc68000 1
```



----
goto [index](../README.md) / [プログラミング](./README.md)
