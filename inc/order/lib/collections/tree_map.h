#ifndef ORDER_INC_ORDER_LIB_COLLECTIONS_TREE_TREE_MAP_H
#define ORDER_INC_ORDER_LIB_COLLECTIONS_TREE_TREE_MAP_H

// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#define ORDER_PP_DEF_8tree_map(...) 8EVAL_TREE_MAP,ORDER_PP_0EVAL_TREE_MAP_ARGS(__VA_ARGS__)(0tree_map_eval_terminate,),

#define ORDER_PP_0EVAL_TREE_MAP_ARGS(...) ORDER_PP_OVERLOAD(0EVAL_TREE_MAP_ARGS, ORDER_PP_IS_TUPLE_SIZE_1(,__VA_ARGS__)(,1,N))(__VA_ARGS__)
#define ORDER_PP_0EVAL_TREE_MAP_ARGS_1(cmp) cmp,ORDER_PP_SEQ_AT_0
#define ORDER_PP_0EVAL_TREE_MAP_ARGS_N(cmp, ...) cmp,ORDER_PP_SEQ_AT_0 __VA_ARGS__

#define ORDER_PP_8EVAL_TREE_MAP(P, env, q_cmp, q_head_key, q_head_value, tail, G, ...) \
                          (,P##env,ORDER_PP_DEF_##q_cmp,8EVAL_TREE_MAP_LOOP,P##q_head_key,P##q_head_value,P##tail,,P##env,P##__VA_ARGS__)
#define ORDER_PP_8EVAL_TREE_MAP_LOOP(P, cmp, q_head_key, q_head_value, tail, acc, env, ...) \
                               (,P##env,ORDER_PP_DEF_##q_head_key,8EVAL_TREE_MAP_LOOP_B,P##q_head_value,P##tail,P##acc,P##cmp,P##env,P##__VA_ARGS__)
#define ORDER_PP_8EVAL_TREE_MAP_LOOP_B(P, head_key, q_head_value, tail, acc, cmp, env, ...) \
                                 (,P##env,ORDER_PP_DEF_##q_head_value,8EVAL_TREE_MAP_LOOP_C,P##head_key,P##tail,P##acc,P##cmp,P##env,P##__VA_ARGS__)
#define ORDER_PP_8EVAL_TREE_MAP_LOOP_C(P, head_value, head_key, tail, acc, cmp, env, ...) \
                                 (,P##cmp,8EVAL_TREE_MAP_LOOP,ORDER_PP_SEQ_AT_0 tail##P,P##acc(P##head_key,P##head_value),P##env,P##__VA_ARGS__)

#define ORDER_PP_DEF_0tree_map_eval_terminate 0EVAL_TREE_MAP_TERMINATE,
#define ORDER_PP_0EVAL_TREE_MAP_TERMINATE(P, env, G, _eval_tree_map_loop_b_, _q_head_value_, _tail_, _acc_, _cmp_, _env_,...) \
                                    (,P##env, ORDER_PP_DEF_8tree_map_from_seq_of_pairs, 0EVAL_TREE_MAP_TERMINATE_B, P##_cmp_, ORDER_PP_9VSEQ_TO_SEQ_OF_TUPLES(,P##_acc_), P##__VA_ARGS__)
#define ORDER_PP_0EVAL_TREE_MAP_TERMINATE_B(P, fold_fn, cmp, acc, ...) (,P##cmp,ORDER_PP_OPEN fold_fn##P,8AP, P##acc,P##__VA_ARGS__)


#define ORDER_PP_DEF_8tree_map_comparison_fn ORDER_PP_FN_NATIVE(1,8TREE_MAP_COMPARISON_FN,0IS_TREE_MAP)
#define ORDER_PP_8TREE_MAP_COMPARISON_FN(P, map) ORDER_PP_FX(TUPLE_AT_0,(,ORDER_PP_REM P##map,))


#define ORDER_PP_DEF_8tree_map_at \
ORDER_PP_FN(8fn(8K, 8M, \
                 0tm_get(8tree_map_comparison_fn(8M), 8K, 0tree_map_items(8M))))


#define ORDER_PP_DEF_8tree_map_insert \
ORDER_PP_FN(8fn(8K, 8V, 8M, \
                0tree_map_reset(0tm_insert(8tree_map_comparison_fn(8M), 0tm_node(8K, 8V), 0tree_map_items(8M)), 8M)))


#define ORDER_PP_DEF_8tree_map_erase \
ORDER_PP_FN(8fn(8K, 8M, \
                0tree_map_reset(0tm_delete(8tree_map_comparison_fn(8M), 8K, 0tree_map_items(8M)), 8M)))


#define ORDER_PP_DEF_8tree_map_exists \
ORDER_PP_FN(8fn(8K, 8M, \
                0tree_map_reset(0tm_member(8tree_map_comparison_fn(8M), 8K, 0tree_map_items(8M)), 8M)))


#define ORDER_PP_DEF_8is_tree_map ORDER_PP_FN_CM(1,8IS_TREE_MAP,0IS_ANY)
#define ORDER_PP_8IS_TREE_MAP(P,x,...) (,ORDER_PP_0IS_TREE_MAP(,P##x)(,8true,8false),P##__VA_ARGS__)

#define ORDER_PP_DEF_8tree_map_from_seq_of_pairs \
ORDER_PP_FN(8fn(8C, 8S, \
                8pair(8C, 8seq_fold(8fn(8A, 8P, 0tm_insert(8C, 8P, 8A)), \
                                        0tm_leaf(0tm_black), \
                                    8S))))

// Detail

#define ORDER_PP_DEF_0tree_map_items ORDER_PP_FN_NATIVE(1,0TREE_MAP_ITEMS,0IS_TREE_MAP)
#define ORDER_PP_0TREE_MAP_ITEMS(P, map) ORDER_PP_FX(TUPLE_AT_1,(,ORDER_PP_REM P##map,))

#define ORDER_PP_DEF_0tree_map_reset ORDER_PP_FN(8fn(8E, 8M, 8pair(8tree_map_comparison_fn(8M), 8E)))

#define ORDER_PP_0IS_TREE_MAP(P,x) ORDER_PP_AND                                                                  \
                              (and)(ORDER_PP_0IS_TUPLE(,P##x))                                              \
                              (and)(ORDER_PP_FY(IS_TUPLE_SIZE_2,(,ORDER_PP_REM P##x)))                      \
                              (and)(ORDER_PP_FY(0IS_FN,(,ORDER_PP_FX(TUPLE_AT_0,(,ORDER_PP_REM P##x,)))))()

// Implementation

#define ORDER_PP_DEF_0tm_node ORDER_PP_FN(8fn(8K, 8V, 8pair(8K, 8V)))
#define ORDER_PP_DEF_0tm_node_key ORDER_PP_FN(8fn(8N, 8tuple_at_0(8N)))
#define ORDER_PP_DEF_0tm_node_value ORDER_PP_FN(8fn(8N, 8tuple_at_1(8N)))

#define ORDER_PP_DEF_0tm_black ORDER_PP_CONST(0)
#define ORDER_PP_DEF_0tm_red ORDER_PP_CONST(1)
#define ORDER_PP_DEF_0tm_bblack ORDER_PP_CONST(1)

#define ORDER_PP_DEF_0tm_tree ORDER_PP_FN(8fn(8C, 8L, 8N, 8R, \
                                              8with_assert(8and(8is_lit(8C), 8is_tuple(8L), 8is_tuple(8N), 8is_tuple(8R)), 8tuple(8C, 8L, 8N, 8R))))
#define ORDER_PP_DEF_0tm_tree_color ORDER_PP_FN(8fn(8T, 8tuple_at_0(8T)))
#define ORDER_PP_DEF_0tm_tree_left ORDER_PP_FN(8fn(8T, 8tuple_at_1(8T)))
#define ORDER_PP_DEF_0tm_tree_node ORDER_PP_FN(8fn(8T, 8tuple_at_2(8T)))
#define ORDER_PP_DEF_0tm_tree_right ORDER_PP_FN(8fn(8T, 8tuple_at_3(8T)))
#define ORDER_PP_DEF_0tm_tree_colored ORDER_PP_FN(8fn(8T, 8C, 8and(0tm_is_tree(8T), 0tm_tree_colored_impl(0tm_tree_color(8T), 8C))))
#define ORDER_PP_DEF_0tm_is_tree ORDER_PP_FN(8fn(8T, 8not(0tm_is_leaf(8T))))

#define ORDER_PP_DEF_0tm_tree_colored_impl ORDER_PP_FN(8fn(8T, 8C, 8equal(8T, 8C)))

#define ORDER_PP_DEF_0tm_leaf ORDER_PP_FN(8fn(8C, 8tuple(8C)))
#define ORDER_PP_DEF_0tm_leaf_colored ORDER_PP_FN(8fn(8T, 8C, 8and(0tm_is_leaf(8T), 0tm_tree_colored_impl(0tm_tree_color(8T), 8C))))
#define ORDER_PP_DEF_0tm_is_leaf ORDER_PP_FN(8fn(8T, 8is_seq(8T)))


#define ORDER_PP_DEF_0tm_make_tree_black \
ORDER_PP_FN(8fn(8T, \
                8if(0tm_tree_colored(8T, 0tm_red), \
                    8apply(8fn(8C, 8L, 8N, 8R, \
                           0tm_tree(0tm_black, 8L, 8N, 8R)), \
                       8T), \
                    8T)))

#define ORDER_PP_DEF_0tm_member \
ORDER_PP_FN(8fn(8E, 8K, 8T, \
                8if(0tm_is_leaf(8T), \
                    8false, \
                    8apply(8fn(8C, 8L, 8Y, 8R, \
                           8cond((8ap(8E, 8K, 0tm_node_key(8Y)), 0tm_member(8E, 8K, 8L)) \
                                 (8ap(8E, 0tm_node_key(8Y), 8K), 0tm_member(8E, 8K, 8R)) \
                                 (8else, 8true))), \
                           8T))))

#define ORDER_PP_DEF_0tm_get \
ORDER_PP_FN(8fn(8E, 8K, 8T, \
                8if(0tm_is_leaf(8T), \
                    8nil, \
                    8apply(8fn(8C, 8L, 8Y, 8R, \
                           8cond((8ap(8E, 8K, 0tm_node_key(8Y)), 0tm_get(8E, 8K, 8L)) \
                                 (8ap(8E, 0tm_node_key(8Y), 8K), 0tm_get(8E, 8K, 8R)) \
                                 (8else, 0tm_node_value(8Y)))), \
                           8T))))

#define ORDER_PP_DEF_0tm_balance \
ORDER_PP_FN(8fn(8T, \
                8cond((0tm_tree_colored(8T, 0tm_black), \
                       8cond((8and(0tm_tree_colored(0tm_tree_left(8T), 0tm_red), 0tm_tree_colored(0tm_tree_left(0tm_tree_left(8T)), 0tm_red)), \
                              8apply(8fn(8_, 8_, 8Z, 8D, 8_, 8_, 8Y, 8C, 8_, 8A, 8X, 8B, \
                                         0tm_tree(0tm_red, 0tm_tree(0tm_black, 8A, 8X, 8B), 8Y, 0tm_tree(0tm_black, 8C, 8Z, 8D))), \
                                     8tuple_append(8T, 0tm_tree_left(8T), 0tm_tree_left(0tm_tree_left(8T))))) \
                             (8and(0tm_tree_colored(0tm_tree_left(8T), 0tm_red), 0tm_tree_colored(0tm_tree_right(0tm_tree_left(8T)), 0tm_red)), \
                              8apply(8fn(8_, 8_, 8Z, 8D, 8_, 8A, 8X, 8_, 8_, 8B, 8Y, 8C, \
                                         0tm_tree(0tm_red, 0tm_tree(0tm_black, 8A, 8X, 8B), 8Y, 0tm_tree(0tm_black, 8C, 8Z, 8D))), \
                                     8tuple_append(8T, 0tm_tree_left(8T), 0tm_tree_right(0tm_tree_left(8T))))) \
                             (8and(0tm_tree_colored(0tm_tree_right(8T), 0tm_red), 0tm_tree_colored(0tm_tree_left(0tm_tree_right(8T)), 0tm_red)), \
                              8apply(8fn(8_, 8A, 8X, 8_, 8_, 8_, 8Z, 8D, 8_, 8B, 8Y, 8C, \
                                         0tm_tree(0tm_red, 0tm_tree(0tm_black, 8A, 8X, 8B), 8Y, 0tm_tree(0tm_black, 8C, 8Z, 8D))), \
                                     8tuple_append(8T, 0tm_tree_right(8T), 0tm_tree_left(0tm_tree_right(8T))))) \
                             (8and(0tm_tree_colored(0tm_tree_right(8T), 0tm_red), 0tm_tree_colored(0tm_tree_right(0tm_tree_right(8T)), 0tm_red)), \
                              8apply(8fn(8_, 8A, 8X, 8_, 8_, 8B, 8Y, 8_, 8_, 8C, 8Z, 8D, \
                                         0tm_tree(0tm_red, 0tm_tree(0tm_black, 8A, 8X, 8B), 8Y, 0tm_tree(0tm_black, 8C, 8Z, 8D))), \
                                     8tuple_append(8T, 0tm_tree_right(8T), 0tm_tree_right(0tm_tree_right(8T))))) \
                             (8else, 8T))) \
                      (0tm_tree_colored(8T, 0tm_bblack), \
                       8cond((8and(0tm_tree_colored(0tm_tree_left(8T), 0tm_red), 0tm_tree_colored(0tm_tree_right(0tm_tree_left(8T)), 0tm_red)), \
                              8apply(8fn(8_, 8_, 8Z, 8D, 8_, 8A, 8X, 8_, 8_, 8B, 8Y, 8C, \
                                         0tm_tree(0tm_black, 0tm_tree(0tm_black, 8A, 8X, 8B), 8Y, 0tm_tree(0tm_black, 8C, 8Z, 8D))), \
                                     8tuple_append(8T, 0tm_tree_left(8T), 0tm_tree_right(0tm_tree_left(8T))))) \
                             (8and(0tm_tree_colored(0tm_tree_right(8T), 0tm_red), 0tm_tree_colored(0tm_tree_left(0tm_tree_right(8T)), 0tm_red)), \
                              8apply(8fn(8_, 8A, 8X, 8_, 8_, 8_, 8Z, 8D, 8_, 8B, 8Y, 8C, \
                                         0tm_tree(0tm_black, 0tm_tree(0tm_black, 8A, 8X, 8B), 8Y, 0tm_tree(0tm_black, 8C, 8Z, 8D))), \
                                     8tuple_append(8T, 0tm_Tree_right(8T), 0tm_tree_left(0tm_tree_right(8T))))) \
                             (8else, 8T))) \
                      (8else, 8T))))


#define ORDER_PP_DEF_0tm_demote_bblack \
ORDER_PP_FN(8fn(8T, \
                8cond((0tm_leaf_colored(8T, 0tm_bblack), \
                       0tm_leaf(0tm_black)) \
                      (0tm_tree_colored(8T, 0tm_bblack), \
                       8apply(8fn(8C, 8L, 8N, 8R, \
                                  0tm_tree(0tm_black, 8L, 8N, 8R)), \
                              8T)) \
                      (8else, 8exit(8(called demote_bblack on tree that was not double black))))))


#define ORDER_PP_DEF_0tm_redden \
ORDER_PP_FN(8fn(8T, \
                8cond((8and(0tm_tree_colored(8T, 0tm_black), 0tm_tree_colored(0tm_tree_left(8T), 0tm_black), 0tm_tree_colored(0tm_tree_right(8T), 0tm_black)), \
                       8apply(8fn(8C, 8L, 8N, 8R, \
                                  0tm_tree(0tm_red, 8L, 8N, 8R)), \
                              8T)) \
                      (8else, 8T))))


#define ORDER_PP_DEF_0tm_min_delete \
ORDER_PP_FN(8fn(8T, \
                8cond((0tm_leaf_colored(8T, 0tm_black), 8exit(8(called min_delete on empty tree))) \
                      (8and(0tm_tree_colored(8T, 0tm_red), 0tm_leaf_colored(0tm_tree_left(8T), 0tm_black), 0tm_leaf_colored(0tm_tree_right(8T), 0tm_black)), \
                       8pair(0tm_tree_node(8T), 0tm_leaf(0tm_black))) \
                      (8and(0tm_tree_colored(8T, 0tm_black), 0tm_leaf_colored(0tm_tree_left(8T), 0tm_black), 0tm_leaf_colored(0tm_tree_right(8T), 0tm_black)), \
                       8pair(0tm_tree_node(8T), 0tm_leaf(0tm_bblack))) \
                      (8and(0tm_tree_colored(8T, 0tm_black), 0tm_leaf_colored(0tm_tree_left(8T), 0tm_black), 0tm_tree_colored(0tm_tree_right(8T), 0tm_red)), \
                       8apply(8fn(8C, 8L, 8N, 8R, \
                                  8pair(0tm_tree_node(8T), 0tm_tree(0tm_black, 8L, 8N, 8R))), \
                              0tm_tree_right(8T))) \
                      (0tm_is_tree(8T), \
                       8apply(8fn(8C, 8L, 8N, 8R, \
                                  8apply(8fn(8M, 8L, \
                                             8pair(8M, 0tm_rotate(0tm_tree(8C, 8L, 8N, 8R)))), \
                                         0tm_min_delete(8L))), \
                              8T)) \
                      (8else, 8exit(8(called min_delete on miscolored leaf node))))))


#define ORDER_PP_DEF_0tm_rotate \
ORDER_PP_FN(8fn(8T, \
                8cond((8and(0tm_tree_colored(8T, 0tm_red), 0tm_tree_colored(0tm_tree_left(8T), 0tm_bblack), 0tm_tree_colored(0tm_tree_right(8T), 0tm_black)), \
                       8apply(8fn(8_, 8A, 8Y, 8_, 8_, 8C, 8Z, 8D, \
                                  0tm_balance(0tm_tree(0tm_black, 0tm_tree(0tm_red, 0tm_demote_bblack(8A), 8Y, 8C), 8Z, 8D))), \
                              8tuple_append(8T, 0tm_tree_right(8T)))) \
                      (8and(0tm_tree_colored(8T, 0tm_red), 0tm_tree_colored(0tm_tree_left(8T), 0tm_black), 0tm_tree_colored(0tm_tree_right(8T), 0tm_bblack)), \
                       8apply(8fn(8_, 8_, 8Y, 8C, 8_, 8A, 8X, 8B, \
                                  0tm_balance(0tm_tree(0tm_black, 8A, 8X, 0tm_tree(0tm_red, 8B, 8Y, 0tm_demote_bblack(8C))))), \
                              8tuple_append(8T, 0tm_tree_left(8T)))) \
                      (8and(0tm_tree_colored(8T, 0tm_black), 0tm_tree_colored(0tm_tree_left(8T), 0tm_bblack), 0tm_tree_colored(0tm_tree_right(8T), 0tm_black)), \
                       8apply(8fn(8_, 8A, 8Y, 8_, 8_, 8C, 8Z, 8D, \
                                  0tm_balance(0tm_tree(0tm_bblack, 0tm_tree(0tm_red, 0tm_demote_bblack(8A), 8Y, 8C), 8Z, 8D))), \
                              8tuple_append(8T, 0tm_tree_right(8T)))) \
                      (8and(0tm_tree_colored(8T, 0tm_black), 0tm_tree_colored(0tm_tree_left(8T), 0tm_black), 0tm_tree_colored(0tm_tree_right(8T), 0tm_bblack)), \
                       8apply(8fn(8_, 8_, 8Y, 8C, 8_, 8A, 8X, 8B, \
                                  0tm_balance(0tm_tree(0tm_bblack, 8A, 8X, 0tm_tree(0tm_red, 8B, 8Y, 0tm_demote_bblack(8C))))), \
                              8tuple_append(8T, 0tm_tree_left(8T)))) \
                      (8and(0tm_tree_colored(8T, 0tm_black), 0tm_tree_colored(0tm_tree_left(8T), 0tm_bblack), 0tm_tree_colored(0tm_tree_right(8T), 0tm_red), 0tm_tree_colored(0tm_tree_left(0tm_tree_right(8T)), 0tm_black)), \
                       8apply(8fn(8_, 8A, 8X, 8_, 8_, 8_, 8Z, 8E, 8_, 8C, 8Y, 8D, \
                                  0tm_tree(0tm_black, 0tm_balance(0tm_tree(0tm_red, 0tm_demote_bblack(8A), 8X, 8C)), 8Z, 8E)), \
                              8tuple_append(8T, 0tm_tree_right(8T), 0tm_tree_left(0tm_tree_right(8T))))) \
                      (8and(0tm_tree_colored(8T, 0tm_black), 0tm_tree_colored(0tm_tree_left(8T), 0tm_red), 0tm_tree_colored(0tm_tree_right(0tm_tree_left(8T)), 0tm_black), 0tm_tree_colored(0tm_tree_right, 0tm_bblack)), \
                       8apply(8fn(8_, 8_, 8Y, 8D, 8_, 8A, 8W, 8_, 8_, 8B, 8X, 8C, \
                                  0tm_tree(0tm_black, 8A, 8W, 0tm_balance(0tm_tree(0tm_black, 8B, 8X, 0tm_tree(0tm_red, 8C, 8Y, 0tm_demote_bblack(8D)))))), \
                              8tuple_append(8T, 0tm_tree_left(8T), 0tm_tree_right(0tm_tree_left(8T))))) \
                      (8else, 8T))))


#define ORDER_PP_DEF_0tm_delete_impl \
ORDER_PP_FN(8fn(8E, 8K, 8T, \
                8cond((0tm_leaf_colored(8T, 0tm_black), 8T) \
                      (0tm_is_tree(8T), \
                       8let((8L, 8ap(8E, 8K, 0tm_node_key(0tm_tree_node(8T))))(8G, 8ap(8E, 8K, 0tm_node_key(0tm_tree_node(8T)))), \
                            8cond((8and(8not(8or(8L, 8G)), 0tm_tree_colored(8T, 0tm_red), 0tm_leaf_colored(0tm_tree_left(8T), 0tm_black), 0tm_leaf_colored(0tm_tree_right(8T), 0tm_black)), \
                                   0tm_leaf(0tm_black)) \
                                  (8and(8not(8or(8L, 8G)), 0tm_tree_colored(8T, 0tm_black), 0tm_tree_colored(0tm_tree_left(8T), 0tm_red), 0tm_leaf_colored(0tm_tree_right(8T), 0tm_black)), \
                                   8apply(8fn(8_, 8A, 8X, 8B, \
                                              0tm_tree(0tm_black, 8A, 8X, 8B)), \
                                          0tm_tree_left(8T))) \
                                  (8and(8not(8or(8L, 8G)), 0tm_tree_colored(8T, 0tm_black), 0tm_leaf_colored(0tm_tree_left(8T), 0tm_black), 0tm_leaf_colored(0tm_tree_right(8T), 0tm_black)), \
                                   0tm_leaf(0tm_bblack)) \
                                  (8else, 8apply(8fn(8C, 8A, 8X, 8B, \
                                                     8cond((8L, 0tm_rotate(0tm_tree(8C, 0tm_delete_impl(8E, 8K, 8A), 8X, 8B))) \
                                                           (8G, 0tm_rotate(0tm_tree(8C, 8A, 8X, 0tm_delete_impl(8E, 8K, 8B)))) \
                                                           (8else, 8apply(8fn(8U, 8I, \
                                                                              0tm_rotate(0tm_tree(8C, 8A, 8U, 8I))), \
                                                                          0tm_min_delete(8B))))), \
                                                 8T))))) \
                      (8else, 8exit(8(called delete_impl on malformed tree))))))


#define ORDER_PP_DEF_0tm_delete \
ORDER_PP_FN(8fn(8E, 8K, 8T, \
                0tm_delete_impl(8E, 8K, 0tm_redden(8T))))


#define ORDER_PP_DEF_0tm_insert_impl \
ORDER_PP_FN(8fn(8E, 8X, 8T, \
                8if(0tm_is_leaf(8T), \
                    0tm_tree(0tm_red, 0tm_leaf(0tm_black), 8X, 0tm_leaf(0tm_black)), \
                    8apply(8fn(8C, 8L, 8Y, 8R, \
                               8cond((8ap(8E, 0tm_node_key(8X), 0tm_node_key(8Y)), 0tm_balance(0tm_tree(8C, 0tm_insert_impl(8E, 8X, 8L), 8Y, 8R))) \
                                     (8ap(8E, 0tm_node_key(8Y), 0tm_node_key(8X)), 0tm_balance(0tm_tree(8C, 8L, 8Y, 0tm_insert_impl(8E, 8X, 8R)))) \
                                     (8else, 0tm_tree(8C, 8L, 8X, 8R)))), \
                           8T))))

#define ORDER_PP_DEF_0tm_insert \
ORDER_PP_FN(8fn(8E, 8N, 8T, \
                0tm_make_tree_black(0tm_insert_impl(8E, 8N, 8T))))

#endif