# elf2x68k
https://github.com/yunkya2/elf2x68k


----
## 事前定義されるマクロの一覧

elf2x68k(Release 20250907、GCC 13.4.0)にて
`m68k-xelf-gcc -dM -E - < /dev/null | sort`
で出力したものです。  

Release 20250907以降では`__human68k`と`__human68k__`の定義が追加されており、
ターゲットのOSの識別に使うことができます。

```c
#define __ATOMIC_ACQUIRE 2
#define __ATOMIC_ACQ_REL 4
#define __ATOMIC_CONSUME 1
#define __ATOMIC_RELAXED 0
#define __ATOMIC_RELEASE 3
#define __ATOMIC_SEQ_CST 5
#define __BIGGEST_ALIGNMENT__ 2
#define __BYTE_ORDER__ __ORDER_BIG_ENDIAN__
#define __CHAR16_TYPE__ short unsigned int
#define __CHAR32_TYPE__ long unsigned int
#define __CHAR_BIT__ 8
#define __DBL_DECIMAL_DIG__ 17
#define __DBL_DENORM_MIN__ ((double)4.94065645841246544177e-324L)
#define __DBL_DIG__ 15
#define __DBL_EPSILON__ ((double)2.22044604925031308085e-16L)
#define __DBL_HAS_DENORM__ 1
#define __DBL_HAS_INFINITY__ 1
#define __DBL_HAS_QUIET_NAN__ 1
#define __DBL_IS_IEC_60559__ 1
#define __DBL_MANT_DIG__ 53
#define __DBL_MAX_10_EXP__ 308
#define __DBL_MAX_EXP__ 1024
#define __DBL_MAX__ ((double)1.79769313486231570815e+308L)
#define __DBL_MIN_10_EXP__ (-307)
#define __DBL_MIN_EXP__ (-1021)
#define __DBL_MIN__ ((double)2.22507385850720138309e-308L)
#define __DBL_NORM_MAX__ ((double)1.79769313486231570815e+308L)
#define __DECIMAL_DIG__ 21
#define __DEC_EVAL_METHOD__ 2
#define __ELF__ 1
#define __FINITE_MATH_ONLY__ 0
#define __FLOAT_WORD_ORDER__ __ORDER_BIG_ENDIAN__
#define __FLT32X_DECIMAL_DIG__ 17
#define __FLT32X_DENORM_MIN__ 4.94065645841246544177e-324F32x
#define __FLT32X_DIG__ 15
#define __FLT32X_EPSILON__ 2.22044604925031308085e-16F32x
#define __FLT32X_HAS_DENORM__ 1
#define __FLT32X_HAS_INFINITY__ 1
#define __FLT32X_HAS_QUIET_NAN__ 1
#define __FLT32X_IS_IEC_60559__ 1
#define __FLT32X_MANT_DIG__ 53
#define __FLT32X_MAX_10_EXP__ 308
#define __FLT32X_MAX_EXP__ 1024
#define __FLT32X_MAX__ 1.79769313486231570815e+308F32x
#define __FLT32X_MIN_10_EXP__ (-307)
#define __FLT32X_MIN_EXP__ (-1021)
#define __FLT32X_MIN__ 2.22507385850720138309e-308F32x
#define __FLT32X_NORM_MAX__ 1.79769313486231570815e+308F32x
#define __FLT32_DECIMAL_DIG__ 9
#define __FLT32_DENORM_MIN__ 1.40129846432481707092e-45F32
#define __FLT32_DIG__ 6
#define __FLT32_EPSILON__ 1.19209289550781250000e-7F32
#define __FLT32_HAS_DENORM__ 1
#define __FLT32_HAS_INFINITY__ 1
#define __FLT32_HAS_QUIET_NAN__ 1
#define __FLT32_IS_IEC_60559__ 1
#define __FLT32_MANT_DIG__ 24
#define __FLT32_MAX_10_EXP__ 38
#define __FLT32_MAX_EXP__ 128
#define __FLT32_MAX__ 3.40282346638528859812e+38F32
#define __FLT32_MIN_10_EXP__ (-37)
#define __FLT32_MIN_EXP__ (-125)
#define __FLT32_MIN__ 1.17549435082228750797e-38F32
#define __FLT32_NORM_MAX__ 3.40282346638528859812e+38F32
#define __FLT64_DECIMAL_DIG__ 17
#define __FLT64_DENORM_MIN__ 4.94065645841246544177e-324F64
#define __FLT64_DIG__ 15
#define __FLT64_EPSILON__ 2.22044604925031308085e-16F64
#define __FLT64_HAS_DENORM__ 1
#define __FLT64_HAS_INFINITY__ 1
#define __FLT64_HAS_QUIET_NAN__ 1
#define __FLT64_IS_IEC_60559__ 1
#define __FLT64_MANT_DIG__ 53
#define __FLT64_MAX_10_EXP__ 308
#define __FLT64_MAX_EXP__ 1024
#define __FLT64_MAX__ 1.79769313486231570815e+308F64
#define __FLT64_MIN_10_EXP__ (-307)
#define __FLT64_MIN_EXP__ (-1021)
#define __FLT64_MIN__ 2.22507385850720138309e-308F64
#define __FLT64_NORM_MAX__ 1.79769313486231570815e+308F64
#define __FLT_DECIMAL_DIG__ 9
#define __FLT_DENORM_MIN__ 1.40129846432481707092e-45F
#define __FLT_DIG__ 6
#define __FLT_EPSILON__ 1.19209289550781250000e-7F
#define __FLT_EVAL_METHOD_TS_18661_3__ 0
#define __FLT_EVAL_METHOD__ 0
#define __FLT_HAS_DENORM__ 1
#define __FLT_HAS_INFINITY__ 1
#define __FLT_HAS_QUIET_NAN__ 1
#define __FLT_IS_IEC_60559__ 1
#define __FLT_MANT_DIG__ 24
#define __FLT_MAX_10_EXP__ 38
#define __FLT_MAX_EXP__ 128
#define __FLT_MAX__ 3.40282346638528859812e+38F
#define __FLT_MIN_10_EXP__ (-37)
#define __FLT_MIN_EXP__ (-125)
#define __FLT_MIN__ 1.17549435082228750797e-38F
#define __FLT_NORM_MAX__ 3.40282346638528859812e+38F
#define __FLT_RADIX__ 2
#define __GCC_ATOMIC_BOOL_LOCK_FREE 1
#define __GCC_ATOMIC_CHAR16_T_LOCK_FREE 1
#define __GCC_ATOMIC_CHAR32_T_LOCK_FREE 1
#define __GCC_ATOMIC_CHAR_LOCK_FREE 1
#define __GCC_ATOMIC_INT_LOCK_FREE 1
#define __GCC_ATOMIC_LLONG_LOCK_FREE 1
#define __GCC_ATOMIC_LONG_LOCK_FREE 1
#define __GCC_ATOMIC_POINTER_LOCK_FREE 1
#define __GCC_ATOMIC_SHORT_LOCK_FREE 1
#define __GCC_ATOMIC_TEST_AND_SET_TRUEVAL 128
#define __GCC_ATOMIC_WCHAR_T_LOCK_FREE 1
#define __GCC_IEC_559 0
#define __GCC_IEC_559_COMPLEX 0
#define __GNUC_EXECUTION_CHARSET_NAME "UTF-8"
#define __GNUC_MINOR__ 4
#define __GNUC_PATCHLEVEL__ 0
#define __GNUC_STDC_INLINE__ 1
#define __GNUC_WIDE_EXECUTION_CHARSET_NAME "UTF-32BE"
#define __GNUC__ 13
#define __GXX_ABI_VERSION 1018
#define __HAVE_SPECULATION_SAFE_VALUE 1
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
#define __LDBL_DECIMAL_DIG__ 21
#define __LDBL_DENORM_MIN__ 1.82259976594123730126e-4951L
#define __LDBL_DIG__ 18
#define __LDBL_EPSILON__ 1.08420217248550443401e-19L
#define __LDBL_HAS_DENORM__ 1
#define __LDBL_HAS_INFINITY__ 1
#define __LDBL_HAS_QUIET_NAN__ 1
#define __LDBL_IS_IEC_60559__ 0
#define __LDBL_MANT_DIG__ 64
#define __LDBL_MAX_10_EXP__ 4932
#define __LDBL_MAX_EXP__ 16384
#define __LDBL_MAX__ 1.18973149535723176502e+4932L
#define __LDBL_MIN_10_EXP__ (-4931)
#define __LDBL_MIN_EXP__ (-16382)
#define __LDBL_MIN__ 1.68105157155604675313e-4932L
#define __LDBL_NORM_MAX__ 1.18973149535723176502e+4932L
#define __LONG_LONG_MAX__ 0x7fffffffffffffffLL
#define __LONG_LONG_WIDTH__ 64
#define __LONG_MAX__ 0x7fffffffL
#define __LONG_WIDTH__ 32
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
#define __SIZEOF_DOUBLE__ 8
#define __SIZEOF_FLOAT__ 4
#define __SIZEOF_INT__ 4
#define __SIZEOF_LONG_DOUBLE__ 12
#define __SIZEOF_LONG_LONG__ 8
#define __SIZEOF_LONG__ 4
#define __SIZEOF_POINTER__ 4
#define __SIZEOF_PTRDIFF_T__ 4
#define __SIZEOF_SHORT__ 2
#define __SIZEOF_SIZE_T__ 4
#define __SIZEOF_WCHAR_T__ 4
#define __SIZEOF_WINT_T__ 4
#define __SIZE_MAX__ 0xffffffffUL
#define __SIZE_TYPE__ long unsigned int
#define __SIZE_WIDTH__ 32
#define __STDC_HOSTED__ 1
#define __STDC_UTF_16__ 1
#define __STDC_UTF_32__ 1
#define __STDC_VERSION__ 201710L
#define __STDC__ 1
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
#define __USER_LABEL_PREFIX__ 
#define __VERSION__ "13.4.0"
#define __WCHAR_MAX__ 0x7fffffffL
#define __WCHAR_MIN__ (-__WCHAR_MAX__ - 1)
#define __WCHAR_TYPE__ long int
#define __WCHAR_WIDTH__ 32
#define __WINT_MAX__ 0xffffffffU
#define __WINT_MIN__ 0U
#define __WINT_TYPE__ unsigned int
#define __WINT_WIDTH__ 32
#define __embedded__ 1
#define __human68k 1
#define __human68k__ 1
#define __m68k__ 1
#define __mc68000 1
#define __mc68000__ 1
#define mc68000 1
```

