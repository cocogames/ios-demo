/* Copyright 2015, Kenneth MacKay. Licensed under the BSD 2-clause license. */

#ifndef _BUuECC_TYPES_H_
#define _BUuECC_TYPES_H_

#ifndef BUuECC_PLATFORM
    #if __AVR__
        #define BUuECC_PLATFORM BUuECC_avr
    #elif defined(__thumb2__) || defined(_M_ARMT) /* I think MSVC only supports Thumb-2 targets */
        #define BUuECC_PLATFORM BUuECC_arm_thumb2
    #elif defined(__thumb__)
        #define BUuECC_PLATFORM BUuECC_arm_thumb
    #elif defined(__arm__) || defined(_M_ARM)
        #define BUuECC_PLATFORM BUuECC_arm
    #elif defined(__aarch64__)
        #define BUuECC_PLATFORM BUuECC_arm64
    #elif defined(__i386__) || defined(_M_IX86) || defined(_X86_) || defined(__I86__)
        #define BUuECC_PLATFORM BUuECC_x86
    #elif defined(__amd64__) || defined(_M_X64)
        #define BUuECC_PLATFORM BUuECC_x86_64
    #else
        #define BUuECC_PLATFORM BUuECC_arch_other
    #endif
#endif

#ifndef BUuECC_ARM_USE_UMAAL
    #if (BUuECC_PLATFORM == BUuECC_arm) && (__ARM_ARCH >= 6)
        #define BUuECC_ARM_USE_UMAAL 1
    #elif (BUuECC_PLATFORM == BUuECC_arm_thumb2) && (__ARM_ARCH >= 6) && !__ARM_ARCH_7M__
        #define BUuECC_ARM_USE_UMAAL 1
    #else
        #define BUuECC_ARM_USE_UMAAL 0
    #endif
#endif

#ifndef BUuECC_WORD_SIZE
    #if BUuECC_PLATFORM == BUuECC_avr
        #define BUuECC_WORD_SIZE 1
    #elif (BUuECC_PLATFORM == BUuECC_x86_64 || BUuECC_PLATFORM == BUuECC_arm64)
        #define BUuECC_WORD_SIZE 8
    #else
        #define BUuECC_WORD_SIZE 4
    #endif
#endif

#if (BUuECC_WORD_SIZE != 1) && (BUuECC_WORD_SIZE != 4) && (BUuECC_WORD_SIZE != 8)
    #error "Unsupported value for BUuECC_WORD_SIZE"
#endif

#if ((BUuECC_PLATFORM == BUuECC_avr) && (BUuECC_WORD_SIZE != 1))
    #pragma message ("BUuECC_WORD_SIZE must be 1 for AVR")
    #undef BUuECC_WORD_SIZE
    #define BUuECC_WORD_SIZE 1
#endif

#if ((BUuECC_PLATFORM == BUuECC_arm || BUuECC_PLATFORM == BUuECC_arm_thumb || \
        BUuECC_PLATFORM ==  BUuECC_arm_thumb2) && \
     (BUuECC_WORD_SIZE != 4))
    #pragma message ("BUuECC_WORD_SIZE must be 4 for ARM")
    #undef BUuECC_WORD_SIZE
    #define BUuECC_WORD_SIZE 4
#endif

#if defined(__SIZEOF_INT128__) || ((__clang_major__ * 100 + __clang_minor__) >= 302)
    #define SUPPORTS_INT128 1
#else
    #define SUPPORTS_INT128 0
#endif

typedef int8_t wordcount_t;
typedef int16_t bitcount_t;
typedef int8_t cmpresult_t;

#if (BUuECC_WORD_SIZE == 1)

typedef uint8_t BUuECC_word_t;
typedef uint16_t BUuECC_dword_t;

#define HIGH_BIT_SET 0x80
#define BUuECC_WORD_BITS 8
#define BUuECC_WORD_BITS_SHIFT 3
#define BUuECC_WORD_BITS_MASK 0x07

#elif (BUuECC_WORD_SIZE == 4)

typedef uint32_t BUuECC_word_t;
typedef uint64_t BUuECC_dword_t;

#define HIGH_BIT_SET 0x80000000
#define BUuECC_WORD_BITS 32
#define BUuECC_WORD_BITS_SHIFT 5
#define BUuECC_WORD_BITS_MASK 0x01F

#elif (BUuECC_WORD_SIZE == 8)

typedef uint64_t BUuECC_word_t;
#if SUPPORTS_INT128
typedef unsigned __int128 BUuECC_dword_t;
#endif

#define HIGH_BIT_SET 0x8000000000000000ull
#define BUuECC_WORD_BITS 64
#define BUuECC_WORD_BITS_SHIFT 6
#define BUuECC_WORD_BITS_MASK 0x03F

#endif /* BUuECC_WORD_SIZE */

#endif /* _BUuECC_TYPES_H_ */
