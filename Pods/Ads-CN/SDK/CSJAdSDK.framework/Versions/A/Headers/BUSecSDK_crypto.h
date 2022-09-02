#ifndef _CRYPTO_H_
#define _CRYPTO_H_

#include <string.h>
#include <stdint.h>

bool duanzi_decode(uint8_t* in, uint32_t inlen, uint8_t** out, uint32_t* outlen);
bool duanzi_encode(uint8_t* in, uint32_t inlen, uint32_t mode, uint8_t** out, uint32_t* outlen);

// version of encode method
enum crypto_type2{encode_type=0, encode_type1=1};

#endif
