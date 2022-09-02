/* Copyright 2014, Kenneth MacKay. Licensed under the BSD 2-clause license. */

#ifndef _BUuECC_H_
#define _BUuECC_H_

#include <stdint.h>

/* Platform selection options.
If BUuECC_PLATFORM is not defined, the code will try to guess it based on compiler macros.
Possible values for BUuECC_PLATFORM are defined below: */
#define BUuECC_arch_other 0
#define BUuECC_x86        1
#define BUuECC_x86_64     2
#define BUuECC_arm        3
#define BUuECC_arm_thumb  4
#define BUuECC_arm_thumb2 5
#define BUuECC_arm64      6
#define BUuECC_avr        7

/* If desired, you can define BUuECC_WORD_SIZE as appropriate for your platform (1, 4, or 8 bytes).
If BUuECC_WORD_SIZE is not explicitly defined then it will be automatically set based on your
platform. */

/* Optimization level; trade speed for code size.
   Larger values produce code that is faster but larger.
   Currently supported values are 0 - 4; 0 is unusably slow for most applications.
   Optimization level 4 currently only has an effect ARM platforms where more than one
   curve is enabled. */
#ifndef BUuECC_OPTIMIZATION_LEVEL
    #define BUuECC_OPTIMIZATION_LEVEL 2
#endif

/* BUuECC_SQUARE_FUNC - If enabled (defined as nonzero), this will cause a specific function to be
used for (scalar) squaring instead of the generic multiplication function. This can make things
faster somewhat faster, but increases the code size. */
#ifndef BUuECC_SQUARE_FUNC
    #define BUuECC_SQUARE_FUNC 0
#endif

/* BUuECC_VLI_NATIVE_LITTLE_ENDIAN - If enabled (defined as nonzero), this will switch to native
little-endian format for *all* arrays passed in and out of the public API. This includes public 
and private keys, shared secrets, signatures and message hashes. 
Using this switch reduces the amount of call stack memory used by BUuECC, since less intermediate
translations are required. 
Note that this will *only* work on native little-endian processors and it will treat the uint8_t
arrays passed into the public API as word arrays, therefore requiring the provided byte arrays 
to be word aligned on architectures that do not support unaligned accesses.
IMPORTANT: Keys and signatures generated with BUuECC_VLI_NATIVE_LITTLE_ENDIAN=1 are incompatible
with keys and signatures generated with BUuECC_VLI_NATIVE_LITTLE_ENDIAN=0; all parties must use
the same endianness. */
#ifndef BUuECC_VLI_NATIVE_LITTLE_ENDIAN
    #define BUuECC_VLI_NATIVE_LITTLE_ENDIAN 0
#endif

/* Curve support selection. Set to 0 to remove that curve. */
#ifndef BUuECC_SUPPORTS_secp160r1
    #define BUuECC_SUPPORTS_secp160r1 1
#endif
#ifndef BUuECC_SUPPORTS_secp192r1
    #define BUuECC_SUPPORTS_secp192r1 1
#endif
#ifndef BUuECC_SUPPORTS_secp224r1
    #define BUuECC_SUPPORTS_secp224r1 1
#endif
#ifndef BUuECC_SUPPORTS_secp256r1
    #define BUuECC_SUPPORTS_secp256r1 1
#endif
#ifndef BUuECC_SUPPORTS_secp256k1
    #define BUuECC_SUPPORTS_secp256k1 1
#endif

/* Specifies whether compressed point format is supported.
   Set to 0 to disable point compression/decompression functions. */
#ifndef BUuECC_SUPPORT_COMPRESSED_POINT
    #define BUuECC_SUPPORT_COMPRESSED_POINT 1
#endif

struct BUuECC_Curve_t;
typedef const struct BUuECC_Curve_t * BUuECC_Curve;

