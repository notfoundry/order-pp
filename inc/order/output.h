// (C) Copyright Vesa Karvonen 2004.
//
// Distributed under the Boost Software License, Version 1.0.

#define ORDER_PP_OUTPUT(s) ORDER_PP_OUTPUT_EMIT_A ORDER_PP_OUTPUT_SCAN(ORDER_PP_OUTPUT_REV_OUT_A(9,)s(9,)(0,))(0,0,)
#define ORDER_PP_OUTPUT_SCAN(x) x

#define ORDER_PP_OUTPUT_REV_OUT_A(P,...) ORDER_PP_OUTPUT_REV_OUT##P(,__VA_ARGS__##P)ORDER_PP_OUTPUT_REV_OUT_B##P
#define ORDER_PP_OUTPUT_REV_OUT_A0
#define ORDER_PP_OUTPUT_REV_OUT_A9 (,ORDER_PP_OUTPUT_REV_IN_B
#define ORDER_PP_OUTPUT_REV_OUT_B(P,...) ORDER_PP_OUTPUT_REV_OUT##P(,__VA_ARGS__##P)ORDER_PP_OUTPUT_REV_OUT_A##P
#define ORDER_PP_OUTPUT_REV_OUT_B0
#define ORDER_PP_OUTPUT_REV_OUT_B9 (,ORDER_PP_OUTPUT_REV_IN_A
#define ORDER_PP_OUTPUT_REV_OUT0(...)
#define ORDER_PP_OUTPUT_REV_OUT9(...) ORDER_PP_OUTPUT_REVERSE
#define ORDER_PP_OUTPUT_REV_OUT

#define ORDER_PP_OUTPUT_REV_IN_A(P,...) ORDER_PP_OUTPUT_REV_IN##P(,__VA_ARGS__##P)ORDER_PP_OUTPUT_REV_IN_B##P
#define ORDER_PP_OUTPUT_REV_IN_A0
#define ORDER_PP_OUTPUT_REV_IN_A9 )ORDER_PP_OUTPUT_REV_OUT_B
#define ORDER_PP_OUTPUT_REV_IN_B(P,...) ORDER_PP_OUTPUT_REV_IN##P(,__VA_ARGS__##P)ORDER_PP_OUTPUT_REV_IN_A##P
#define ORDER_PP_OUTPUT_REV_IN_B0
#define ORDER_PP_OUTPUT_REV_IN_B9 )ORDER_PP_OUTPUT_REV_OUT_A
#define ORDER_PP_OUTPUT_REV_IN0(...) ORDER_PP_ERROR_ODD_NUMBER_OF_OUTPUT_REVERSAL_TOGGLES(!)
#define ORDER_PP_OUTPUT_REV_IN9(...)
#define ORDER_PP_OUTPUT_REV_IN

#define ORDER_PP_ERROR_ODD_NUMBER_OF_OUTPUT_REVERSAL_TOGGLES()

#define ORDER_PP_OUTPUT_REVERSE(P,s) ORDER_PP_PM(ORDER_PP_OUTPUT_REV_PAIR_A P##s(0,),8OUTPUT_REV_EXIT)

#define ORDER_PP_8OUTPUT_REV_PAIR(P,s,...) (,ORDER_PP_OUTPUT_REV_PAIR_A P##s(0,),8OUTPUT_REV_SWAP,P##__VA_ARGS__)

