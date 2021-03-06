#ifndef UTILS_CACHE_H_
#define UTILS_CACHE_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "accelerator/errors.h"
#include "cclient/types/types.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @file cache.h
 * @brief Implementation of cache interface
 * @example test_cache.c
 */

/** struct of cache_t */
typedef struct {
  /** @cond private data */
  void* conn;
  /** @endcond */
} cache_t;

/**
 * Initiate cache module
 *
 * @param[in] host cache server host
 * @param[in] port cache server port
 *
 * @return
 * - True on success
 * - False on error
 */
bool cache_init(const char* host, int port);

/**
 * Stop interacting with cache module
 *
 * @return NULL
 */
void cache_stop();

/**
 * Delete certain key-value store from cache
 *
 * @param[in] key Key string to search
 *
 * @return
 * - SC_OK on success
 * - non-zero on error
 */
status_t cache_del(const char* const key);

/**
 * Get key-value store from in-memory cache
 *
 * @param[in] key Key string to search
 * @param[out] res Result of GET key
 *
 * @return
 * - SC_OK on success
 * - non-zero on error
 */
status_t cache_get(const char* const key, char* res);

/**
 * Set key-value store into in-memory cache
 *
 * @param[in] cache Data type for Cache module
 * @param[in] key Key string to store
 * @param[in] value Value string to store
 *
 * @return
 * - SC_OK on success
 * - non-zero on error
 */
status_t cache_set(const char* const key, const char* const value);

#ifdef __cplusplus
}
#endif

#endif  // UTILS_CACHE_H_