#ifdef __cplusplus
extern "C"
{
#endif

#if BUuECC_SUPPORTS_secp160r1
BUuECC_Curve BUuECC_secp160r1(void);
#endif
#if BUuECC_SUPPORTS_secp192r1
BUuECC_Curve BUuECC_secp192r1(void);
#endif
#if BUuECC_SUPPORTS_secp224r1
BUuECC_Curve BUuECC_secp224r1(void);
#endif
#if BUuECC_SUPPORTS_secp256r1
BUuECC_Curve BUuECC_secp256r1(void);
#endif
#if BUuECC_SUPPORTS_secp256k1
BUuECC_Curve BUuECC_secp256k1(void);
#endif

/* BUuECC_RNG_Function type
The RNG function should fill 'size' random bytes into 'dest'. It should return 1 if
'dest' was filled with random data, or 0 if the random data could not be generated.
The filled-in values should be either truly random, or from a cryptographically-secure PRNG.

A correctly functioning RNG function must be set (using BUuECC_set_rng()) before calling
BUuECC_make_key() or BUuECC_sign().

Setting a correctly functioning RNG function improves the resistance to side-channel attacks
for BUuECC_shared_secret() and BUuECC_sign_deterministic().

A correct RNG function is set by default when building for Windows, Linux, or OS X.
If you are building on another POSIX-compliant system that supports /dev/random or /dev/urandom,
you can define BUuECC_POSIX to use the predefined RNG. For embedded platforms there is no predefined
RNG function; you must provide your own.
*/
typedef int (*BUuECC_RNG_Function)(uint8_t *dest, unsigned size);

/* BUuECC_set_rng() function.
Set the function that will be used to generate random bytes. The RNG function should
return 1 if the random data was generated, or 0 if the random data could not be generated.

On platforms where there is no predefined RNG function (eg embedded platforms), this must
be called before BUuECC_make_key() or BUuECC_sign() are used.

Inputs:
    rng_function - The function that will be used to generate random bytes.
*/
void BUuECC_set_rng(BUuECC_RNG_Function rng_function);

/* BUuECC_get_rng() function.

Returns the function that will be used to generate random bytes.
*/
BUuECC_RNG_Function BUuECC_get_rng(void);

/* BUuECC_curve_private_key_size() function.

Returns the size of a private key for the curve in bytes.
*/
int BUuECC_curve_private_key_size(BUuECC_Curve curve);

/* BUuECC_curve_public_key_size() function.

Returns the size of a public key for the curve in bytes.
*/
int BUuECC_curve_public_key_size(BUuECC_Curve curve);

/* BUuECC_make_key() function.
Create a public/private key pair.

Outputs:
    public_key  - Will be filled in with the public key. Must be at least 2 * the curve size
                  (in bytes) long. For example, if the curve is secp256r1, public_key must be 64
                  bytes long.
    private_key - Will be filled in with the private key. Must be as long as the curve order; this
                  is typically the same as the curve size, except for secp160r1. For example, if the
                  curve is secp256r1, private_key must be 32 bytes long.

                  For secp160r1, private_key must be 21 bytes long! Note that the first byte will
                  almost always be 0 (there is about a 1 in 2^80 chance of it being non-zero).

Returns 1 if the key pair was generated successfully, 0 if an error occurred.
*/
int BUuECC_make_key(uint8_t *public_key, uint8_t *private_key, BUuECC_Curve curve);

/* BUuECC_shared_secret() function.
Compute a shared secret given your secret key and someone else's public key.
Note: It is recommended that you hash the result of BUuECC_shared_secret() before using it for
symmetric encryption or HMAC.

Inputs:
    public_key  - The public key of the remote party.
    private_key - Your private key.

Outputs:
    secret - Will be filled in with the shared secret value. Must be the same size as the
             curve size; for example, if the curve is secp256r1, secret must be 32 bytes long.

Returns 1 if the shared secret was generated successfully, 0 if an error occurred.
*/
int BUuECC_shared_secret(const uint8_t *public_key,
                       const uint8_t *private_key,
                       uint8_t *secret,
                       BUuECC_Curve curve);

#if BUuECC_SUPPORT_COMPRESSED_POINT
/* BUuECC_compress() function.
Compress a public key.

Inputs:
    public_key - The public key to compress.

Outputs:
    compressed - Will be filled in with the compressed public key. Must be at least
                 (curve size + 1) bytes long; for example, if the curve is secp256r1,
                 compressed must be 33 bytes long.
*/
void BUuECC_compress(const uint8_t *public_key, uint8_t *compressed, BUuECC_Curve curve);

/* BUuECC_decompress() function.
Decompress a compressed public key.

Inputs:
    compressed - The compressed public key.

Outputs:
    public_key - Will be filled in with the decompressed public key.
*/
void BUuECC_decompress(const uint8_t *compressed, uint8_t *public_key, BUuECC_Curve curve);
#endif /* BUuECC_SUPPORT_COMPRESSED_POINT */

/* BUuECC_valid_public_key() function.
Check to see if a public key is valid.

Note that you are not required to check for a valid public key before using any other BUuECC
functions. However, you may wish to avoid spending CPU time computing a shared secret or
verifying a signature using an invalid public key.

Inputs:
    public_key - The public key to check.

Returns 1 if the public key is valid, 0 if it is invalid.
*/
int BUuECC_valid_public_key(const uint8_t *public_key, BUuECC_Curve curve);

/* BUuECC_compute_public_key() function.
Compute the corresponding public key for a private key.

Inputs:
    private_key - The private key to compute the public key for

Outputs:
    public_key - Will be filled in with the corresponding public key

Returns 1 if the key was computed successfully, 0 if an error occurred.
*/
int BUuECC_compute_public_key(const uint8_t *private_key, uint8_t *public_key, BUuECC_Curve curve);

/* BUuECC_sign() function.
Generate an ECDSA signature for a given hash value.

Usage: Compute a hash of the data you wish to sign (SHA-2 is recommended) and pass it in to
this function along with your private key.

Inputs:
    private_key  - Your private key.
    message_hash - The hash of the message to sign.
    hash_size    - The size of message_hash in bytes.

Outputs:
    signature - Will be filled in with the signature value. Must be at least 2 * curve size long.
                For example, if the curve is secp256r1, signature must be 64 bytes long.

Returns 1 if the signature generated successfully, 0 if an error occurred.
*/
int BUuECC_sign(const uint8_t *private_key,
              const uint8_t *message_hash,
              unsigned hash_size,
              uint8_t *signature,
              BUuECC_Curve curve);

/* BUuECC_HashContext structure.
This is used to pass in an arbitrary hash function to BUuECC_sign_deterministic().
The structure will be used for multiple hash computations; each time a new hash
is computed, init_hash() will be called, followed by one or more calls to
update_hash(), and finally a call to finish_hash() to produce the resulting hash.

The intention is that you will create a structure that includes BUuECC_HashContext
followed by any hash-specific data. For example:

typedef struct SHA256_HashContext {
    BUuECC_HashContext BUuECC;
    SHA256_CTX ctx;
} SHA256_HashContext;

void init_SHA256(BUuECC_HashContext *base) {
    SHA256_HashContext *context = (SHA256_HashContext *)base;
    SHA256_Init(&context->ctx);
}

void update_SHA256(BUuECC_HashContext *base,
                   const uint8_t *message,
                   unsigned message_size) {
    SHA256_HashContext *context = (SHA256_HashContext *)base;
    SHA256_Update(&context->ctx, message, message_size);
}

void finish_SHA256(BUuECC_HashContext *base, uint8_t *hash_result) {
    SHA256_HashContext *context = (SHA256_HashContext *)base;
    SHA256_Final(hash_result, &context->ctx);
}

... when signing ...
{
    uint8_t tmp[32 + 32 + 64];
    SHA256_HashContext ctx = {{&init_SHA256, &update_SHA256, &finish_SHA256, 64, 32, tmp}};
    BUuECC_sign_deterministic(key, message_hash, &ctx.BUuECC, signature);
}
*/
typedef struct BUuECC_HashContext {
    void (*init_hash)(const struct BUuECC_HashContext *context);
    void (*update_hash)(const struct BUuECC_HashContext *context,
                        const uint8_t *message,
                        unsigned message_size);
    void (*finish_hash)(const struct BUuECC_HashContext *context, uint8_t *hash_result);
    unsigned block_size; /* Hash function block size in bytes, eg 64 for SHA-256. */
    unsigned result_size; /* Hash function result size in bytes, eg 32 for SHA-256. */
    uint8_t *tmp; /* Must point to a buffer of at least (2 * result_size + block_size) bytes. */
} BUuECC_HashContext;

/* BUuECC_sign_deterministic() function.
Generate an ECDSA signature for a given hash value, using a deterministic algorithm
(see RFC 6979). You do not need to set the RNG using BUuECC_set_rng() before calling
this function; however, if the RNG is defined it will improve resistance to side-channel
attacks.

Usage: Compute a hash of the data you wish to sign (SHA-2 is recommended) and pass it to
this function along with your private key and a hash context. Note that the message_hash
does not need to be computed with the same hash function used by hash_context.

Inputs:
    private_key  - Your private key.
    message_hash - The hash of the message to sign.
    hash_size    - The size of message_hash in bytes.
    hash_context - A hash context to use.

Outputs:
    signature - Will be filled in with the signature value.

Returns 1 if the signature generated successfully, 0 if an error occurred.
*/
int BUuECC_sign_deterministic(const uint8_t *private_key,
                            const uint8_t *message_hash,
                            unsigned hash_size,
                            const BUuECC_HashContext *hash_context,
                            uint8_t *signature,
                            BUuECC_Curve curve);

/* BUuECC_verify() function.
Verify an ECDSA signature.

Usage: Compute the hash of the signed data using the same hash as the signer and
pass it to this function along with the signer's public key and the signature values (r and s).

Inputs:
    public_key   - The signer's public key.
    message_hash - The hash of the signed data.
    hash_size    - The size of message_hash in bytes.
    signature    - The signature value.

Returns 1 if the signature is valid, 0 if it is invalid.
*/
int BUuECC_verify(const uint8_t *public_key,
                const uint8_t *message_hash,
                unsigned hash_size,
                const uint8_t *signature,
                BUuECC_Curve curve);

#ifdef __cplusplus
} /* end of extern "C" */
#endif

#endif /* _BUuECC_H_ */