----
## libgcc.aに含まれるオブジェクトとシンボル
elf2x68k(Release 20250907、GCC 13.4.0)にて
`m68k-xelf-nm libgcc.a`
で出力したものです。  

```

_mulsi3.o:
00000000 T __mulsi3
00000000 T __mulsi3_internal

_udivsi3.o:
00000028 t L3
0000002a t L4
00000056 t L5
00000058 t L6
00000000 T __udivsi3
00000000 T __udivsi3_internal

_divsi3.o:
0000000e t L1
00000018 t L2
0000002a t L3
00000000 T __divsi3
00000000 T __divsi3_internal
         U __udivsi3_internal

_umodsi3.o:
         U __mulsi3_internal
         U __udivsi3_internal
00000000 T __umodsi3

_modsi3.o:
         U __divsi3_internal
00000000 T __modsi3
         U __mulsi3_internal

_double.o:
         U $_exception_handler
00000001 a ADD
00000005 a COMPARE
00000035 a DBL_MANT_DIG
00000401 a DBL_MAX_EXP
fffffc03 a DBL_MIN_EXP
00000003 a DIVIDE
00000008 a DIVIDE_BY_ZERO
00000002 a DOUBLE_FLOAT
000003fe a D_BIAS
000007ff a D_MAX_EXP
00000000 a EQUAL
00000006 a EXTENDSFDF
00000001 a GREATER
00000001 a INEXACT_RESULT
00000010 a INVALID_OPERATION
ffffffff a LESS
000000bc t Ladddf$1
000000d4 t Ladddf$2
000001c0 t Ladddf$3
000001c4 t Ladddf$4
00000228 t Ladddf$5
00000324 t Ladddf$a
000002f8 t Ladddf$a$den
000002bc t Ladddf$a$small
00000306 t Ladddf$b
000002fe t Ladddf$b$den
000002da t Ladddf$b$small
00000382 t Ladddf$nf
00000366 t Ladddf$ret
00000362 t Ladddf$ret$1
0000037a t Ladddf$ret$den
00000938 t Lcmpd$inop
000008b2 t Lcmpdf$0
000008c8 t Lcmpdf$1
00000914 t Lcmpdf$a$0
00000900 t Lcmpdf$a$gt$b
00000924 t Lcmpdf$a$nf
0000091c t Lcmpdf$b$0
0000090a t Lcmpdf$b$gt$a
0000092e t Lcmpdf$b$nf
00000000 t Ld$den
00000044 t Ld$div$0
0000000e t Ld$infty
00000034 t Ld$inop
0000000e t Ld$overflow
00000024 t Ld$underflow
00000614 t Ldivdf$1
00000626 t Ldivdf$2
000006ee t Ldivdf$a$0
00000762 t Ldivdf$a$den
0000074a t Ldivdf$a$nf
00000726 t Ldivdf$b$0
00000778 t Ldivdf$b$den
0000073e t Ldivdf$b$nf
000006e8 t Ldivdf$inop
00000466 t Lmuldf$1
00000478 t Lmuldf$2
0000054e t Lmuldf$a$0
00000578 t Lmuldf$a$den
00000534 t Lmuldf$a$nf
00000542 t Lmuldf$b$0
0000058e t Lmuldf$b$den
00000526 t Lmuldf$b$nf
00000520 t Lmuldf$inop
000007ea t Lround$0
0000078e t Lround$exit
000009ca t Lround$to$minus
00000966 t Lround$to$nearest
000009ca t Lround$to$plus
000009ca t Lround$to$zero
00000246 t Lsubdf$0
000002ac t Lsubdf$1
00000002 a MULTIPLY
00000004 a NEGATE
00000000 a NOOP
00000004 a OVERFLOW
ffffffff a QUIET_NaN
00000003 a ROUND_TO_MINUS
00000000 a ROUND_TO_NEAREST
00000002 a ROUND_TO_PLUS
00000001 a ROUND_TO_ZERO
00000007 a TRUNCDFSF
00000002 a UNDERFLOW
ffffffff a UNKNOWN
00000060 T __adddf3
00000946 T __cmpdf2
00000876 T __cmpdf2_internal
000005a4 T __divdf3
000003f6 T __muldf3
00000818 T __negdf2
0000005a T __subdf3
         U _fpCCR

_float.o:
         U $_exception_handler
00000001 a ADD
00000005 a COMPARE
00000003 a DIVIDE
00000008 a DIVIDE_BY_ZERO
00000000 a EQUAL
00000006 a EXTENDSFDF
00000018 a FLT_MANT_DIG
00000081 a FLT_MAX_EXP
ffffff83 a FLT_MIN_EXP
0000007e a F_BIAS
000000ff a F_MAX_EXP
00000001 a GREATER
00000001 a INEXACT_RESULT
7f800000 a INFINITY
00000010 a INVALID_OPERATION
ffffffff a LESS
00000090 t Laddsf$1
000000a6 t Laddsf$2
00000124 t Laddsf$3
00000170 t Laddsf$4
00000236 t Laddsf$a
00000208 t Laddsf$a$den
000001dc t Laddsf$a$small
0000021a t Laddsf$b
00000210 t Laddsf$b$den
000001f2 t Laddsf$b$small
00000288 t Laddsf$nf
0000026e t Laddsf$ret
00000282 t Laddsf$ret$den
000006ae t Lcmpf$inop
00000648 t Lcmpsf$1
0000065e t Lcmpsf$2
0000069e t Lcmpsf$a$0
0000068a t Lcmpsf$a$gt$b
000006a6 t Lcmpsf$b$0
00000694 t Lcmpsf$b$gt$a
00000468 t Ldivsf$1
00000476 t Ldivsf$2
000004e0 t Ldivsf$a$0
0000052a t Ldivsf$a$den
0000050a t Ldivsf$b$0
0000053e t Ldivsf$b$den
0000051a t Ldivsf$inf
000004ce t Ldivsf$inop
000004d4 t Ldivsf$overflow
000004da t Ldivsf$underflow
00000000 t Lf$den
00000036 t Lf$div$0
0000000c t Lf$infty
0000002a t Lf$inop
0000000c t Lf$overflow
0000001e t Lf$underflow
0000033c t Lmulsf$1
0000034a t Lmulsf$2
000003ba t Lmulsf$a$0
000003e0 t Lmulsf$a$den
000003b2 t Lmulsf$b$0
000003f4 t Lmulsf$b$den
000003a6 t Lmulsf$inf
0000039a t Lmulsf$inop
000003a0 t Lmulsf$overflow
000005a0 t Lround$0
00000552 t Lround$exit
00000728 t Lround$to$minus
000006d4 t Lround$to$nearest
00000728 t Lround$to$plus
00000728 t Lround$to$zero
0000018c t Lsubsf$0
000001ce t Lsubsf$1
00000002 a MULTIPLY
00000004 a NEGATE
00000000 a NOOP
00000004 a OVERFLOW
ffffffff a QUIET_NaN
00000003 a ROUND_TO_MINUS
00000000 a ROUND_TO_NEAREST
00000002 a ROUND_TO_PLUS
00000001 a ROUND_TO_ZERO
7f800001 a SIGNL_NaN
00000001 a SINGLE_FLOAT
00000007 a TRUNCDFSF
00000002 a UNDERFLOW
ffffffff a UNKNOWN
0000004e T __addsf3
000006bc T __cmpsf2
00000620 T __cmpsf2_internal
00000408 T __divsf3
000002dc T __mulsf3
000005ce T __negsf2
00000048 T __subsf3
         U _fpCCR

_floatex.o:
0000000e T $_exception_handler
00000001 a ADD
00000005 a COMPARE
00000003 a DIVIDE
00000008 a DIVIDE_BY_ZERO
00000002 a DOUBLE_FLOAT
00000000 a EBITS
00000006 a EXTENDSFDF
00000008 a FORMT
0000000f a FPTRAP
00000001 a INEXACT_RESULT
00000010 a INVALID_OPERATION
0000000a a LASTO
00000003 a LONG_FLOAT
00000002 a MULTIPLY
00000004 a NEGATE
00000000 a NIL
00000000 a NOOP
0000000c a OPER1
00000014 a OPER2
00000004 a OVERFLOW
00000006 a ROUND
00000003 a ROUND_TO_MINUS
00000000 a ROUND_TO_NEAREST
00000002 a ROUND_TO_PLUS
00000001 a ROUND_TO_ZERO
00000001 a SINGLE_FLOAT
00000004 a STICK
00000002 a TRAPE
00000007 a TRUNCDFSF
00000002 a UNDERFLOW
ffffffff a UNKNOWN
00000000 T __clear_sticky_bit
00000000 d __exception_bits
00000008 d __format
0000000a d __last_operation
0000000c d __operand1
00000014 d __operand2
00000006 d __rounding_mode
00000004 d __sticky_bits
00000002 d __trap_enable_bits
00000000 D _fpCCR

_eqdf2.o:
         U __cmpdf2_internal
00000000 T __eqdf2

_nedf2.o:
         U __cmpdf2_internal
00000000 T __nedf2

_gtdf2.o:
         U __cmpdf2_internal
00000000 T __gtdf2

_gedf2.o:
         U __cmpdf2_internal
00000000 T __gedf2

_ltdf2.o:
         U __cmpdf2_internal
00000000 T __ltdf2

_ledf2.o:
         U __cmpdf2_internal
00000000 T __ledf2

_eqsf2.o:
         U __cmpsf2_internal
00000000 T __eqsf2

_nesf2.o:
         U __cmpsf2_internal
00000000 T __nesf2

_gtsf2.o:
         U __cmpsf2_internal
00000000 T __gtsf2

_gesf2.o:
         U __cmpsf2_internal
00000000 T __gesf2

_ltsf2.o:
         U __cmpsf2_internal
00000000 T __ltsf2

_lesf2.o:
         U __cmpsf2_internal
00000000 T __lesf2

_muldi3.o:
00000000 T __muldi3
         U __mulsi3

_negdi2.o:
00000000 T __negdi2

_lshrdi3.o:
00000000 T __lshrdi3

_ashldi3.o:
00000000 T __ashldi3

_ashrdi3.o:
00000000 T __ashrdi3

_cmpdi2.o:
00000000 T __cmpdi2

_ucmpdi2.o:
00000000 T __ucmpdi2

_clear_cache.o:
00000000 T __clear_cache

_trampoline.o:
00000000 T ___trampoline
00000000 T __transfer_from_trampoline

__main.o:

_absvsi2.o:
00000000 T __absvsi2

_absvdi2.o:
00000000 T __absvdi2

_addvsi3.o:
00000000 T __addvsi3

_addvdi3.o:
00000000 T __addvdi3

_subvsi3.o:
00000000 T __subvsi3

_subvdi3.o:
00000000 T __subvdi3

_mulvsi3.o:
         U __mulsi3
00000000 T __mulvsi3

_mulvdi3.o:
         U __muldi3
00000000 T __mulvdi3

_negvsi2.o:
00000000 T __negvsi2

_negvdi2.o:
00000000 T __negvdi2

_ctors.o:

_ffssi2.o:
         U __clz_tab
00000000 T __ffssi2

_ffsdi2.o:
         U __clz_tab
00000000 T __ffsdi2

_clz.o:
00000000 R __clz_tab

_clzsi2.o:
         U __clz_tab
00000000 T __clzsi2

_clzdi2.o:
         U __clz_tab
00000000 T __clzdi2

_ctzsi2.o:
         U __clz_tab
00000000 T __ctzsi2

_ctzdi2.o:
         U __clz_tab
00000000 T __ctzdi2

_popcount_tab.o:
00000000 R __popcount_tab

_popcountsi2.o:
00000000 T __popcountsi2

_popcountdi2.o:
00000000 T __popcountdi2

_paritysi2.o:
00000000 T __paritysi2

_paritydi2.o:
00000000 T __paritydi2

_powisf2.o:
         U __divsf3
         U __mulsf3
00000000 T __powisf2

_powidf2.o:
         U __divdf3
         U __muldf3
00000000 T __powidf2

_powixf2.o:
         U __divxf3
         U __mulxf3
00000000 T __powixf2

_powitf2.o:

_mulhc3.o:

_mulsc3.o:
         U __addsf3
         U __floatsisf
         U __lesf2
00000000 T __mulsc3
         U __mulsf3
         U __subsf3
         U __unordsf2

_muldc3.o:
         U __adddf3
         U __floatsidf
         U __ledf2
00000000 T __muldc3
         U __muldf3
         U __subdf3
         U __unorddf2

_mulxc3.o:
         U __addxf3
         U __floatsixf
         U __lexf2
00000000 T __mulxc3
         U __mulxf3
         U __subxf3
         U __unordxf2

_multc3.o:

_divhc3.o:

_divsc3.o:
         U __adddf3
         U __addsf3
         U __divdf3
00000000 T __divsc3
         U __eqsf2
         U __extendsfdf2
         U __floatsisf
         U __gtsf2
         U __lesf2
         U __muldf3
         U __mulsf3
         U __subdf3
         U __subsf3
         U __truncdfsf2
         U __unordsf2

_divdc3.o:
         U __adddf3
00000000 T __divdc3
         U __divdf3
         U __eqdf2
         U __floatsidf
         U __gedf2
         U __gtdf2
         U __ledf2
         U __ltdf2
         U __muldf3
         U __subdf3
         U __unorddf2

_divxc3.o:
         U __addxf3
00000000 T __divxc3
         U __divxf3
         U __eqxf2
         U __floatsixf
         U __gexf2
         U __gtxf2
         U __lexf2
         U __ltxf2
         U __mulxf3
         U __subxf3
         U __unordxf2

_divtc3.o:

_bswapsi2.o:
00000000 T __bswapsi2

_bswapdi2.o:
00000000 T __bswapdi2

_clrsbsi2.o:
00000000 T __clrsbsi2
         U __clz_tab

_clrsbdi2.o:
00000000 T __clrsbdi2
         U __clz_tab

_fixunssfsi.o:
         U __fixsfsi
00000000 T __fixunssfsi
         U __gesf2
         U __subsf3

_fixunsdfsi.o:
         U __fixdfsi
00000000 T __fixunsdfsi
         U __gedf2
         U __subdf3

_fixunsxfsi.o:
00000000 T __fixunsxfsi
         U __fixxfsi
         U __gexf2
         U __subxf3

_fixsfdi.o:
00000000 T __fixsfdi
         U __fixunssfdi
         U __ltsf2

_fixdfdi.o:
00000000 T __fixdfdi
         U __fixunsdfdi
         U __ltdf2

_fixxfdi.o:
         U __fixunsxfdi
00000000 T __fixxfdi
         U __ltxf2

_fixtfdi.o:

_fixunssfdi.o:
         U __extendsfdf2
         U __fixunsdfsi
00000000 T __fixunssfdi
         U __floatunsidf
         U __muldf3
         U __subdf3

_fixunsdfdi.o:
00000000 T __fixunsdfdi
         U __fixunsdfsi
         U __floatunsidf
         U __muldf3
         U __subdf3

_fixunsxfdi.o:
00000000 T __fixunsxfdi
         U __fixunsxfsi
         U __floatundixf
         U __ltxf2
         U __mulxf3
         U __subxf3

_fixunstfdi.o:

_floatdisf.o:
         U __adddf3
00000000 T __floatdisf
         U __floatsidf
         U __floatunsidf
         U __muldf3
         U __truncdfsf2

_floatdidf.o:
         U __adddf3
00000000 T __floatdidf
         U __floatsidf
         U __floatunsidf
         U __muldf3

_floatdixf.o:
         U __addxf3
00000000 T __floatdixf
         U __floatsixf
         U __floatunsixf
         U __mulxf3

_floatditf.o:

_floatundisf.o:
         U __adddf3
00000000 T __floatundisf
         U __floatunsidf
         U __muldf3
         U __truncdfsf2

_floatundidf.o:
         U __adddf3
00000000 T __floatundidf
         U __floatunsidf
         U __muldf3

_floatundixf.o:
         U __addxf3
00000000 T __floatundixf
         U __floatunsixf
         U __mulxf3

_floatunditf.o:

_eprintf.o:

__gcc_bcmp.o:
00000000 T __gcc_bcmp

_divdi3.o:
         U __clz_tab
00000000 T __divdi3
         U __divsi3
         U __mulsi3
         U __udivsi3
         U __umodsi3

_moddi3.o:
         U __clz_tab
         U __divsi3
00000000 T __moddi3
         U __mulsi3
         U __udivsi3
         U __umodsi3

_divmoddi4.o:
         U __clz_tab
00000000 T __divmoddi4
         U __divsi3
         U __mulsi3
         U __udivsi3
         U __umodsi3

_udivdi3.o:
         U __clz_tab
         U __divsi3
         U __mulsi3
00000000 T __udivdi3
         U __udivsi3
         U __umodsi3

_umoddi3.o:
         U __clz_tab
         U __divsi3
         U __mulsi3
         U __udivsi3
00000000 T __umoddi3
         U __umodsi3

_udivmoddi4.o:
         U __clz_tab
         U __divsi3
         U __mulsi3
00000000 T __udivmoddi4
         U __udivsi3
         U __umodsi3

_udiv_w_sdiv.o:
00000000 T __udiv_w_sdiv

fpgnulib.o:
00000278 T __extendsfdf2
00000400 T __fixdfsi
00000490 T __fixsfsi
000001bc T __floatsidf
00000000 t __floatsidf.part.0
0000025c T __floatsisf
0000013a T __floatunsidf
000001d0 T __floatunsisf
000002ec T __truncdfsf2
000000d6 T __unorddf2
0000008a T __unordsf2

xfgnulib.o:
         U __adddf3
000003c6 T __addxf3
         U __cmpdf2
0000052e T __cmpxf2
         U __divdf3
000004b6 T __divxf3
0000057a T __eqxf2
00000082 T __extenddfxf2
         U __extendsfdf2
000001e0 T __extendsfxf2
         U __fixdfsi
000003a4 T __fixxfsi
         U __floatsidf
00000374 T __floatsixf
         U __floatunsidf
0000038c T __floatunsixf
000006f6 T __gexf2
000006aa T __gtxf2
0000065e T __lexf2
00000612 T __ltxf2
         U __muldf3
00000466 T __mulxf3
00000506 T __negxf2
000005c6 T __nexf2
         U __subdf3
00000416 T __subxf3
         U __truncdfsf2
00000118 T __truncxfdf2
0000027a T __truncxfsf2
00000000 T __unordxf2

enable-execute-stack.o:
00000000 T __enable_execute_stack

unwind-dw2.o:
00002b32 T _Unwind_Backtrace
000027cc t _Unwind_DebugHook
00002b18 T _Unwind_DeleteException
000026d4 T _Unwind_FindEnclosingFunction
         U _Unwind_Find_FDE
0000294a T _Unwind_ForcedUnwind
0000248c t _Unwind_ForcedUnwind_Phase2
0000263a T _Unwind_GetCFA
000026f8 T _Unwind_GetDataRelBase
000025fa T _Unwind_GetGR
00002690 T _Unwind_GetIP
0000269a T _Unwind_GetIPInfo
000026c0 T _Unwind_GetLanguageSpecificData
000026ca T _Unwind_GetRegionStart
00002702 T _Unwind_GetTextRelBase
000027ce T _Unwind_RaiseException
0000233a t _Unwind_RaiseException_Phase2
000029e4 T _Unwind_Resume
00002a7c T _Unwind_Resume_or_Rethrow
00002644 T _Unwind_SetGR
000026b4 T _Unwind_SetIP
         U __divsi3
0000270c T __frame_state_for
         U __mulsi3
         U __umodsi3
00000000 b dwarf_reg_size_table
0000164c t execute_cfa_program_generic
00000f64 t execute_cfa_program_specialized
00000312 t execute_stack_op
         U memcpy
         U memset
00000134 t read_encoded_value
         U strlen
00001db0 t uw_frame_state_for
000021ca t uw_init_context_1
00000000 t uw_install_context_1
00000c6e t uw_update_context_1

unwind-dw2-fde.o:
000016f8 T _Unwind_Find_FDE
000016dc T __deregister_frame
000016d8 T __deregister_frame_info
00001646 T __deregister_frame_info_bases
00001564 T __register_frame
00001528 T __register_frame_info
000014e8 T __register_frame_info_bases
000015de T __register_frame_info_table
000015aa T __register_frame_info_table_bases
0000160e T __register_frame_table
00000aaa t add_fdes.isra.0
00000644 t classify_object_over_fdes.constprop.0
0000095e t fde_mixed_encoding_compare
0000058e t fde_mixed_encoding_extract
00000290 t fde_radixsort
00000884 t fde_single_encoding_compare
0000080c t fde_single_encoding_extract
0000020e t fde_unencoded_compare
00000260 t fde_unencoded_extract
00000000 t frame_downheap
         U free
000004a8 t get_cie_encoding
00000cf8 t linear_search_fdes
         U malloc
         U memcpy
         U memset
0000007a t read_encoded_value_with_base
00000f16 t search_object
00000000 b seen_objects
         U strlen
00000000 r terminator.0
00000004 b unseen_objects

unwind-sjlj.o:

unwind-c.o:
         U _Unwind_GetDataRelBase
         U _Unwind_GetIPInfo
         U _Unwind_GetLanguageSpecificData
         U _Unwind_GetRegionStart
         U _Unwind_GetTextRelBase
         U _Unwind_SetGR
         U _Unwind_SetIP
000001ea T __gcc_personality_v0
00000000 t base_of_encoded_value
00000056 t read_encoded_value_with_base

emutls.o:
00000000 T __emutls_get_address
00000098 T __emutls_register_common
         U malloc
         U memcpy
         U memset
```


----
goto [index](../README.md) / [プログラミング](./README.md)
