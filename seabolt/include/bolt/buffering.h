/*
 * Copyright (c) 2002-2017 "Neo Technology,"
 * Network Engine for Objects in Lund AB [http://neotechnology.com]
 *
 * This file is part of Neo4j.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/**
 * @file
 */

#ifndef SEABOLT_BUFFERING
#define SEABOLT_BUFFERING


#include "config.h"

#include <stddef.h>
#include <stdint.h>


struct BoltBuffer
{
    int size;
    int extent;
    int cursor;
    char* data;
};


PUBLIC struct BoltBuffer* BoltBuffer_create(int size);

PUBLIC void BoltBuffer_destroy(struct BoltBuffer* buffer);

PUBLIC void BoltBuffer_compact(struct BoltBuffer* buffer);

PUBLIC int BoltBuffer_loadable(struct BoltBuffer* buffer);

PUBLIC char* BoltBuffer_load_target(struct BoltBuffer* buffer, int size);

PUBLIC void BoltBuffer_load(struct BoltBuffer* buffer, const char* data, int size);

PUBLIC int BoltBuffer_sizeof_utf8_char(uint32_t ch);

PUBLIC void BoltBuffer_load_utf8_char(struct BoltBuffer* buffer, uint32_t ch);

PUBLIC void BoltBuffer_load_uint8(struct BoltBuffer* buffer, uint8_t x);

PUBLIC void BoltBuffer_load_uint16_be(struct BoltBuffer* buffer, uint16_t x);

PUBLIC void BoltBuffer_load_int8(struct BoltBuffer* buffer, int8_t x);

PUBLIC void BoltBuffer_load_int16_be(struct BoltBuffer* buffer, int16_t x);

PUBLIC void BoltBuffer_load_int32_be(struct BoltBuffer* buffer, int32_t x);

PUBLIC void BoltBuffer_load_int64_be(struct BoltBuffer* buffer, int64_t x);

PUBLIC void BoltBuffer_load_double_be(struct BoltBuffer* buffer, double x);

PUBLIC int BoltBuffer_unloadable(struct BoltBuffer * buffer);

PUBLIC char* BoltBuffer_unload_target(struct BoltBuffer* buffer, int size);

PUBLIC int BoltBuffer_unload(struct BoltBuffer* buffer, char* data, int size);

PUBLIC int BoltBuffer_peek_uint8(struct BoltBuffer* buffer, uint8_t* x);

PUBLIC int BoltBuffer_unload_uint8(struct BoltBuffer* buffer, uint8_t* x);

PUBLIC int BoltBuffer_unload_uint16_be(struct BoltBuffer* buffer, uint16_t* x);

PUBLIC int BoltBuffer_unload_int8(struct BoltBuffer* buffer, int8_t* x);

PUBLIC int BoltBuffer_unload_int16_be(struct BoltBuffer* buffer, int16_t* x);

PUBLIC int BoltBuffer_unload_int32_be(struct BoltBuffer* buffer, int32_t* x);

PUBLIC int BoltBuffer_unload_int64_be(struct BoltBuffer* buffer, int64_t* x);

PUBLIC int BoltBuffer_unload_double_be(struct BoltBuffer* buffer, double* x);


#endif // SEABOLT_BUFFERING
