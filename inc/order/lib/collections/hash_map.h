#ifndef ORDER_INC_ORDER_LIB_COLLECTIONS_HASH_MAP_H
#define ORDER_INC_ORDER_LIB_COLLECTIONS_HASH_MAP_H

// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

// Constants

#define ORDER_PP_DEF_8hash_map_default_capacity ORDER_PP_CONST(16)


// First-order

#define ORDER_PP_DEF_8hash_map(...) ORDER_PP_CAT(0HASH_MAP_CTOR_,ORDER_PP_0HASH_MAP_CHOOSE_CTOR(__VA_ARGS__)),__VA_ARGS__,

#define ORDER_PP_0HASH_MAP_CHOOSE_CTOR(...) ORDER_PP_OVERLOAD(0HASH_MAP_CHOOSE_CTOR,ORDER_PP_TUPLE_SIZE(,__VA_ARGS__))(__VA_ARGS__) 
#define ORDER_PP_0HASH_MAP_CHOOSE_CTOR_2(q_eq,q_hash) EQ_HASH
#define ORDER_PP_0HASH_MAP_CHOOSE_CTOR_3(q_eq,q_hash,q_cap_or_items) ORDER_PP_ISNT_EDIBLE(,q_cap_or_items)(,EQ_HASH_CAPACITY,EQ_HASH_ITEMS)

#define ORDER_PP_0HASH_MAP_CTOR_EQ_HASH(P,env,q_eq,q_hash,G,...) (,P##q_eq,0HASH_MAP_CTOR_EQ_HASH_IMPL,P##q_hash,P##env,0HASH_MAP_CTOR_EQ_HASH_B,P##env,P##__VA_ARGS__)
#define ORDER_PP_0HASH_MAP_CTOR_EQ_HASH_B(P,eq_and_hash,env,...) (,P##env,0HASH_MAP_CTOR_COMPLETE,ORDER_PP_REM P##eq_and_hash,ORDER_PP_GET_CONST(8hash_map_default_capacity),,P##__VA_ARGS__)
#define ORDER_PP_0HASH_MAP_CTOR_EQ_HASH_IMPL(P,q_eq,q_hash,env,...) (,P##env,ORDER_PP_DEF_##q_eq,0HASH_MAP_CTOR_EQ_HASH_IMPL_B,P##q_hash,P##env,P##__VA_ARGS__)
#define ORDER_PP_0HASH_MAP_CTOR_EQ_HASH_IMPL_B(P,eq,q_hash,env,...) (,P##env,ORDER_PP_DEF_##q_hash,0HASH_MAP_CTOR_EQ_HASH_IMPL_C,P##eq,P##env,P##__VA_ARGS__)
#define ORDER_PP_0HASH_MAP_CTOR_EQ_HASH_IMPL_C(P,hash,eq,env,...) (,(P##eq,P##hash),P##__VA_ARGS__)

#define ORDER_PP_0HASH_MAP_CTOR_EQ_HASH_CAPACITY(P,env,q_eq,q_hash,q_capacity,G,...) (,P##env,ORDER_PP_DEF_##q_capacity,0HASH_MAP_CTOR_EQ_HASH_CAPACITY_B,P##q_eq,P##q_hash,P##env,P##__VA_ARGS__)
#define ORDER_PP_0HASH_MAP_CTOR_EQ_HASH_CAPACITY_B(P,capacity,q_eq,q_hash,env,...) (,P##q_eq,0HASH_MAP_CTOR_EQ_HASH_IMPL,P##q_hash,P##env,0HASH_MAP_CTOR_EQ_HASH_CAPACITY_C,P##capacity,P##env,P##__VA_ARGS__)
#define ORDER_PP_0HASH_MAP_CTOR_EQ_HASH_CAPACITY_C(P,eq_and_hash,capacity,env,...) (,P##env,0HASH_MAP_CTOR_COMPLETE,ORDER_PP_REM P##eq_and_hash,P##capacity,,P##__VA_ARGS__)

#define ORDER_PP_0HASH_MAP_CTOR_EQ_HASH_ITEMS(P,env,q_eq,q_hash,q_items,G,...) (,P##q_eq,0HASH_MAP_CTOR_EQ_HASH_IMPL,P##q_hash,P##env,0HASH_MAP_CTOR_EQ_HASH_ITEMS_LOOP,ORDER_PP_SEQ_AT_0 q_items##P(0hash_map_ctor_eq_hash_items_end,),P##env,,P##__VA_ARGS__)
#define ORDER_PP_0HASH_MAP_CTOR_EQ_HASH_ITEMS_LOOP(P,eq_and_hash,q_head_key,q_head_value,q_tail,env,acc,...) (,P##env,ORDER_PP_DEF_##q_head_key,0HASH_MAP_CTOR_EQ_HASH_ITEMS_LOOP_B,P##eq_and_hash,P##q_head_value,P##q_tail,P##env,P##acc,P##__VA_ARGS__)
#define ORDER_PP_0HASH_MAP_CTOR_EQ_HASH_ITEMS_LOOP_B(P,head_key,eq_and_hash,q_head_value,q_tail,env,acc,...) (,P##env,ORDER_PP_DEF_##q_head_value,0HASH_MAP_CTOR_EQ_HASH_ITEMS_LOOP_C,P##eq_and_hash,P##head_key,P##q_tail,P##env,P##acc,P##__VA_ARGS__)
#define ORDER_PP_0HASH_MAP_CTOR_EQ_HASH_ITEMS_LOOP_C(P,head_value,eq_and_hash,head_key,q_tail,env,acc,...) (,P##eq_and_hash,0HASH_MAP_CTOR_EQ_HASH_ITEMS_LOOP,ORDER_PP_SEQ_AT_0 q_tail##P,P##env,P##acc((P##head_key,P##head_value)),P##__VA_ARGS__)

