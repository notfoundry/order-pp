#ifndef ORDER_INC_ORDER_LIB_COLLECTIONS_TREE_MAP_H
#define ORDER_INC_ORDER_LIB_COLLECTIONS_TREE_MAP_H

// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#define ORDER_PP_DEF_0tm_node ORDER_PP_FN(8fn(8K, 8V, 8pair(8K, 8V)))
#define ORDER_PP_DEF_0tm_node_key ORDER_PP_FN(8fn(8N, 8tuple_at_0(8N)))
#define ORDER_PP_DEF_0tm_node_value ORDER_PP_FN(8fn(8N, 8tuple_at_1(8N)))

#define ORDER_PP_DEF_0tm_black ORDER_PP_CONST(0)
#define ORDER_PP_DEF_0tm_red ORDER_PP_CONST(1)
#define ORDER_PP_DEF_0tm_bblack ORDER_PP_CONST(1)

#define ORDER_PP_DEF_0tm_tree \
ORDER_PP_FN(8fn(8C /*Color*/, 8L /*LTree*/, 8N /*TreeNode*/, 8R /*RTree*/, \
                8tuple(8C, 8L, 8N, 8R)))
#define ORDER_PP_DEF_0tm_tree_color ORDER_PP_FN(8fn(8T, 8tuple_at_0(8T)))
#define ORDER_PP_DEF_0tm_tree_left ORDER_PP_FN(8fn(8T, 8tuple_at_1(8T)))
#define ORDER_PP_DEF_0tm_tree_node ORDER_PP_FN(8fn(8T, 8tuple_at_2(8T)))
#define ORDER_PP_DEF_0tm_tree_right ORDER_PP_FN(8fn(8T, 8tuple_at_3(8T)))
#define ORDER_PP_DEF_0tm_tree_colored ORDER_PP_FN(8fn(8T, 8C, 8equal(0tm_tree_color(8T), 8C)))

#define ORDER_PP_DEF_0tm_make_tree_black \
ORDER_PP_FN(8fn(8T, \
                8apply(8fn(8C, 8L, 8N, 8R, \
                           0tm_tree(0tm_black, 8L, 8N, 8R)), \
                       8T)))

#define ORDER_PP_DEF_0tm_member \
ORDER_PP_FN(8fn(8E, 8K, 8T, \
                8if(8is_nil(8T), \
                    8false, \
                    8apply(8fn(8C, 8L, 8Y, 8R, \
                           8cond((8ap(8E, 8K, 0tm_node_key(8Y)), 0tm_member(8E, 8K, 8L)) \
                                 (8ap(8E, 0tm_node_key(8Y), 8K), 0tm_member(8E, 8K, 8R)) \
                                 (8else, 8true))), \
                           8T))))

#define ORDER_PP_DEF_0tm_get \
ORDER_PP_FN(8fn(8E, 8K, 8T, \
                8if(8is_nil(8T), \
                    8nil, \
                    8apply(8fn(8C, 8L, 8Y, 8R, \
                           8cond((8ap(8E, 8K, 0tm_node_key(8Y)), 0tm_get(8E, 8K, 8L)) \
                                 (8ap(8E, 0tm_node_key(8Y), 8K), 0tm_get(8E, 8K, 8R)) \
                                 (8else, 0tm_node_value(8Y)))), \
                           8T))))

#define ORDER_PP_DEF_0tm_balance \
ORDER_PP_FN(8fn(8T, \
                8cond((0tm_tree_colored(8T, 0tm_black), \
                       8cond((8and(8isnt_nil(0tm_tree_left(8T)), 0tm_tree_colored(0tm_tree_left(8T), 0tm_red)), \
                           8cond((8and(8isnt_nil(0tm_tree_left(0tm_tree_left(8T))), 0tm_tree_colored(0tm_tree_left(0tm_tree_left(8T)), 0tm_red)), \
                                  8apply(8fn(8_, 8_, 8Z, 8D, 8_, 8_, 8Y, 8C, 8_, 8A, 8X, 8B, \
                                             0tm_tree(0tm_red, 0tm_tree(0tm_black, 8A, 8X, 8B), 8Y, 0tm_tree(0tm_black, 8C, 8Z, 8D))), \
                                          8tuple_append(8T, 0tm_tree_left(8T), 0tm_tree_left(0tm_tree_left(8T))))) \
                                 (8and(8isnt_nil(0tm_tree_right(0tm_tree_left(8T))), 0tm_tree_colored(0tm_tree_right(0tm_tree_left(8T)), 0tm_red)), \
                                  8apply(8fn(8_, 8_, 8Z, 8D, 8_, 8A, 8X, 8_, 8_, 8B, 8Y, 8C, \
                                             0tm_tree(0tm_red, 0tm_tree(0tm_black, 8A, 8X, 8B), 8Y, 0tm_tree(0tm_black, 8C, 8Z, 8D))), \
                                         8tuple_append(8T, 0tm_tree_left(8T), 0tm_tree_right(0tm_tree_left(8T))))) \
                                 (8else, 8T))) \
                          (8isnt_nil(0tm_tree_right(8T)), \
                           8cond((8and(8isnt_nil(0tm_tree_left(0tm_tree_right(8T))), 0tm_tree_colored(0tm_tree_left(0tm_tree_right(8T)), 0tm_red)), \
                                  8apply(8fn(8_, 8A, 8X, 8_, 8_, 8_, 8Z, 8D, 8_, 8B, 8Y, 8C, \
                                             0tm_tree(0tm_red, 0tm_tree(0tm_black, 8A, 8X, 8B), 8Y, 0tm_tree(0tm_black, 8C, 8Z, 8D))), \
                                         8tuple_append(8T, 0tm_tree_right(8T), 0tm_tree_left(0tm_tree_right(8T))))) \
                                 (8and(8isnt_nil(0tm_tree_right(0tm_tree_right(8T))), 0tm_tree_colored(0tm_tree_right(0tm_tree_right(8T)), 0tm_red)), \
                                  8apply(8fn(8_, 8A, 8X, 8_, 8_, 8B, 8Y, 8_, 8_, 8C, 8Z, 8D, \
                                             0tm_tree(0tm_red, 0tm_tree(0tm_black, 8A, 8X, 8B), 8Y, 0tm_tree(0tm_black, 8C, 8Z, 8D))), \
                                         8tuple_append(8T, 0tm_tree_right(8T), 0tm_tree_right(0tm_tree_right(8T))))) \
                                 (8else, 8T))) \
                          (8else, 8T))) \
                      (8else, 8T))))


#define ORDER_PP_DEF_0tm_insert_impl \
ORDER_PP_FN(8fn(8E, 8X, 8T, \
                8if(8is_nil(8T), \
                    0tm_tree(0tm_red, 8nil, 8X, 8nil), \
                    8apply(8fn(8C, 8L, 8Y, 8R, \
                               8cond((8ap(8E, 0tm_node_key(8X), 0tm_node_key(8Y)), 0tm_balance(0tm_tree(8C, 0tm_insert_impl(8E, 8X, 8L), 8Y, 8R))) \
                                     (8ap(8E, 0tm_node_key(8Y), 0tm_node_key(8X)), 0tm_balance(0tm_tree(8C, 8L, 8Y, 0tm_insert_impl(8E, 8X, 8R)))) \
                                     (8else, 0tm_tree(8C, 8L, 8X, 8R)))), \
                           8T))))

#define ORDER_PP_DEF_0tm_insert \
ORDER_PP_FN(8fn(8E, 8N, 8T, \
                0tm_make_tree_black(0tm_insert_impl(8E, 8N, 8T))))

#endif