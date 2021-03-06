#include "serializer/serializer.h"
#include "test_define.h"

void test_serialize_ta_get_tips(void) {
  const char* json = "{\"tips\":[\"" TRYTES_81_1 "\",\"" TRYTES_81_2 "\"]}";
  char* json_result;
  ta_get_tips_res_t* res = ta_get_tips_res_new();
  flex_trit_t hash_trits_1[FLEX_TRIT_SIZE_243],
      hash_trits_2[FLEX_TRIT_SIZE_243];
  flex_trits_from_trytes(hash_trits_1, NUM_TRITS_HASH,
                         (const tryte_t*)TRYTES_81_1, NUM_TRYTES_HASH,
                         NUM_TRYTES_HASH);
  flex_trits_from_trytes(hash_trits_2, NUM_TRITS_HASH,
                         (const tryte_t*)TRYTES_81_2, NUM_TRYTES_HASH,
                         NUM_TRYTES_HASH);

  hash243_stack_push(&res->tips, hash_trits_2);
  hash243_stack_push(&res->tips, hash_trits_1);

  ta_get_tips_res_serialize(&json_result, res);
  TEST_ASSERT_EQUAL_STRING(json, json_result);
  ta_get_tips_res_free(&res);
  free(json_result);
}

void test_serialize_ta_generate_address(void) {
  const char* json = "{\"address\":[\"" TRYTES_81_1 "\",\"" TRYTES_81_2 "\"]}";
  char* json_result;
  ta_generate_address_res_t* res = ta_generate_address_res_new();
  flex_trit_t hash_trits_1[FLEX_TRIT_SIZE_243],
      hash_trits_2[FLEX_TRIT_SIZE_243];
  flex_trits_from_trytes(hash_trits_1, NUM_TRITS_HASH,
                         (const tryte_t*)TRYTES_81_1, NUM_TRYTES_HASH,
                         NUM_TRYTES_HASH);
  flex_trits_from_trytes(hash_trits_2, NUM_TRITS_HASH,
                         (const tryte_t*)TRYTES_81_2, NUM_TRYTES_HASH,
                         NUM_TRYTES_HASH);
  hash243_queue_push(&res->addresses, hash_trits_1);
  hash243_queue_push(&res->addresses, hash_trits_2);

  ta_generate_address_res_serialize(&json_result, res);
  TEST_ASSERT_EQUAL_STRING(json, json_result);
  ta_generate_address_res_free(&res);
  free(json_result);
}

void test_deserialize_ta_send_transfer(void) {
  const char* json =
      "{\"value\":100,"
      "\"message_format\":\"trytes\","
      "\"message\":\"" TAG_MSG "\",\"tag\":\"" TAG_MSG
      "\","
      "\"address\":\"" TRYTES_81_1 "\"}";

  ta_send_transfer_req_t* req = ta_send_transfer_req_new();
  flex_trit_t tag_msg_trits[FLEX_TRIT_SIZE_81],
      hash_trits_1[FLEX_TRIT_SIZE_243];

  ta_send_transfer_req_deserialize(json, req);

  TEST_ASSERT_EQUAL_INT(100, req->value);
  flex_trits_from_trytes(tag_msg_trits, NUM_TRITS_TAG, (const tryte_t*)TAG_MSG,
                         NUM_TRYTES_TAG, NUM_TRYTES_TAG);
  TEST_ASSERT_EQUAL_MEMORY(tag_msg_trits, req->tag->hash, FLEX_TRIT_SIZE_81);
  TEST_ASSERT_EQUAL_MEMORY(tag_msg_trits, req->message, FLEX_TRIT_SIZE_81);

  flex_trits_from_trytes(hash_trits_1, NUM_TRITS_HASH,
                         (const tryte_t*)TRYTES_81_1, NUM_TRYTES_HASH,
                         NUM_TRYTES_HASH);
  TEST_ASSERT_EQUAL_MEMORY(hash_trits_1, req->address->hash,
                           FLEX_TRIT_SIZE_243);

  ta_send_transfer_req_free(&req);
}