#define ORDER_PP_DEF_0hash_map_ctor_eq_hash_items_end 0HASH_MAP_CTOR_EQ_HASH_ITEMS_END,
#define ORDER_PP_0HASH_MAP_CTOR_EQ_HASH_ITEMS_END(P, env, G, _loop_b_, _eq_and_hash_, _q_head_value_, _q_tail_, _env_, _acc_,...) (,P##env,0HASH_MAP_CTOR_COMPLETE,ORDER_PP_REM P##_eq_and_hash_,,P##_acc_,P##__VA_ARGS__)


#define ORDER_PP_0HASH_MAP_CTOR_COMPLETE(P,env,eq,hash,capacity,items,...) (,P##env,ORDER_PP_DEF_8hash_map_from_seq_of_pairs,0HASH_MAP_CTOR_COMPLETE_B,P##eq,P##hash,P##capacity,P##items,P##__VA_ARGS__)
#define ORDER_PP_0HASH_MAP_CTOR_COMPLETE_B(P,fold_fn,eq,hash,capacity,items,...) (,ORDER_PP_9APPLY(,fold_fn##P,(P##eq,P##hash,P##capacity,P##items)),P##__VA_ARGS__)


#define ORDER_PP_DEF_8hash_map_equivalence_fn ORDER_PP_FN(8fn(8M, 0hm_equivalence_fn(8M)))

#define ORDER_PP_DEF_8hash_map_hash_fn ORDER_PP_FN(8fn(8M, 0hm_hash_fn(8M)))

#define ORDER_PP_DEF_8hash_map_size ORDER_PP_FN(8fn(8M, 0hm_size(8M)))

#define ORDER_PP_DEF_8hash_map_capacity ORDER_PP_FN(8fn(8M, 0hm_capacity(8M)))

#define ORDER_PP_DEF_8hash_map_items ORDER_PP_FN_CM(1,8HASH_MAP_ITEMS,0IS_ANY)
#define ORDER_PP_8HASH_MAP_ITEMS(P,map,...) (,,8HASH_MAP_ITEMS_LOOP,ORDER_PP_SCAN(ORDER_PP_SEQ_AT_0 ORDER_PP_0HASH_MAP_BUCKETS(,P##map)),P##__VA_ARGS__) //
#define ORDER_PP_8HASH_MAP_ITEMS_LOOP(P,acc,head_bucket,tail_buckets,...) (,ORDER_PP_SEQ_IS_NIL(,P##tail_buckets)(,ORDER_PP_LEFT(,acc##P)P##head_bucket,ORDER_PP_LEFT(,acc##P)P##head_bucket,8HASH_MAP_ITEMS_LOOP,ORDER_PP_SEQ_AT_0 P##tail_buckets),P##__VA_ARGS__)


#define ORDER_PP_DEF_8hash_map_keys ORDER_PP_FN(8fn(8M, 8seq_map(8tuple_at_0, 8hash_map_items(8M))))
#define ORDER_PP_DEF_8hash_map_values ORDER_PP_FN(8fn(8M, 8seq_map(8tuple_at_1, 8hash_map_items(8M))))


#define ORDER_PP_DEF_8hash_map_at \
ORDER_PP_FN(8fn(8K, 8M, \
                 0hm_find_in_bucket(8K, 0hm_equivalence_fn(8M), 8seq_at(0hm_bucket_index(8K, 0hm_hash_fn(8M), 0hm_capacity(8M)), 0hm_buckets(8M)))))


#define ORDER_PP_DEF_8hash_map_insert \
ORDER_PP_FN(8fn(8K, 8V, 8M, \
                 8apply(8fn(8A, 8B, \
                            0hm_map_reset(8if(8A, 8inc(0hm_size(8M)), 0hm_size(8M)), 0hm_capacity(8M), 8B, 8M)), \
                        0hm_insert_in_bucket(8K, 8V, 8M))))


#define ORDER_PP_DEF_8hash_map_erase \
ORDER_PP_FN(8fn(8K, 8M, \
                8apply(8fn(8R, 8B, \
                           0hm_map_reset(8if(8R, 8dec(0hm_size(8M)), 0hm_size(8M)), 0hm_capacity(8M), 8B, 8M)), \
                       0hm_erase_impl(8K, 8M))))


