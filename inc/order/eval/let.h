// (C) Copyright Vesa Karvonen 2004.
//
//    Distributed under the Boost Software License, Version 1.0.

#define ORDER_PP_DEF_8let(...) 8EVAL_LET,__VA_ARGS__,

#define ORDER_PP_8EVAL_LET(P,e,s,i,b,G,...) (,P##e,ORDER_PP_DEF_##i,8EVAL_LET_B,P##s,P##e,P##b,P##__VA_ARGS__)
#define ORDER_PP_8EVAL_LET_B(P,v,s,e,...) (,(,P##s,P##v)P##e,ORDER_PP_DEF_##__VA_ARGS__)