void test_serialize_ta_get_transaction_object(void) {
  const char* json =
      "{\"hash\":\"" TRYTES_81_1 "\","
      "\"signature_and_message_fragment\":\"" TRYTES_2187_1 "\","
      "\"address\":\"" TRYTES_81_1 "\",\"value\":" STR(VALUE) ","
      "\"obsolete_tag\":\"" TAG_MSG "\",\"timestamp\":" STR(TIMESTAMP) ","
      "\"current_index\":" STR(CURRENT_INDEX) ",\"last_index\":" STR(LAST_INDEX) ","
      "\"bundle_hash\":\"" TRYTES_81_2 "\","
      "\"trunk_transaction_hash\":\"" TRYTES_81_2 "\","
      "\"branch_transaction_hash\":\"" TRYTES_81_1 "\","
      "\"tag\":\"" TAG_MSG "\","
      "\"attachment_timestamp\":" STR(TIMESTAMP) ","
      "\"attachment_timestamp_lower_bound\":" STR(TIMESTAMP)","
      "\"attachment_timestamp_upper_bound\":" STR(TIMESTAMP)","
      "\"nonce\":\"" NONCE "\"}";
  char* json_result;
  flex_trit_t msg_trits[FLEX_TRIT_SIZE_6561], tag_trits[FLEX_TRIT_SIZE_81],
      hash_trits_1[FLEX_TRIT_SIZE_243], hash_trits_2[FLEX_TRIT_SIZE_243];
  ta_get_transaction_object_res_t* res = ta_get_transaction_object_res_new();
  res->txn = transaction_new();

  flex_trits_from_trytes(hash_trits_1, NUM_TRITS_HASH,
                         (const tryte_t*)TRYTES_81_1, NUM_TRYTES_HASH,
                         NUM_TRYTES_HASH);
  flex_trits_from_trytes(hash_trits_2, NUM_TRITS_HASH,
                         (const tryte_t*)TRYTES_81_2, NUM_TRYTES_HASH,
                         NUM_TRYTES_HASH);

  // set transaction hash
  transaction_set_hash(res->txn, hash_trits_1);

  // set message
  flex_trits_from_trytes(msg_trits, NUM_TRITS_SIGNATURE,
                         (const tryte_t*)TRYTES_2187_1, NUM_TRYTES_SIGNATURE,
                         NUM_TRYTES_SIGNATURE);
  transaction_set_signature(res->txn, msg_trits);

  // set address
  transaction_set_address(res->txn, hash_trits_1);
  // set value
  transaction_set_value(res->txn, VALUE);

  // set obsolete_tag
  flex_trits_from_trytes(tag_trits, NUM_TRITS_TAG, (const tryte_t*)TAG_MSG,
                         NUM_TRYTES_TAG, NUM_TRYTES_TAG);
  transaction_set_obsolete_tag(res->txn, tag_trits);

  // set timestamp
  transaction_set_timestamp(res->txn, TIMESTAMP);
  // set current_index
  transaction_set_current_index(res->txn, CURRENT_INDEX);
  // set last_index
  transaction_set_last_index(res->txn, LAST_INDEX);
  // set bundle_hash
  transaction_set_bundle(res->txn, hash_trits_2);
  // set trunk
  transaction_set_trunk(res->txn, hash_trits_2);
  // set branch
  transaction_set_branch(res->txn, hash_trits_1);
  // set tag
  transaction_set_tag(res->txn, tag_trits);
  // set attachment_timestamp
  transaction_set_attachment_timestamp(res->txn, TIMESTAMP);
  // set attachment_timestamp_lower_bound
  transaction_set_attachment_timestamp_lower(res->txn, TIMESTAMP);
  // set attachment_timestamp_upper_bound
  transaction_set_attachment_timestamp_upper(res->txn, TIMESTAMP);
  // set nonce
  flex_trits_from_trytes(tag_trits, NUM_TRITS_NONCE, (const tryte_t*)NONCE,
                         NUM_TRYTES_NONCE, NUM_TRYTES_NONCE);
  transaction_set_nonce(res->txn, tag_trits);

  ta_get_transaction_object_res_serialize(&json_result, res);

  TEST_ASSERT_EQUAL_STRING(json, json_result);
  ta_get_transaction_object_res_free(&res);
  free(json_result);
}