#define ORDER_PP_DEF_8hash_map_exists \
ORDER_PP_FN(8fn(8K, 8M, \
                 8seq_exists(8fn(8N, 0hm_node_matches(8K, 0hm_equivalence_fn(8M), 8N)), \
                             8seq_at(0hm_bucket_index(8K, 0hm_hash_fn(8M), 0hm_capacity(8M)), 0hm_buckets(8M)))))


#define ORDER_PP_DEF_8hash_map_union \
ORDER_PP_FN(8fn(8M, 8N, \
                8seq_fold(8fn(8A, 8E, \
                              0hm_insert_pair(8E, 8A)), \
                          8M, \
                          8hash_map_items(8N))))


#define ORDER_PP_DEF_8hash_map_intersect \
ORDER_PP_FN(8fn(8M, 8N, \
                8seq_fold(8fn(8A, 8E, \
                              8if(8hash_map_exists(8tuple_at_0(8E), 8N), \
                                  0hm_insert_pair(8E, 8A), \
                                  8A)), \
                          0hm_map_empty(0hm_equivalence_fn(8M), 0hm_hash_fn(8M), 8max(0hm_capacity(8M), 0hm_capacity(8N))), \
                          8hash_map_items(8M))))


#define ORDER_PP_DEF_8hash_map_diff \
ORDER_PP_FN(8fn(8M, 8N, \
                8seq_fold(8fn(8A, 8E, \
                              8if(8hash_map_exists(8tuple_at_0(8E), 8N), \
                                  8A, \
                                  0hm_insert_pair(8E, 8A))), \
                          0hm_map_empty(0hm_equivalence_fn(8M), 0hm_hash_fn(8M), 8max(0hm_capacity(8M), 0hm_capacity(8N))), \
                          8hash_map_items(8M))))


#define ORDER_PP_DEF_8hash_map_symm_diff \
ORDER_PP_FN(8fn(8M, 8N, \
                8seq_fold(8fn(8A, 8E, \
                              8hash_map_erase(8tuple_at_0(8E), 8A)), \
                          8hash_map_union(8M, 8N), \
                          8hash_map_items(8hash_map_intersect(8M, 8N)))))


#define ORDER_PP_DEF_8hash_map_from_seq_of_pairs \
ORDER_PP_FN(8fn(8E, 8H, 8C, 8S, \
                8seq_fold(8fn(8A, 8P, 8hash_map_insert(8tuple_at_0(8P), 8tuple_at_1(8P), 8A)), \
                          0hm_map_empty(8E, 8H, 8if(8is_nil(8C), 8seq_size(8S), 8C)), \
                          8S)))

// Detail

#define ORDER_PP_DEF_0hm_map(eq,hash,size,capacity,buckets) ORDER_PP_MACRO(8tuple(eq,hash,size,capacity,buckets))
#define ORDER_PP_DEF_0hm_map_empty(eq,hash,capacity) ORDER_PP_MACRO(0hm_map(eq,hash,0,capacity,8seq_repeat(capacity,8(()))))

#define ORDER_PP_DEF_0hm_equivalence_fn ORDER_PP_MACRO(8tuple_at_0)
#define ORDER_PP_DEF_0hm_hash_fn ORDER_PP_MACRO(8tuple_at_1)
#define ORDER_PP_DEF_0hm_size ORDER_PP_MACRO(8tuple_at_2)
#define ORDER_PP_DEF_0hm_capacity ORDER_PP_MACRO(8tuple_at_3)

#define ORDER_PP_DEF_0hm_buckets ORDER_PP_FN_NATIVE(1,0HASH_MAP_BUCKETS,0IS_ANY)
#define ORDER_PP_0HASH_MAP_BUCKETS(P,map) ORDER_PP_FX(TUPLE_AT_4,(,ORDER_PP_REM P##map,))


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


#define ORDER_PP_DEF_0hm_insert_in_bucket \
ORDER_PP_FN(8fn(8K, 8V, 8M, \
                 8apply(8fn(8H, 8T, \
                            8apply(8fn(8A, 8B, \
                                       8pair(8A, 8seq_append(8H, 8seq(8B), 8seq_tail(8T)))), \
                                   0hm_insert_in_bucket_impl(8K, 8V, 0hm_equivalence_fn(8M), 8seq_head(8T)))), \
                        8seq_split_at(0hm_bucket_index(8K, 0hm_hash_fn(8M), 0hm_capacity(8M)), 0hm_buckets(8M)))))

#define ORDER_PP_DEF_0hm_insert_in_bucket_impl \
ORDER_PP_FN(8fn(8K, 8V, 8E, 8B, \
                8apply(8fn(8P, 8F, \
                           8pair(8is_nil(8P), 8seq_push_front(0hm_node(8K, 8V), 8F))), \
                       8seq_partition(8fn(8N, 0hm_node_matches(8K,8E,8N)), 8B))))


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

#define ORDER_PP_DEF_0hm_map_reset(size,capacity,buckets,map) \
ORDER_PP_MACRO(0hm_map(0hm_equivalence_fn(map),0hm_hash_fn(map),size,capacity,buckets))

#define ORDER_PP_DEF_0hm_insert_pair(pair,map) ORDER_PP_MACRO(8hash_map_insert(8tuple_at_0(pair), 8tuple_at_1(pair), map))

#endif
