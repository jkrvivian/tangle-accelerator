#ifndef SERIALIZER_SERIALIZER_H_
#define SERIALIZER_SERIALIZER_H_

#include <stdlib.h>

#include "accelerator/errors.h"
#include "cJSON.h"
#include "cclient/types/types.h"
#include "common/trinary/tryte_ascii.h"
#include "request/request.h"
#include "response/response.h"

#ifdef __cplusplus
extern "C" {
#endif
/**
 * @file serializer.h
 * @brief Serialization of data strings
 * @example test_serializer.c
 */

//
/** @name Default input fields */
/** @{ */
/** Tag with mnemonic presentation of 'Powered by Tangle-Accelerator' */
#define DEFAULT_TAG "POWEREDBYTANGLEACCELERATOR9"
/** Address with mnemonic presentation of 'Powered by Tangle-Accelerator' */
#define DEFAULT_ADDRESS                      \
  "POWEREDBYTANGLEACCELERATOR99999999999999" \
  "99999999999999999999999999999999999999999"
/** 'Powered by tangle-accelerator' in ASCII */
#define DEFAULT_MSG "ZBCDKDTCFDTCSCEAQCMDEAHDPCBDVC9DTCRAPCRCRCTC9DTCFDPCHDCDFD"
/** Default message length */
#define DEFAULT_MSG_LEN 58
/** @} */

/**
 * @brief Serialze type of ta_generate_address_res_t to JSON string
 *
 * @param[out] obj Address hash in JSON
 * @param[in] res Response data in type of ta_generate_address_res_t
 *
 * @return
 * - SC_OK on success
 * - non-zero on error
 */
status_t ta_generate_address_res_serialize(
    char** obj, const ta_generate_address_res_t* const res);

/**
 * @brief Serialze type of ta_get_tips_res_t to JSON string
 *
 * @param[out] obj List of tip hashes in JSON
 * @param[in] res Response data in type of ta_get_tips_res_t
 *
 * @return
 * - SC_OK on success
 * - non-zero on error
 */
status_t ta_get_tips_res_serialize(char** obj,
                                   const ta_get_tips_res_t* const res);

/**
 * @brief Deserialze JSON string to type of ta_send_transfer_req_t
 *
 * @param[in] obj Input values in JSON
 * @param[out] req Request data in type of ta_send_transfer_req_t
 *
 * @return
 * - SC_OK on success
 * - non-zero on error
 */
status_t ta_send_transfer_req_deserialize(const char* const obj,
                                          ta_send_transfer_req_t* req);

/**
 * @brief Serialze type of ta_get_transaction_object_res_t to JSON string
 *
 * @param[out] obj List of transaction object in JSON
 * @param[in] res Response data in type of ta_get_transaction_object_res_t
 *
 * @return
 * - SC_OK on success
 * - non-zero on error
 */
status_t ta_get_transaction_object_res_serialize(
    char** obj, const ta_get_transaction_object_res_t* const res);

/**
 * @brief Serialze type of ta_find_transactions_res_t to JSON string
 *
 * @param[out] obj List of transaction hash in JSON
 * @param[in] res Response data in type of ta_find_transactions_res_t
 *
 * @return
 * - SC_OK on success
 * - non-zero on error
 */
status_t ta_find_transactions_res_serialize(
    char** obj, const ta_find_transactions_res_t* const res);

/**
 * @brief Serialze type of ta_find_transactions_obj_res_t to JSON string
 *
 * @param[out] obj List of transaction object in JSON
 * @param[in] res Response data in type of ta_find_transactions_obj_res_t
 *
 * @return
 * - SC_OK on success
 * - non-zero on error
 */
status_t ta_find_transactions_obj_res_serialize(
    char** obj, const ta_find_transactions_obj_res_t* const res);

/**
 * @brief Serialize mam message
 *
 * @param[out] obj message formed in JSON
 * @param[in] res Response of payload message
 *
 * @return
 * - SC_OK on success
 * - non-zero on error
 */
status_t receive_mam_message_serialize(char** obj, const char** res);

/**
 * @brief Serialze type of send_mam_res_t to JSON string
 *
 * @param[out] obj send mam response object in JSON
 * @param[in] res Response data in type of send_mam_res_t
 *
 * @return
 * - SC_OK on success
 * - non-zero on error
 */
status_t send_mam_res_serialize(char** obj, const send_mam_res_t* const res);

/**
 * @brief Deserialze JSON string to type of send_mam_res_t
 *
 * @param[in] obj Input values in JSON
 * @param[out] res Response data in type of send_mam_res_t
 *
 * @return
 * - SC_OK on success
 * - non-zero on error
 */
status_t send_mam_res_deserialize(const char* const obj,
                                  send_mam_res_t* const res);

/**
 * @brief Deserialze JSON string to type of send_mam_req_t
 *
 * @param[in] obj Input values in JSON
 * @param[out] req Request data in type of send_mam_req_t
 *
 * @return
 * - SC_OK on success
 * - non-zero on error
 */
status_t send_mam_req_deserialize(const char* const obj, send_mam_req_t* req);
#ifdef __cplusplus
}
#endif

#endif  // SERIALIZER_SERIALIZER_H_
