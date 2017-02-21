/*
 * Part of μleb128.
 * 
 * Copyright (c) 2017 Alex Beregszaszi
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
*/

#ifndef __ULEB128_H
#define __ULEB128_H 1

#include <stdint.h>
#include <unistd.h>

typedef int (*uleb128_write_u8)(void *ctx, uint8_t value);
typedef int (*uleb128_read_u8)(void *ctx, uint8_t *value);

struct uleb128_io {
  uleb128_write_u8 write;
  void *write_ctx;
  uleb128_read_u8 read;
  void *read_ctx;
};

int uleb128_encode_u64(struct uleb128_io *io, uint64_t value);
int uleb128_encode_s64(struct uleb128_io *io, int64_t value);
int uleb128_encode_padded_u64(struct uleb128_io *io, uint64_t value, size_t width);
int uleb128_encode_padded_s64(struct uleb128_io *io, int64_t value, size_t width);

int uleb128_decode_u64(struct uleb128_io *io, uint64_t *value);
int uleb128_decode_s64(struct uleb128_io *io, int64_t *value);

#endif
