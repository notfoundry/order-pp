#ifndef ORDER_INC_ORDER_LIB_HASH_SET_H
#define ORDER_INC_ORDER_LIB_HASH_SET_H

#include "order/lib/collections/hash_map.h"

// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

// First-order

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


#define ORDER_PP_DEF_8eq_set_erase ORDER_PP_MACRO(8hash_map_erase)


// Higher-order

#define ORDER_PP_DEF_8hash_set_union ORDER_PP_MACRO(8hash_map_union)


#define ORDER_PP_DEF_8hash_set_intersect ORDER_PP_MACRO(8hash_map_intersect)


#define ORDER_PP_DEF_8hash_set_diff ORDER_PP_MACRO(8hash_map_diff)


#define ORDER_PP_DEF_8hash_set_symm_diff ORDER_PP_MACRO(8hash_map_symm_diff)

#endif