void test_serialize_ta_find_transactions_by_tag(void) {
  const char* json = "{\"hashes\":[\"" TRYTES_81_1 "\",\"" TRYTES_81_2 "\"]}";
  char* json_result;
  ta_find_transactions_res_t* res = ta_find_transactions_res_new();
  flex_trit_t hash_trits_1[FLEX_TRIT_SIZE_243],
      hash_trits_2[FLEX_TRIT_SIZE_243];
  flex_trits_from_trytes(hash_trits_1, NUM_TRITS_HASH,
                         (const tryte_t*)TRYTES_81_1, NUM_TRYTES_HASH,
                         NUM_TRYTES_HASH);
  flex_trits_from_trytes(hash_trits_2, NUM_TRITS_HASH,
                         (const tryte_t*)TRYTES_81_2, NUM_TRYTES_HASH,
                         NUM_TRYTES_HASH);

  hash243_queue_push(&res->hashes, hash_trits_1);
  hash243_queue_push(&res->hashes, hash_trits_2);

  ta_find_transactions_res_serialize(&json_result, res);

  TEST_ASSERT_EQUAL_STRING(json, json_result);
  ta_find_transactions_res_free(&res);
  free(json_result);
}

void test_serialize_ta_find_transactions_obj_by_tag(void) {
  const char* json =
      "{\"transactions\":[{\"hash\":\"" TRYTES_81_1 "\","
      "\"signature_and_message_fragment\":\"" TRYTES_2187_1 "\","
      "\"address\":\"" TRYTES_81_1 "\",\"value\":" STR(VALUE) ","
      "\"obsolete_tag\":\"" TAG_MSG "\",\"timestamp\":" STR(TIMESTAMP) ","
      "\"current_index\":" STR(CURRENT_INDEX) ",\"last_index\":" STR(LAST_INDEX) ","
      "\"bundle_hash\":\"" TRYTES_81_2 "\","
      "\"trunk_transaction_hash\":\"" TRYTES_81_2 "\","
      "\"branch_transaction_hash\":\"" TRYTES_81_1 "\","
      "\"tag\":\"" TAG_MSG "\","
      "\"attachment_timestamp\":" STR(TIMESTAMP) ","
      "\"attachment_timestamp_lower_bound\":" STR(TIMESTAMP)","
      "\"attachment_timestamp_upper_bound\":" STR(TIMESTAMP)","
      "\"nonce\":\"" NONCE "\"}]}";
  char* json_result;
  iota_transaction_t* txn = transaction_new();
  flex_trit_t msg_trits[FLEX_TRIT_SIZE_6561], tag_trits[FLEX_TRIT_SIZE_81],
      hash1[FLEX_TRIT_SIZE_243], hash2[FLEX_TRIT_SIZE_243];
  flex_trits_from_trytes(hash1, NUM_TRITS_HASH, (const tryte_t*)TRYTES_81_1,
                         NUM_TRYTES_HASH, NUM_TRYTES_HASH);
  flex_trits_from_trytes(hash2, NUM_TRITS_HASH, (const tryte_t*)TRYTES_81_2,
                         NUM_TRYTES_HASH, NUM_TRYTES_HASH);
  ta_find_transactions_obj_res_t* res = ta_find_transactions_obj_res_new();

  // set transaction hash
  transaction_set_hash(txn, hash1);

  // set message
  flex_trits_from_trytes(msg_trits, NUM_TRITS_SIGNATURE,
                         (const tryte_t*)TRYTES_2187_1, NUM_TRYTES_SIGNATURE,
                         NUM_TRYTES_SIGNATURE);
  transaction_set_signature(txn, msg_trits);

  // set address
  transaction_set_address(txn, hash1);
  // set value
  transaction_set_value(txn, VALUE);

  // set obsolete_tag
  flex_trits_from_trytes(tag_trits, NUM_TRITS_TAG, (const tryte_t*)TAG_MSG,
                         NUM_TRYTES_TAG, NUM_TRYTES_TAG);
  transaction_set_obsolete_tag(txn, tag_trits);

  // set timestamp
  transaction_set_timestamp(txn, TIMESTAMP);
  // set current_index
  transaction_set_current_index(txn, CURRENT_INDEX);
  // set last_index
  transaction_set_last_index(txn, LAST_INDEX);
  // set bundle_hash
  transaction_set_bundle(txn, hash2);
  // set trunk
  transaction_set_trunk(txn, hash2);
  // set branch
  transaction_set_branch(txn, hash1);
  // set tag
  transaction_set_tag(txn, tag_trits);
  // set attachment_timestamp
  transaction_set_attachment_timestamp(txn, TIMESTAMP);
  // set attachment_timestamp_lower_bound
  transaction_set_attachment_timestamp_lower(txn, TIMESTAMP);
  // set attachment_timestamp_upper_bound
  transaction_set_attachment_timestamp_upper(txn, TIMESTAMP);
  // set nonce
  flex_trits_from_trytes(tag_trits, NUM_TRITS_NONCE, (const tryte_t*)NONCE,
                         NUM_TRYTES_NONCE, NUM_TRYTES_NONCE);
  transaction_set_nonce(txn, tag_trits);

  utarray_push_back(res->txn_obj, txn);
  ta_find_transactions_obj_res_serialize(&json_result, res);

  TEST_ASSERT_EQUAL_STRING(json, json_result);
  ta_find_transactions_obj_res_free(&res);
  transaction_free(txn);
  free(json_result);
}

