#ifndef ORDER_INC_ORDER_LIB_HASH_SET_H
#define ORDER_INC_ORDER_LIB_HASH_SET_H

#include "order/lib/collections/hash_map.h"

// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

// First-order

#define ORDER_PP_DEF_8hash_set(...) ORDER_PP_0HASH_SET_CHOOSE_CTOR(__VA_ARGS__),__VA_ARGS__,

#define ORDER_PP_0HASH_SET_CHOOSE_CTOR(...) ORDER_PP_OVERLOAD(0HASH_SET_CHOOSE_CTOR,ORDER_PP_TUPLE_SIZE(,__VA_ARGS__))(__VA_ARGS__) 
#define ORDER_PP_0HASH_SET_CHOOSE_CTOR_2(q_eq,q_hash) 0HASH_MAP_CTOR_EQ_HASH
#define ORDER_PP_0HASH_SET_CHOOSE_CTOR_3(q_eq,q_hash,q_cap_or_items) ORDER_PP_ISNT_EDIBLE(,q_cap_or_items)(,0HASH_MAP_CTOR_EQ_HASH_CAPACITY,0HASH_SET_CTOR_EQ_HASH_ITEMS)

#define ORDER_PP_0HASH_SET_CTOR_EQ_HASH_ITEMS(P,env,q_eq,q_hash,q_items,G,...) (,,0HASH_SET_CTOR_EQ_HASH_ITEMS_LOOP,ORDER_PP_SEQ_AT_0 P##q_items,0HASH_SET_CTOR_EQ_HASH_ITEMS_END,P##q_eq,P##q_hash,P##env,P##__VA_ARGS__)
#define ORDER_PP_0HASH_SET_CTOR_EQ_HASH_ITEMS_LOOP(P,acc,q_head,q_tail,...) (,ORDER_PP_SEQ_IS_NIL(,P##q_tail)(,acc##P(P##q_head,8nil),acc##P(P##q_head,8nil),0HASH_SET_CTOR_EQ_HASH_ITEMS_LOOP,ORDER_PP_SEQ_AT_0 P##q_tail),P##__VA_ARGS__)
#define ORDER_PP_0HASH_SET_CTOR_EQ_HASH_ITEMS_END(P,acc,q_eq,q_hash,env,...) (,P##env,0HASH_MAP_CTOR_EQ_HASH_ITEMS,P##q_eq,P##q_hash,P##acc,,P##__VA_ARGS__)


#define ORDER_PP_DEF_8basb_set_equivalence_fn ORDER_PP_MACRO(8hash_map_equivalence_fn)


#define ORDER_PP_DEF_8basb_set_hash_fn ORDER_PP_MACRO(8hash_map_hash_fn)


#define ORDER_PP_DEF_8basb_set_size ORDER_PP_MACRO(8hash_map_size)


#define ORDER_PP_DEF_8hash_set_items \
ORDER_PP_FN(8fn(8S, \
                   8seq_map(8tuple_at_0, 8hash_map_items(8S))))


#define ORDER_PP_DEF_8hash_set_exists ORDER_PP_MACRO(8hash_map_exists)


#define ORDER_PP_DEF_8hash_set_insert \
ORDER_PP_FN(8fn(8V, 8S, \
                8hash_map_insert(8V,8nil,8S)))


#define ORDER_PP_DEF_8hash_set_erase ORDER_PP_MACRO(8hash_map_erase)


// Higher-order

#define ORDER_PP_DEF_8hash_set_union ORDER_PP_MACRO(8hash_map_union)


#define ORDER_PP_DEF_8hash_set_intersect ORDER_PP_MACRO(8hash_map_intersect)


#define ORDER_PP_DEF_8hash_set_diff ORDER_PP_MACRO(8hash_map_diff)


#define ORDER_PP_DEF_8hash_set_symm_diff ORDER_PP_MACRO(8hash_map_symm_diff)

#endif
