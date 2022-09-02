/* Copyright 2015, Kenneth MacKay. Licensed under the BSD 2-clause license. */

#ifndef _BUuECC_VLI_H_
#define _BUuECC_VLI_H_

#include "BUuECC.h"
#include "BUTypes.h"

/* Functions for raw large-integer manipulation. These are only available
   if BUuECC.c is compiled with BUuECC_ENABLE_VLI_API defined to 1. */
#ifndef BUuECC_ENABLE_VLI_API
    #define BUuECC_ENABLE_VLI_API 0
#endif

#ifdef __cplusplus
extern "C"
{
#endif

#if BUuECC_ENABLE_VLI_API

void BUuECC_vli_clear(BUuECC_word_t *vli, wordcount_t num_words);

/* Constant-time comparison to zero - secure way to compare long integers */
/* Returns 1 if vli == 0, 0 otherwise. */
BUuECC_word_t BUuECC_vli_isZero(const BUuECC_word_t *vli, wordcount_t num_words);

/* Returns nonzero if bit 'bit' of vli is set. */
BUuECC_word_t BUuECC_vli_testBit(const BUuECC_word_t *vli, bitcount_t bit);

/* Counts the number of bits required to represent vli. */
bitcount_t BUuECC_vli_numBits(const BUuECC_word_t *vli, const wordcount_t max_words);

/* Sets dest = src. */
void BUuECC_vli_set(BUuECC_word_t *dest, const BUuECC_word_t *src, wordcount_t num_words);

/* Constant-time comparison function - secure way to compare long integers */
/* Returns one if left == right, zero otherwise */
BUuECC_word_t BUuECC_vli_equal(const BUuECC_word_t *left,
                           const BUuECC_word_t *right,
                           wordcount_t num_words);

/* Constant-time comparison function - secure way to compare long integers */
/* Returns sign of left - right, in constant time. */
cmpresult_t BUuECC_vli_cmp(const BUuECC_word_t *left, const BUuECC_word_t *right, wordcount_t num_words);

/* Computes vli = vli >> 1. */
void BUuECC_vli_rshift1(BUuECC_word_t *vli, wordcount_t num_words);

/* Computes result = left + right, returning carry. Can modify in place. */
BUuECC_word_t BUuECC_vli_add(BUuECC_word_t *result,
                         const BUuECC_word_t *left,
                         const BUuECC_word_t *right,
                         wordcount_t num_words);

/* Computes result = left - right, returning borrow. Can modify in place. */
BUuECC_word_t BUuECC_vli_sub(BUuECC_word_t *result,
                         const BUuECC_word_t *left,
                         const BUuECC_word_t *right,
                         wordcount_t num_words);

/* Computes result = left * right. Result must be 2 * num_words long. */
void BUuECC_vli_mult(BUuECC_word_t *result,
                   const BUuECC_word_t *left,
                   const BUuECC_word_t *right,
                   wordcount_t num_words);

/* Computes result = left^2. Result must be 2 * num_words long. */
void BUuECC_vli_square(BUuECC_word_t *result, const BUuECC_word_t *left, wordcount_t num_words);

/* Computes result = (left + right) % mod.
   Assumes that left < mod and right < mod, and that result does not overlap mod. */
void BUuECC_vli_modAdd(BUuECC_word_t *result,
                     const BUuECC_word_t *left,
                     const BUuECC_word_t *right,
                     const BUuECC_word_t *mod,
                     wordcount_t num_words);

/* Computes result = (left - right) % mod.
   Assumes that left < mod and right < mod, and that result does not overlap mod. */
void BUuECC_vli_modSub(BUuECC_word_t *result,
                     const BUuECC_word_t *left,
                     const BUuECC_word_t *right,
                     const BUuECC_word_t *mod,
                     wordcount_t num_words);

/* Computes result = product % mod, where product is 2N words long.
   Currently only designed to work for mod == curve->p or curve_n. */
void BUuECC_vli_mmod(BUuECC_word_t *result,
                   BUuECC_word_t *product,
                   const BUuECC_word_t *mod,
                   wordcount_t num_words);

/* Calculates result = product (mod curve->p), where product is up to
   2 * curve->num_words long. */
void BUuECC_vli_mmod_fast(BUuECC_word_t *result, BUuECC_word_t *product, BUuECC_Curve curve);

/* Computes result = (left * right) % mod.
   Currently only designed to work for mod == curve->p or curve_n. */
void BUuECC_vli_modMult(BUuECC_word_t *result,
                      const BUuECC_word_t *left,
                      const BUuECC_word_t *right,
                      const BUuECC_word_t *mod,
                      wordcount_t num_words);

/* Computes result = (left * right) % curve->p. */
void BUuECC_vli_modMult_fast(BUuECC_word_t *result,
                           const BUuECC_word_t *left,
                           const BUuECC_word_t *right,
                           BUuECC_Curve curve);

/* Computes result = left^2 % mod.
   Currently only designed to work for mod == curve->p or curve_n. */
void BUuECC_vli_modSquare(BUuECC_word_t *result,
                        const BUuECC_word_t *left,
                        const BUuECC_word_t *mod,
                        wordcount_t num_words);

/* Computes result = left^2 % curve->p. */
void BUuECC_vli_modSquare_fast(BUuECC_word_t *result, const BUuECC_word_t *left, BUuECC_Curve curve);

/* Computes result = (1 / input) % mod.*/
void BUuECC_vli_modInv(BUuECC_word_t *result,
                     const BUuECC_word_t *input,
                     const BUuECC_word_t *mod,
                     wordcount_t num_words);

#if BUuECC_SUPPORT_COMPRESSED_POINT
/* Calculates a = sqrt(a) (mod curve->p) */
void BUuECC_vli_mod_sqrt(BUuECC_word_t *a, BUuECC_Curve curve);
#endif

/* Converts an integer in BUuECC native format to big-endian bytes. */
void BUuECC_vli_nativeToBytes(uint8_t *bytes, int num_bytes, const BUuECC_word_t *native);
/* Converts big-endian bytes to an integer in BUuECC native format. */
void BUuECC_vli_bytesToNative(BUuECC_word_t *native, const uint8_t *bytes, int num_bytes);

unsigned BUuECC_curve_num_words(BUuECC_Curve curve);
unsigned BUuECC_curve_num_bytes(BUuECC_Curve curve);
unsigned BUuECC_curve_num_bits(BUuECC_Curve curve);
unsigned BUuECC_curve_num_n_words(BUuECC_Curve curve);
unsigned BUuECC_curve_num_n_bytes(BUuECC_Curve curve);
unsigned BUuECC_curve_num_n_bits(BUuECC_Curve curve);

const BUuECC_word_t *BUuECC_curve_p(BUuECC_Curve curve);
const BUuECC_word_t *BUuECC_curve_n(BUuECC_Curve curve);
const BUuECC_word_t *BUuECC_curve_G(BUuECC_Curve curve);
const BUuECC_word_t *BUuECC_curve_b(BUuECC_Curve curve);

int BUuECC_valid_point(const BUuECC_word_t *point, BUuECC_Curve curve);

/* Multiplies a point by a scalar. Points are represented by the X coordinate followed by
   the Y coordinate in the same array, both coordinates are curve->num_words long. Note
   that scalar must be curve->num_n_words long (NOT curve->num_words). */
void BUuECC_point_mult(BUuECC_word_t *result,
                     const BUuECC_word_t *point,
                     const BUuECC_word_t *scalar,
                     BUuECC_Curve curve);

/* Generates a random integer in the range 0 < random < top.
   Both random and top have num_words words. */
int BUuECC_generate_random_int(BUuECC_word_t *random,
                             const BUuECC_word_t *top,
                             wordcount_t num_words);

#endif /* BUuECC_ENABLE_VLI_API */

#ifdef __cplusplus
} /* end of extern "C" */
#endif

#endif /* _BUuECC_VLI_H_ */
