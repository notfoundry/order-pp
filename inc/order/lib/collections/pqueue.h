#ifndef ORDER_INC_ORDER_LIB_COLLECTIONS_PQUEUE_H
#define ORDER_INC_ORDER_LIB_COLLECTIONS_PQUEUE_H

// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

// First-order

#define ORDER_PP_DEF_8pqueue(cmp, ...) 8EVAL_PQUEUE,cmp,ORDER_PP_SEQ_AT_0 __VA_ARGS__(0pqueue_eval_terminate),
#define ORDER_PP_8EVAL_PQUEUE(P, env, q_cmp, q_head, tail, G, ...) \
                          (,P##env,ORDER_PP_DEF_##q_cmp,8EVAL_PQUEUE_LOOP,P##q_head,P##tail,,P##env,P##__VA_ARGS__)
#define ORDER_PP_8EVAL_PQUEUE_LOOP(P, cmp, q_head, tail, acc, env, ...) \
                               (,P##env,ORDER_PP_DEF_##q_head,8EVAL_PQUEUE_LOOP_B,P##tail,P##acc,P##cmp,P##env,P##__VA_ARGS__)
#define ORDER_PP_8EVAL_PQUEUE_LOOP_B(P, head, tail, acc, cmp, env, ...) \
                                 (,P##cmp,8EVAL_PQUEUE_LOOP,ORDER_PP_SEQ_AT_0 tail##P,P##acc(P##head),P##env,P##__VA_ARGS__)

#define ORDER_PP_DEF_0pqueue_eval_terminate 0EVAL_PQUEUE_TERMINATE,
#define ORDER_PP_0EVAL_PQUEUE_TERMINATE(P, env, G, _eval_pqueue_loop_b_, _tail_, _acc_, _cmp_, _env_,...) \
                                       (,P##_acc_, 8SEQ_MERGE_SORT, P##_cmp_, 0EVAL_PQUEUE_TERMINATE_B, P##_cmp_, P##__VA_ARGS__)
#define ORDER_PP_0EVAL_PQUEUE_TERMINATE_B(P, acc, cmp, ...) \
                                         (,(P##cmp,P##acc), P##__VA_ARGS__)


#define ORDER_PP_DEF_8pqueue_compare_fn ORDER_PP_FN_NATIVE(1,8PQUEUE_COMPARE_FN,0IS_PQUEUE)
#define ORDER_PP_8PQUEUE_COMPARE_FN(P, pqueue) ORDER_PP_FX(TUPLE_AT_0,(,ORDER_PP_REM P##pqueue,))


#define ORDER_PP_DEF_8pqueue_items ORDER_PP_FN_NATIVE(1,8PQUEUE_ITEMS,0IS_PQUEUE)
#define ORDER_PP_8PQUEUE_ITEMS(P, pqueue) ORDER_PP_FX(TUPLE_AT_1,(,ORDER_PP_REM P##pqueue,))


#define ORDER_PP_DEF_8pqueue_push \
ORDER_PP_FN(8fn(8E, 8Q, \
                0pqueue_reset(8seq_push_back(8E, 8pqueue_items(8Q)), 8Q)))


#define ORDER_PP_DEF_8pqueue_pop \
ORDER_PP_FN(8fn(8Q, \
                0pqueue_reset(8seq_pop_front(8pqueue_items(8Q)), 8Q)))


#define ORDER_PP_DEF_8pqueue_head ORDER_PP_FN(8fn(8Q, 8seq_head(8pqueue_items(8Q))))


#define ORDER_PP_DEF_8pqueue_is_nil ORDER_PP_FN(8fn(8Q, 8seq_is_nil(8pqueue_items(8Q))))


#define ORDER_PP_DEF_8pqueue_isnt_nil ORDER_PP_FN(8fn(8Q, 8not(8pqueue_is_nil(8Q))))


#define ORDER_PP_DEF_8is_pqueue ORDER_PP_FN_NATIVE(1,8IS_PQUEUE,0IS_ANY)
#define ORDER_PP_8IS_PQUEUE(P,x) ORDER_PP_0IS_PQUEUE(,P##x)(,8true,8false)

// Higher-order

// Detail
#define ORDER_PP_0IS_PQUEUE(P,x) ORDER_PP_0IS_TUPLE(,P##x)


#define ORDER_PP_DEF_0pqueue_reset \
ORDER_PP_FN(8fn(8I, 8Q, \
                8pair(8pqueue_compare_fn(8Q), 8seq_merge_sort(8pqueue_compare_fn(8Q), 8I))))

#endif
