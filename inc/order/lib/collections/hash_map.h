#ifndef ORDER_INC_ORDER_LIB_COLLECTIONS_HASH_MAP_H
#define ORDER_INC_ORDER_LIB_COLLECTIONS_HASH_MAP_H

// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

// Constants

#define ORDER_PP_DEF_8hash_map_default_capacity ORDER_PP_CONST(16)

#define ORDER_PP_DEF_8hash_map_default_load_factor ORDER_PP_CONST((0)(0)(02))

// First-order


#define ORDER_PP_DEF_8hash_map_at \
ORDER_PP_FN(8fn(8K, 8M, \
                 0hm_find_in_bucket(8K, 0hm_equivalence_fn(8M), 8seq_at(0hm_bucket_index(8K, 0hm_hash_fn(8M), 0hm_capacity(8M)), 0hm_buckets(8M)))))


#define ORDER_PP_DEF_8hash_map_insert \
ORDER_PP_FN(8fn(8K, 8V, 8M, \
                 8apply(8fn(8A, 8B, \
                            8if(8A, \
                                0hm_rehash_if_needed(8inc(0hm_size(8M)), 0hm_capacity(8M), 8B, 8M), \
                                0hm_map_reset(0hm_size(8M), 0hm_capacity(8M), 8B, 8M))), \
                        0hm_insert_impl(8K, 8V, 0hm_buckets(8M), 8M))))


#define ORDER_PP_DEF_8hash_map_erase \
ORDER_PP_FN(8fn(8K, 8M, \
                8apply(8fn(8R, 8B, \
                           0hm_map_reset(8if(8R, 8dec(0hm_size(8M)), 0hm_size(8M)), 0hm_capacity(8M), 8B, 8M)), \
                       0hm_erase_impl(8K, 8M))))


#define ORDER_PP_DEF_8hash_map_from_seq_of_pairs \
ORDER_PP_FN(8fn(8E, 8H, 8S, \
                8seq_fold(8fn(8A, 8P, 8hash_map_insert(8tuple_at_0(8P), 8tuple_at_1(8P), 8A)), \
                          0hm_map_empty(8E, 8H, 8hash_map_default_capacity, 8hash_map_default_load_factor), \
                          8S)))

// Detail

#define ORDER_PP_DEF_0hm_map(eq,hash,size,capacity,load,buckets) ORDER_PP_MACRO(8tuple(eq,hash,size,capacity,load,buckets))
#define ORDER_PP_DEF_0hm_map_empty(eq,hash,capacity,load) ORDER_PP_MACRO(0hm_map(eq,hash,0,capacity,load,8seq_repeat(capacity,8(()))))

#define ORDER_PP_DEF_0hm_equivalence_fn ORDER_PP_MACRO(8tuple_at_0)
#define ORDER_PP_DEF_0hm_hash_fn ORDER_PP_MACRO(8tuple_at_1)
#define ORDER_PP_DEF_0hm_size ORDER_PP_MACRO(8tuple_at_2)
#define ORDER_PP_DEF_0hm_capacity ORDER_PP_MACRO(8tuple_at_3)
#define ORDER_PP_DEF_0hm_load_factor ORDER_PP_MACRO(8tuple_at_4)
#define ORDER_PP_DEF_0hm_buckets ORDER_PP_MACRO(8tuple_at_5)


#define ORDER_PP_DEF_0hm_node ORDER_PP_MACRO(8pair)

#define ORDER_PP_DEF_0hm_node_key ORDER_PP_MACRO(8tuple_at_0)
#define ORDER_PP_DEF_0hm_node_value ORDER_PP_MACRO(8tuple_at_1)


#define ORDER_PP_DEF_0hm_bucket_index(key,hash,cap) ORDER_PP_MACRO(8remainder(8ap(hash,key),cap))


#define ORDER_PP_DEF_0hm_find_in_bucket                                                                           \
ORDER_PP_FN(8fn(8K, 8E, 8B,                                                                                 \
                8call_cc(8fn(8C,                                                                        \
                             8seq_for_each(8fn(8N,                                                      \
                                               8when(0hm_node_matches(8K, 8E, 8N), \
                                                     8ap(8C, 0hm_node_value(8N)))),                        \
                                           8B)))))


#define ORDER_PP_DEF_0hm_insert_impl \
ORDER_PP_FN(8fn(8K, 8V, 8B, 8M, \
                 8apply(8fn(8H, 8T, \
                            8apply(8fn(8A, 8B, \
                                       8pair(8A, 8seq_append(8H, 8seq(8B), 8seq_tail(8T)))), \
                                   0hm_insert_in_bucket(8K, 8V, 0hm_equivalence_fn(8M), 8seq_head(8T)))), \
                        8seq_split_at(0hm_bucket_index(8K, 0hm_hash_fn(8M), 0hm_capacity(8M)), 8B))))

#define ORDER_PP_DEF_0hm_insert_in_bucket \
ORDER_PP_FN(8fn(8K, 8V, 8E, 8B, \
                8apply(8fn(8P, 8F, \
                           8pair(8is_nil(8P), 8seq_push_front(0hm_node(8K, 8V), 8F))), \
                       8seq_partition(8fn(8N, 0hm_node_matches(8K,8E,8N)), 8B))))

#define ORDER_PP_DEF_0hm_rehash_if_needed \
ORDER_PP_FN(8fn(8S, 8C, 8B, 8M, \
                8if(8greater(8quotient(8times(8S, 100), 8C), 0hm_load_factor(8M)), \
                    8seq_fold(8fn(8A, 8B, \
                                  0hm_map_reset(8plus(0hm_size(8A), 8seq_size(8B)), \
                                                0hm_capacity(8A), \
                                                8seq_fold(8fn(8X, 8Y, \
                                                              8tuple_at_1(0hm_insert_impl(0hm_node_key(8Y), 0hm_node_value(8Y), 8X, 8A))), \
                                                          0hm_buckets(8A), \
                                                          8B), \
                                                8A)), \
                              0hm_map_empty(0hm_equivalence_fn(8M), 0hm_hash_fn(8M), 8mul(8C, 2), 0hm_load_factor(8M)), \
                              8B), \
                    0hm_map_reset(8S, 8C, 8B, 8M))))


#define ORDER_PP_DEF_0hm_erase_impl \
ORDER_PP_FN(8fn(8K, 8M, \
                 8apply(8fn(8H, 8T, \
                            8apply(8fn(8A, 8B, \
                                       8pair(8A, 8seq_append(8H, 8seq(8B), 8seq_tail(8T)))), \
                                   0hm_erase_in_bucket(8K, 0hm_equivalence_fn(8M), 8seq_head(8T)))), \
                        8seq_split_at(0hm_bucket_index(8K, 0hm_hash_fn(8M), 0hm_capacity(8M)), 0hm_buckets(8M)))))

#define ORDER_PP_DEF_0hm_erase_in_bucket \
ORDER_PP_FN(8fn(8K, 8E, 8B, \
                8apply(8fn(8P, 8F, \
                           8pair(8isnt_nil(8P), 8F)), \
                       8seq_partition(8fn(8N, 0hm_node_matches(8K,8E,8N)), 8B))))


#define ORDER_PP_DEF_0hm_node_matches(key,eq,node) ORDER_PP_MACRO(8ap(eq,key,0hm_node_key(node)))


#define ORDER_PP_DEF_0hm_map_reset \
ORDER_PP_FN(8fn(8S, 8C, 8B, 8M, \
                0hm_map(0hm_equivalence_fn(8M), 0hm_hash_fn(8M), 8S, 8C, 0hm_load_factor(8M), 8B)))

#endif
