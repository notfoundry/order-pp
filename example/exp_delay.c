/* (C) Copyright Vesa Karvonen 2004.
 *
 *    Distributed under the Boost Software License, Version 1.0.
 */

#include "order/interpreter.h"

/*
 * The time complexity of exp_delay(N) is Omega(pow(2,N)).
 *
 * Handy when recompiles are too fast to take a coffee break. :)
 *
 * It should be very easy for a preprocessor to preprocess this example in
 * O(EXP_DELAY_MAX) space. Unfortunately, many preprocessors actually seem
 * to allocate lots of memory during macro expansion and also seem not to
 * release that memory until macro expansion is finished.
 */

#define ORDER_PP_DEF_exp_delay                  \
ORDER_PP_OP(fn(N,                               \
               unless(is_0(N),                  \
                      do(exp_delay(dec(N)),     \
                         exp_delay(dec(N))))))

#ifndef EXP_DELAY_MAX
#define EXP_DELAY_MAX 10
#endif

ORDER_PP(exp_delay(EXP_DELAY_MAX))