#define ORDER_PP_OUTPUT_REV_PAIR_A(P,...) ORDER_PP_OUTPUT_REV_PAIR_B##P(,__VA_ARGS__##P)
#define ORDER_PP_OUTPUT_REV_PAIR_B(P,...) (,(,P##__VA_ARGS__),ORDER_PP_OUTPUT_REV_PAIR_C
#define ORDER_PP_OUTPUT_REV_PAIR_B0(...)
#define ORDER_PP_OUTPUT_REV_PAIR_C(P,...) ORDER_PP_OUTPUT_REV_PAIR_D##P(,__VA_ARGS__##P)
#define ORDER_PP_OUTPUT_REV_PAIR_D(P,...) (,P##__VA_ARGS__))ORDER_PP_OUTPUT_REV_PAIR_E
#define ORDER_PP_OUTPUT_REV_PAIR_D0(...) )
#define ORDER_PP_OUTPUT_REV_PAIR_E(P,...) ORDER_PP_OUTPUT_REV_PAIR_F##P(,__VA_ARGS__##P)
#define ORDER_PP_OUTPUT_REV_PAIR_F(P,...) (,(,P##__VA_ARGS__),ORDER_PP_OUTPUT_REV_PAIR_G
#define ORDER_PP_OUTPUT_REV_PAIR_F0(...)
#define ORDER_PP_OUTPUT_REV_PAIR_G(P,...) ORDER_PP_OUTPUT_REV_PAIR_H##P(,__VA_ARGS__##P)
#define ORDER_PP_OUTPUT_REV_PAIR_H(P,...) (,P##__VA_ARGS__))ORDER_PP_OUTPUT_REV_PAIR_I
#define ORDER_PP_OUTPUT_REV_PAIR_H0(...) ),8OUTPUT_REV_PAIR
#define ORDER_PP_OUTPUT_REV_PAIR_I(P,...) ORDER_PP_OUTPUT_REV_PAIR_J##P(,__VA_ARGS__##P)
#define ORDER_PP_OUTPUT_REV_PAIR_J(P,...) (,(,P##__VA_ARGS__),ORDER_PP_OUTPUT_REV_PAIR_G
#define ORDER_PP_OUTPUT_REV_PAIR_J0(...) ,8OUTPUT_REV_PAIR

#define ORDER_PP_8OUTPUT_REV_SWAP(P,s,...) (,ORDER_PP_SEQ_TERMINATE(ORDER_PP_OUTPUT_REV_SWAP_A P##s),P##__VA_ARGS__)
#define ORDER_PP_8OUTPUT_REV_EXIT(P,s,...) ,ORDER_PP_SEQ_TERMINATE(ORDER_PP_OUTPUT_REV_SWAP_A P##s))
#define ORDER_PP_OUTPUT_REV_SWAP_A(P,x,y) P##y P##x ORDER_PP_OUTPUT_REV_SWAP_B
#define ORDER_PP_OUTPUT_REV_SWAP_A0
#define ORDER_PP_OUTPUT_REV_SWAP_B(P,x,y) P##y P##x ORDER_PP_OUTPUT_REV_SWAP_A
#define ORDER_PP_OUTPUT_REV_SWAP_B0

#define ORDER_PP_OUTPUT_EMIT_A(P,m,...) ORDER_PP_OUTPUT_EMIT_##m(,P##__VA_ARGS__)ORDER_PP_OUTPUT_EMIT_B##P
#define ORDER_PP_OUTPUT_EMIT_A0
#define ORDER_PP_OUTPUT_EMIT_B(P,m,...) ORDER_PP_OUTPUT_EMIT_##m(,P##__VA_ARGS__)ORDER_PP_OUTPUT_EMIT_A##P
#define ORDER_PP_OUTPUT_EMIT_B0

#define ORDER_PP_OUTPUT_EMIT_0(...)
#define ORDER_PP_OUTPUT_EMIT_1(P,...) __VA_ARGS__##P
#define ORDER_PP_OUTPUT_EMIT_2(P,m,...) m##P ORDER_PP_NIL()P##__VA_ARGS__
#define ORDER_PP_OUTPUT_EMIT_3(P,...) ,__VA_ARGS__##P
#define ORDER_PP_OUTPUT_EMIT_4(P,...) (__VA_ARGS__##P
#define ORDER_PP_OUTPUT_EMIT_5(P,...) )__VA_ARGS__##P
