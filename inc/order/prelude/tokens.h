// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE.)

#define ORDER_PP_DEF_8tokens_to_seq ORDER_PP_FN_CM(1,8TOKENS_TO_SEQ,0IS_ANY)
#define ORDER_PP_8TOKENS_TO_SEQ(P,ts,...) (,ORDER_PP_FX(PSEQ_TO_SEQ,(,ORDER_PP_FX(PSEQ_REVERSE,(,ORDER_PP_PM(,ORDER_PP_IS_EDIBLE(,P##ts)(ORDER_PP_TOKENS_TO_SEQ_,EDIBLE,INEDIBLE)(,P##ts,ORDER_PP_TOKEN),ORDER_PP_TOKEN,))))),P##__VA_ARGS__)

#define ORDER_PP_DEF_8tokens_to_seq_with ORDER_PP_FN_CM(2,8TOKENS_TO_SEQ_WITH,0IS_ANY,0IS_ANY)
#define ORDER_PP_8TOKENS_TO_SEQ_WITH(P,m,ts,...) (,ORDER_PP_FX(PSEQ_TO_SEQ,(,ORDER_PP_FX(PSEQ_REVERSE,(,ORDER_PP_PM(,ORDER_PP_IS_EDIBLE(,P##ts)(ORDER_PP_TOKENS_TO_SEQ_,EDIBLE,INEDIBLE)(,P##ts,P##m),P##m,))))),P##__VA_ARGS__)

#define ORDER_PP_8TOKENS_TO_SEQ_LOOP(P,x,ts,stop_nil,m,...) (,ORDER_PP_IS_EDIBLE(,P##ts)(ORDER_PP_TOKENS_TO_SEQ_,EDIBLE,INEDIBLE)(,P##ts,P##m),P##m,)(,P##x)

#define ORDER_PP_TOKENS_TO_SEQ_EDIBLE(P,ts,m) ORDER_PP_TOKENS_TO_SEQ_EDIBLE_TAKE ts##P,
#define ORDER_PP_TOKENS_TO_SEQ_EDIBLE_TAKE(x) (x),8TOKENS_TO_SEQ_LOOP,

#define ORDER_PP_TOKENS_TO_SEQ_INEDIBLE(P,ts,m) ORDER_PP_FX(TOKENS_TO_SEQ_INEDIBLE_TAKE,m##_##ts),8STOP_NIL
#define ORDER_PP_TOKENS_TO_SEQ_INEDIBLE_TAKE(x) x,8TOKENS_TO_SEQ_LOOP,

#define ORDER_PP_TOKEN ORDER_PP_TOKEN

#define ORDER_PP_TOKEN_0 (0)
#define ORDER_PP_TOKEN_1 (1)
#define ORDER_PP_TOKEN_2 (2)
#define ORDER_PP_TOKEN_3 (3)
#define ORDER_PP_TOKEN_4 (4)
#define ORDER_PP_TOKEN_5 (5)
#define ORDER_PP_TOKEN_6 (6)
#define ORDER_PP_TOKEN_7 (7)
#define ORDER_PP_TOKEN_8 (8)
#define ORDER_PP_TOKEN_9 (9)