void test_serialize_send_mam_message(void) {
  const char* json = "{\"channel\":\"" TRYTES_81_1
                     "\","
                     "\"bundle_hash\":\"" TRYTES_81_2 "\"}";
  char* json_result;
  send_mam_res_t* res = send_mam_res_new();

  send_mam_res_set_bundle_hash(res, (tryte_t*)TRYTES_81_2);
  send_mam_res_set_channel_id(res, (tryte_t*)TRYTES_81_1);

  send_mam_res_serialize(&json_result, res);
  TEST_ASSERT_EQUAL_STRING(json, json_result);

  free(json_result);
  send_mam_res_free(&res);
}

void test_deserialize_send_mam_message_response(void) {
  const char* json = "{\"channel\":\"" TRYTES_81_1
                     "\","
                     "\"bundle_hash\":\"" TRYTES_81_2 "\"}";
  send_mam_res_t* res = send_mam_res_new();

  send_mam_res_deserialize(json, res);

  TEST_ASSERT_EQUAL_STRING(TRYTES_81_1, res->channel_id);
  TEST_ASSERT_EQUAL_STRING(TRYTES_81_2, res->bundle_hash);

  send_mam_res_free(&res);
}

void test_deserialize_send_mam_message(void) {
  const char* json = "{\"message\":\"" TEST_PAYLOAD "\"}";
  send_mam_req_t* req = send_mam_req_new();

  send_mam_req_deserialize(json, req);

  size_t payload_size = strlen(TEST_PAYLOAD) * 2;
  tryte_t* payload_trytes = (tryte_t*)malloc(payload_size * sizeof(tryte_t));
  ascii_to_trytes(TEST_PAYLOAD, payload_trytes);

  TEST_ASSERT_EQUAL_UINT(payload_size, req->payload_trytes_size);
  TEST_ASSERT_EQUAL_MEMORY(payload_trytes, req->payload_trytes, payload_size);

  free(payload_trytes);
  send_mam_req_free(&req);
}

int main(void) {
  UNITY_BEGIN();

  RUN_TEST(test_serialize_ta_get_tips);
  RUN_TEST(test_serialize_ta_generate_address);
  RUN_TEST(test_deserialize_ta_send_transfer);
  RUN_TEST(test_serialize_ta_get_transaction_object);
  RUN_TEST(test_serialize_ta_find_transactions_by_tag);
  RUN_TEST(test_serialize_ta_find_transactions_obj_by_tag);
  RUN_TEST(test_serialize_send_mam_message);
  RUN_TEST(test_deserialize_send_mam_message_response);
  RUN_TEST(test_deserialize_send_mam_message);
  return UNITY_END();
}
