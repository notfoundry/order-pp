#ifndef ORDER_CM_H
#define ORDER_CM_H

/* (C) Copyright Vesa Karvonen 2004.
 *
 *    Distributed under the Boost Software License, Version 1.0.
 */

#define ORDER_CM(...) ORDER_CM_B(ORDER_CM_UP_0(__VA_ARGS__))
#define ORDER_CM_B(x) ORDER_CM_C(,x
#define ORDER_CM_C(P,_,x) P##x

#define ORDER_CM_8STOP(P,x,...) ,P##x)

/*
(let ((max 30))
  (loop for i from 0 to max do
    (let ((is (number-to-string i))
          (1+is (number-to-string (1+ i))))
      (insert "#define ORDER_CM_D_" is "(...) ORDER_CM_DN_" is " __VA_ARGS__\n")
      (insert "#define ORDER_CM_U_" is "(...) ORDER_CM_UP_" 1+is " __VA_ARGS__\n")))
  (insert "\n")

  (insert "#ifndef ORDER_CM_TRACE_ON\n")

  (insert "# define ORDER_CM_DN_0(P,x,f,...) ORDER_CM_##f(,P##x,P##__VA_ARGS__)\n")
  (loop for i from 0 to max do
    (let ((is (number-to-string i))
          (1+is (number-to-string (1+ i)))
          (1-is (number-to-string (1- i))))
        (when (< 0 i)
          (insert "# define ORDER_CM_DN_" is "(P,x,f,...) ORDER_CM_D_" 1-is "(ORDER_CM_D_" 1-is "(ORDER_CM_##f(,P##x,P##__VA_ARGS__)))\n"))
        (insert "# define ORDER_CM_UP_" is "(P,x,f,...) ORDER_CM_U_" is "(ORDER_CM_U_" is "(ORDER_CM_D_" is "(ORDER_CM_##f(,P##x,P##__VA_ARGS__))))\n")))
  (insert "# define ORDER_CM_UP_" (number-to-string (1+ max)) "(P,x,f,...) ORDER_CM_##f(,P##x,P##__VA_ARGS__)\n")

  (insert "#else\n")

  (insert "# define ORDER_CM_DN_0(P,x,f,...) ORDER_CM_##f(,P##x,P##__VA_ARGS__)\\(,P##x,P##f,P##__VA_ARGS__)\n")
  (loop for i from 0 to max do
    (let ((is (number-to-string i))
          (1+is (number-to-string (1+ i)))
          (1-is (number-to-string (1- i))))
      (when (< 0 i)
        (insert "# define ORDER_CM_DN_" is "(P,x,f,...) ORDER_CM_D_" 1-is "(ORDER_CM_D_" 1-is "(ORDER_CM_##f(,P##x,P##__VA_ARGS__)))\\(,P##x,P##f,P##__VA_ARGS__)\n"))
      (insert "# define ORDER_CM_UP_" is "(P,x,f,...) ORDER_CM_U_" is "(ORDER_CM_U_" is "(ORDER_CM_D_" is "(ORDER_CM_##f(,P##x,P##__VA_ARGS__))))\\(,P##x,P##f,P##__VA_ARGS__)\n")))
  (insert "# define ORDER_CM_UP_" (number-to-string (1+ max)) "(P,x,f,...) ORDER_CM_##f(,P##x,P##__VA_ARGS__)\\(,P##x,P##f,P##__VA_ARGS__)\n")

  (insert "#endif\n"))
 */

#define ORDER_CM_D_0(...) ORDER_CM_DN_0 __VA_ARGS__
#define ORDER_CM_U_0(...) ORDER_CM_UP_1 __VA_ARGS__
#define ORDER_CM_D_1(...) ORDER_CM_DN_1 __VA_ARGS__
#define ORDER_CM_U_1(...) ORDER_CM_UP_2 __VA_ARGS__
#define ORDER_CM_D_2(...) ORDER_CM_DN_2 __VA_ARGS__
#define ORDER_CM_U_2(...) ORDER_CM_UP_3 __VA_ARGS__
#define ORDER_CM_D_3(...) ORDER_CM_DN_3 __VA_ARGS__
#define ORDER_CM_U_3(...) ORDER_CM_UP_4 __VA_ARGS__
#define ORDER_CM_D_4(...) ORDER_CM_DN_4 __VA_ARGS__
#define ORDER_CM_U_4(...) ORDER_CM_UP_5 __VA_ARGS__
#define ORDER_CM_D_5(...) ORDER_CM_DN_5 __VA_ARGS__
#define ORDER_CM_U_5(...) ORDER_CM_UP_6 __VA_ARGS__
#define ORDER_CM_D_6(...) ORDER_CM_DN_6 __VA_ARGS__
#define ORDER_CM_U_6(...) ORDER_CM_UP_7 __VA_ARGS__
#define ORDER_CM_D_7(...) ORDER_CM_DN_7 __VA_ARGS__
#define ORDER_CM_U_7(...) ORDER_CM_UP_8 __VA_ARGS__
#define ORDER_CM_D_8(...) ORDER_CM_DN_8 __VA_ARGS__
#define ORDER_CM_U_8(...) ORDER_CM_UP_9 __VA_ARGS__
#define ORDER_CM_D_9(...) ORDER_CM_DN_9 __VA_ARGS__
#define ORDER_CM_U_9(...) ORDER_CM_UP_10 __VA_ARGS__
#define ORDER_CM_D_10(...) ORDER_CM_DN_10 __VA_ARGS__
#define ORDER_CM_U_10(...) ORDER_CM_UP_11 __VA_ARGS__
#define ORDER_CM_D_11(...) ORDER_CM_DN_11 __VA_ARGS__
#define ORDER_CM_U_11(...) ORDER_CM_UP_12 __VA_ARGS__
#define ORDER_CM_D_12(...) ORDER_CM_DN_12 __VA_ARGS__
#define ORDER_CM_U_12(...) ORDER_CM_UP_13 __VA_ARGS__
#define ORDER_CM_D_13(...) ORDER_CM_DN_13 __VA_ARGS__
#define ORDER_CM_U_13(...) ORDER_CM_UP_14 __VA_ARGS__
#define ORDER_CM_D_14(...) ORDER_CM_DN_14 __VA_ARGS__
#define ORDER_CM_U_14(...) ORDER_CM_UP_15 __VA_ARGS__
#define ORDER_CM_D_15(...) ORDER_CM_DN_15 __VA_ARGS__
#define ORDER_CM_U_15(...) ORDER_CM_UP_16 __VA_ARGS__
#define ORDER_CM_D_16(...) ORDER_CM_DN_16 __VA_ARGS__
#define ORDER_CM_U_16(...) ORDER_CM_UP_17 __VA_ARGS__
#define ORDER_CM_D_17(...) ORDER_CM_DN_17 __VA_ARGS__
#define ORDER_CM_U_17(...) ORDER_CM_UP_18 __VA_ARGS__
#define ORDER_CM_D_18(...) ORDER_CM_DN_18 __VA_ARGS__
#define ORDER_CM_U_18(...) ORDER_CM_UP_19 __VA_ARGS__
#define ORDER_CM_D_19(...) ORDER_CM_DN_19 __VA_ARGS__
#define ORDER_CM_U_19(...) ORDER_CM_UP_20 __VA_ARGS__
#define ORDER_CM_D_20(...) ORDER_CM_DN_20 __VA_ARGS__
#define ORDER_CM_U_20(...) ORDER_CM_UP_21 __VA_ARGS__
#define ORDER_CM_D_21(...) ORDER_CM_DN_21 __VA_ARGS__
#define ORDER_CM_U_21(...) ORDER_CM_UP_22 __VA_ARGS__
#define ORDER_CM_D_22(...) ORDER_CM_DN_22 __VA_ARGS__
#define ORDER_CM_U_22(...) ORDER_CM_UP_23 __VA_ARGS__
#define ORDER_CM_D_23(...) ORDER_CM_DN_23 __VA_ARGS__
#define ORDER_CM_U_23(...) ORDER_CM_UP_24 __VA_ARGS__
#define ORDER_CM_D_24(...) ORDER_CM_DN_24 __VA_ARGS__
#define ORDER_CM_U_24(...) ORDER_CM_UP_25 __VA_ARGS__
#define ORDER_CM_D_25(...) ORDER_CM_DN_25 __VA_ARGS__
#define ORDER_CM_U_25(...) ORDER_CM_UP_26 __VA_ARGS__
#define ORDER_CM_D_26(...) ORDER_CM_DN_26 __VA_ARGS__
#define ORDER_CM_U_26(...) ORDER_CM_UP_27 __VA_ARGS__
#define ORDER_CM_D_27(...) ORDER_CM_DN_27 __VA_ARGS__
#define ORDER_CM_U_27(...) ORDER_CM_UP_28 __VA_ARGS__
#define ORDER_CM_D_28(...) ORDER_CM_DN_28 __VA_ARGS__
#define ORDER_CM_U_28(...) ORDER_CM_UP_29 __VA_ARGS__
#define ORDER_CM_D_29(...) ORDER_CM_DN_29 __VA_ARGS__
#define ORDER_CM_U_29(...) ORDER_CM_UP_30 __VA_ARGS__
#define ORDER_CM_D_30(...) ORDER_CM_DN_30 __VA_ARGS__
#define ORDER_CM_U_30(...) ORDER_CM_UP_31 __VA_ARGS__

#ifndef ORDER_CM_TRACE_ON
# define ORDER_CM_DN_0(P,x,f,...) ORDER_CM_##f(,P##x,P##__VA_ARGS__)
# define ORDER_CM_UP_0(P,x,f,...) ORDER_CM_U_0(ORDER_CM_U_0(ORDER_CM_D_0(ORDER_CM_##f(,P##x,P##__VA_ARGS__))))
# define ORDER_CM_DN_1(P,x,f,...) ORDER_CM_D_0(ORDER_CM_D_0(ORDER_CM_##f(,P##x,P##__VA_ARGS__)))
# define ORDER_CM_UP_1(P,x,f,...) ORDER_CM_U_1(ORDER_CM_U_1(ORDER_CM_D_1(ORDER_CM_##f(,P##x,P##__VA_ARGS__))))
# define ORDER_CM_DN_2(P,x,f,...) ORDER_CM_D_1(ORDER_CM_D_1(ORDER_CM_##f(,P##x,P##__VA_ARGS__)))
# define ORDER_CM_UP_2(P,x,f,...) ORDER_CM_U_2(ORDER_CM_U_2(ORDER_CM_D_2(ORDER_CM_##f(,P##x,P##__VA_ARGS__))))
# define ORDER_CM_DN_3(P,x,f,...) ORDER_CM_D_2(ORDER_CM_D_2(ORDER_CM_##f(,P##x,P##__VA_ARGS__)))
# define ORDER_CM_UP_3(P,x,f,...) ORDER_CM_U_3(ORDER_CM_U_3(ORDER_CM_D_3(ORDER_CM_##f(,P##x,P##__VA_ARGS__))))
# define ORDER_CM_DN_4(P,x,f,...) ORDER_CM_D_3(ORDER_CM_D_3(ORDER_CM_##f(,P##x,P##__VA_ARGS__)))
# define ORDER_CM_UP_4(P,x,f,...) ORDER_CM_U_4(ORDER_CM_U_4(ORDER_CM_D_4(ORDER_CM_##f(,P##x,P##__VA_ARGS__))))
# define ORDER_CM_DN_5(P,x,f,...) ORDER_CM_D_4(ORDER_CM_D_4(ORDER_CM_##f(,P##x,P##__VA_ARGS__)))
# define ORDER_CM_UP_5(P,x,f,...) ORDER_CM_U_5(ORDER_CM_U_5(ORDER_CM_D_5(ORDER_CM_##f(,P##x,P##__VA_ARGS__))))
# define ORDER_CM_DN_6(P,x,f,...) ORDER_CM_D_5(ORDER_CM_D_5(ORDER_CM_##f(,P##x,P##__VA_ARGS__)))
# define ORDER_CM_UP_6(P,x,f,...) ORDER_CM_U_6(ORDER_CM_U_6(ORDER_CM_D_6(ORDER_CM_##f(,P##x,P##__VA_ARGS__))))
# define ORDER_CM_DN_7(P,x,f,...) ORDER_CM_D_6(ORDER_CM_D_6(ORDER_CM_##f(,P##x,P##__VA_ARGS__)))
# define ORDER_CM_UP_7(P,x,f,...) ORDER_CM_U_7(ORDER_CM_U_7(ORDER_CM_D_7(ORDER_CM_##f(,P##x,P##__VA_ARGS__))))
# define ORDER_CM_DN_8(P,x,f,...) ORDER_CM_D_7(ORDER_CM_D_7(ORDER_CM_##f(,P##x,P##__VA_ARGS__)))
# define ORDER_CM_UP_8(P,x,f,...) ORDER_CM_U_8(ORDER_CM_U_8(ORDER_CM_D_8(ORDER_CM_##f(,P##x,P##__VA_ARGS__))))
# define ORDER_CM_DN_9(P,x,f,...) ORDER_CM_D_8(ORDER_CM_D_8(ORDER_CM_##f(,P##x,P##__VA_ARGS__)))
# define ORDER_CM_UP_9(P,x,f,...) ORDER_CM_U_9(ORDER_CM_U_9(ORDER_CM_D_9(ORDER_CM_##f(,P##x,P##__VA_ARGS__))))
# define ORDER_CM_DN_10(P,x,f,...) ORDER_CM_D_9(ORDER_CM_D_9(ORDER_CM_##f(,P##x,P##__VA_ARGS__)))
# define ORDER_CM_UP_10(P,x,f,...) ORDER_CM_U_10(ORDER_CM_U_10(ORDER_CM_D_10(ORDER_CM_##f(,P##x,P##__VA_ARGS__))))
# define ORDER_CM_DN_11(P,x,f,...) ORDER_CM_D_10(ORDER_CM_D_10(ORDER_CM_##f(,P##x,P##__VA_ARGS__)))
# define ORDER_CM_UP_11(P,x,f,...) ORDER_CM_U_11(ORDER_CM_U_11(ORDER_CM_D_11(ORDER_CM_##f(,P##x,P##__VA_ARGS__))))
# define ORDER_CM_DN_12(P,x,f,...) ORDER_CM_D_11(ORDER_CM_D_11(ORDER_CM_##f(,P##x,P##__VA_ARGS__)))
# define ORDER_CM_UP_12(P,x,f,...) ORDER_CM_U_12(ORDER_CM_U_12(ORDER_CM_D_12(ORDER_CM_##f(,P##x,P##__VA_ARGS__))))
# define ORDER_CM_DN_13(P,x,f,...) ORDER_CM_D_12(ORDER_CM_D_12(ORDER_CM_##f(,P##x,P##__VA_ARGS__)))
# define ORDER_CM_UP_13(P,x,f,...) ORDER_CM_U_13(ORDER_CM_U_13(ORDER_CM_D_13(ORDER_CM_##f(,P##x,P##__VA_ARGS__))))
# define ORDER_CM_DN_14(P,x,f,...) ORDER_CM_D_13(ORDER_CM_D_13(ORDER_CM_##f(,P##x,P##__VA_ARGS__)))
# define ORDER_CM_UP_14(P,x,f,...) ORDER_CM_U_14(ORDER_CM_U_14(ORDER_CM_D_14(ORDER_CM_##f(,P##x,P##__VA_ARGS__))))
# define ORDER_CM_DN_15(P,x,f,...) ORDER_CM_D_14(ORDER_CM_D_14(ORDER_CM_##f(,P##x,P##__VA_ARGS__)))
# define ORDER_CM_UP_15(P,x,f,...) ORDER_CM_U_15(ORDER_CM_U_15(ORDER_CM_D_15(ORDER_CM_##f(,P##x,P##__VA_ARGS__))))
# define ORDER_CM_DN_16(P,x,f,...) ORDER_CM_D_15(ORDER_CM_D_15(ORDER_CM_##f(,P##x,P##__VA_ARGS__)))
# define ORDER_CM_UP_16(P,x,f,...) ORDER_CM_U_16(ORDER_CM_U_16(ORDER_CM_D_16(ORDER_CM_##f(,P##x,P##__VA_ARGS__))))
# define ORDER_CM_DN_17(P,x,f,...) ORDER_CM_D_16(ORDER_CM_D_16(ORDER_CM_##f(,P##x,P##__VA_ARGS__)))
# define ORDER_CM_UP_17(P,x,f,...) ORDER_CM_U_17(ORDER_CM_U_17(ORDER_CM_D_17(ORDER_CM_##f(,P##x,P##__VA_ARGS__))))
# define ORDER_CM_DN_18(P,x,f,...) ORDER_CM_D_17(ORDER_CM_D_17(ORDER_CM_##f(,P##x,P##__VA_ARGS__)))
# define ORDER_CM_UP_18(P,x,f,...) ORDER_CM_U_18(ORDER_CM_U_18(ORDER_CM_D_18(ORDER_CM_##f(,P##x,P##__VA_ARGS__))))
# define ORDER_CM_DN_19(P,x,f,...) ORDER_CM_D_18(ORDER_CM_D_18(ORDER_CM_##f(,P##x,P##__VA_ARGS__)))
# define ORDER_CM_UP_19(P,x,f,...) ORDER_CM_U_19(ORDER_CM_U_19(ORDER_CM_D_19(ORDER_CM_##f(,P##x,P##__VA_ARGS__))))
# define ORDER_CM_DN_20(P,x,f,...) ORDER_CM_D_19(ORDER_CM_D_19(ORDER_CM_##f(,P##x,P##__VA_ARGS__)))
# define ORDER_CM_UP_20(P,x,f,...) ORDER_CM_U_20(ORDER_CM_U_20(ORDER_CM_D_20(ORDER_CM_##f(,P##x,P##__VA_ARGS__))))
# define ORDER_CM_DN_21(P,x,f,...) ORDER_CM_D_20(ORDER_CM_D_20(ORDER_CM_##f(,P##x,P##__VA_ARGS__)))
# define ORDER_CM_UP_21(P,x,f,...) ORDER_CM_U_21(ORDER_CM_U_21(ORDER_CM_D_21(ORDER_CM_##f(,P##x,P##__VA_ARGS__))))
# define ORDER_CM_DN_22(P,x,f,...) ORDER_CM_D_21(ORDER_CM_D_21(ORDER_CM_##f(,P##x,P##__VA_ARGS__)))
# define ORDER_CM_UP_22(P,x,f,...) ORDER_CM_U_22(ORDER_CM_U_22(ORDER_CM_D_22(ORDER_CM_##f(,P##x,P##__VA_ARGS__))))
# define ORDER_CM_DN_23(P,x,f,...) ORDER_CM_D_22(ORDER_CM_D_22(ORDER_CM_##f(,P##x,P##__VA_ARGS__)))
# define ORDER_CM_UP_23(P,x,f,...) ORDER_CM_U_23(ORDER_CM_U_23(ORDER_CM_D_23(ORDER_CM_##f(,P##x,P##__VA_ARGS__))))
# define ORDER_CM_DN_24(P,x,f,...) ORDER_CM_D_23(ORDER_CM_D_23(ORDER_CM_##f(,P##x,P##__VA_ARGS__)))
# define ORDER_CM_UP_24(P,x,f,...) ORDER_CM_U_24(ORDER_CM_U_24(ORDER_CM_D_24(ORDER_CM_##f(,P##x,P##__VA_ARGS__))))
# define ORDER_CM_DN_25(P,x,f,...) ORDER_CM_D_24(ORDER_CM_D_24(ORDER_CM_##f(,P##x,P##__VA_ARGS__)))
# define ORDER_CM_UP_25(P,x,f,...) ORDER_CM_U_25(ORDER_CM_U_25(ORDER_CM_D_25(ORDER_CM_##f(,P##x,P##__VA_ARGS__))))
# define ORDER_CM_DN_26(P,x,f,...) ORDER_CM_D_25(ORDER_CM_D_25(ORDER_CM_##f(,P##x,P##__VA_ARGS__)))
# define ORDER_CM_UP_26(P,x,f,...) ORDER_CM_U_26(ORDER_CM_U_26(ORDER_CM_D_26(ORDER_CM_##f(,P##x,P##__VA_ARGS__))))
# define ORDER_CM_DN_27(P,x,f,...) ORDER_CM_D_26(ORDER_CM_D_26(ORDER_CM_##f(,P##x,P##__VA_ARGS__)))
# define ORDER_CM_UP_27(P,x,f,...) ORDER_CM_U_27(ORDER_CM_U_27(ORDER_CM_D_27(ORDER_CM_##f(,P##x,P##__VA_ARGS__))))
# define ORDER_CM_DN_28(P,x,f,...) ORDER_CM_D_27(ORDER_CM_D_27(ORDER_CM_##f(,P##x,P##__VA_ARGS__)))
# define ORDER_CM_UP_28(P,x,f,...) ORDER_CM_U_28(ORDER_CM_U_28(ORDER_CM_D_28(ORDER_CM_##f(,P##x,P##__VA_ARGS__))))
# define ORDER_CM_DN_29(P,x,f,...) ORDER_CM_D_28(ORDER_CM_D_28(ORDER_CM_##f(,P##x,P##__VA_ARGS__)))
# define ORDER_CM_UP_29(P,x,f,...) ORDER_CM_U_29(ORDER_CM_U_29(ORDER_CM_D_29(ORDER_CM_##f(,P##x,P##__VA_ARGS__))))
# define ORDER_CM_DN_30(P,x,f,...) ORDER_CM_D_29(ORDER_CM_D_29(ORDER_CM_##f(,P##x,P##__VA_ARGS__)))
# define ORDER_CM_UP_30(P,x,f,...) ORDER_CM_U_30(ORDER_CM_U_30(ORDER_CM_D_30(ORDER_CM_##f(,P##x,P##__VA_ARGS__))))
# define ORDER_CM_UP_31(P,x,f,...) ORDER_CM_##f(,P##x,P##__VA_ARGS__)
#else
# define ORDER_CM_DN_0(P,x,f,...) ORDER_CM_##f(,P##x,P##__VA_ARGS__)\(,P##x,P##f,P##__VA_ARGS__)
# define ORDER_CM_UP_0(P,x,f,...) ORDER_CM_U_0(ORDER_CM_U_0(ORDER_CM_D_0(ORDER_CM_##f(,P##x,P##__VA_ARGS__))))\(,P##x,P##f,P##__VA_ARGS__)
# define ORDER_CM_DN_1(P,x,f,...) ORDER_CM_D_0(ORDER_CM_D_0(ORDER_CM_##f(,P##x,P##__VA_ARGS__)))\(,P##x,P##f,P##__VA_ARGS__)
# define ORDER_CM_UP_1(P,x,f,...) ORDER_CM_U_1(ORDER_CM_U_1(ORDER_CM_D_1(ORDER_CM_##f(,P##x,P##__VA_ARGS__))))\(,P##x,P##f,P##__VA_ARGS__)
# define ORDER_CM_DN_2(P,x,f,...) ORDER_CM_D_1(ORDER_CM_D_1(ORDER_CM_##f(,P##x,P##__VA_ARGS__)))\(,P##x,P##f,P##__VA_ARGS__)
# define ORDER_CM_UP_2(P,x,f,...) ORDER_CM_U_2(ORDER_CM_U_2(ORDER_CM_D_2(ORDER_CM_##f(,P##x,P##__VA_ARGS__))))\(,P##x,P##f,P##__VA_ARGS__)
# define ORDER_CM_DN_3(P,x,f,...) ORDER_CM_D_2(ORDER_CM_D_2(ORDER_CM_##f(,P##x,P##__VA_ARGS__)))\(,P##x,P##f,P##__VA_ARGS__)
# define ORDER_CM_UP_3(P,x,f,...) ORDER_CM_U_3(ORDER_CM_U_3(ORDER_CM_D_3(ORDER_CM_##f(,P##x,P##__VA_ARGS__))))\(,P##x,P##f,P##__VA_ARGS__)
# define ORDER_CM_DN_4(P,x,f,...) ORDER_CM_D_3(ORDER_CM_D_3(ORDER_CM_##f(,P##x,P##__VA_ARGS__)))\(,P##x,P##f,P##__VA_ARGS__)
# define ORDER_CM_UP_4(P,x,f,...) ORDER_CM_U_4(ORDER_CM_U_4(ORDER_CM_D_4(ORDER_CM_##f(,P##x,P##__VA_ARGS__))))\(,P##x,P##f,P##__VA_ARGS__)
# define ORDER_CM_DN_5(P,x,f,...) ORDER_CM_D_4(ORDER_CM_D_4(ORDER_CM_##f(,P##x,P##__VA_ARGS__)))\(,P##x,P##f,P##__VA_ARGS__)
# define ORDER_CM_UP_5(P,x,f,...) ORDER_CM_U_5(ORDER_CM_U_5(ORDER_CM_D_5(ORDER_CM_##f(,P##x,P##__VA_ARGS__))))\(,P##x,P##f,P##__VA_ARGS__)
# define ORDER_CM_DN_6(P,x,f,...) ORDER_CM_D_5(ORDER_CM_D_5(ORDER_CM_##f(,P##x,P##__VA_ARGS__)))\(,P##x,P##f,P##__VA_ARGS__)
# define ORDER_CM_UP_6(P,x,f,...) ORDER_CM_U_6(ORDER_CM_U_6(ORDER_CM_D_6(ORDER_CM_##f(,P##x,P##__VA_ARGS__))))\(,P##x,P##f,P##__VA_ARGS__)
# define ORDER_CM_DN_7(P,x,f,...) ORDER_CM_D_6(ORDER_CM_D_6(ORDER_CM_##f(,P##x,P##__VA_ARGS__)))\(,P##x,P##f,P##__VA_ARGS__)
# define ORDER_CM_UP_7(P,x,f,...) ORDER_CM_U_7(ORDER_CM_U_7(ORDER_CM_D_7(ORDER_CM_##f(,P##x,P##__VA_ARGS__))))\(,P##x,P##f,P##__VA_ARGS__)
# define ORDER_CM_DN_8(P,x,f,...) ORDER_CM_D_7(ORDER_CM_D_7(ORDER_CM_##f(,P##x,P##__VA_ARGS__)))\(,P##x,P##f,P##__VA_ARGS__)
# define ORDER_CM_UP_8(P,x,f,...) ORDER_CM_U_8(ORDER_CM_U_8(ORDER_CM_D_8(ORDER_CM_##f(,P##x,P##__VA_ARGS__))))\(,P##x,P##f,P##__VA_ARGS__)
# define ORDER_CM_DN_9(P,x,f,...) ORDER_CM_D_8(ORDER_CM_D_8(ORDER_CM_##f(,P##x,P##__VA_ARGS__)))\(,P##x,P##f,P##__VA_ARGS__)
# define ORDER_CM_UP_9(P,x,f,...) ORDER_CM_U_9(ORDER_CM_U_9(ORDER_CM_D_9(ORDER_CM_##f(,P##x,P##__VA_ARGS__))))\(,P##x,P##f,P##__VA_ARGS__)
# define ORDER_CM_DN_10(P,x,f,...) ORDER_CM_D_9(ORDER_CM_D_9(ORDER_CM_##f(,P##x,P##__VA_ARGS__)))\(,P##x,P##f,P##__VA_ARGS__)
# define ORDER_CM_UP_10(P,x,f,...) ORDER_CM_U_10(ORDER_CM_U_10(ORDER_CM_D_10(ORDER_CM_##f(,P##x,P##__VA_ARGS__))))\(,P##x,P##f,P##__VA_ARGS__)
# define ORDER_CM_DN_11(P,x,f,...) ORDER_CM_D_10(ORDER_CM_D_10(ORDER_CM_##f(,P##x,P##__VA_ARGS__)))\(,P##x,P##f,P##__VA_ARGS__)
# define ORDER_CM_UP_11(P,x,f,...) ORDER_CM_U_11(ORDER_CM_U_11(ORDER_CM_D_11(ORDER_CM_##f(,P##x,P##__VA_ARGS__))))\(,P##x,P##f,P##__VA_ARGS__)
# define ORDER_CM_DN_12(P,x,f,...) ORDER_CM_D_11(ORDER_CM_D_11(ORDER_CM_##f(,P##x,P##__VA_ARGS__)))\(,P##x,P##f,P##__VA_ARGS__)
# define ORDER_CM_UP_12(P,x,f,...) ORDER_CM_U_12(ORDER_CM_U_12(ORDER_CM_D_12(ORDER_CM_##f(,P##x,P##__VA_ARGS__))))\(,P##x,P##f,P##__VA_ARGS__)
# define ORDER_CM_DN_13(P,x,f,...) ORDER_CM_D_12(ORDER_CM_D_12(ORDER_CM_##f(,P##x,P##__VA_ARGS__)))\(,P##x,P##f,P##__VA_ARGS__)
# define ORDER_CM_UP_13(P,x,f,...) ORDER_CM_U_13(ORDER_CM_U_13(ORDER_CM_D_13(ORDER_CM_##f(,P##x,P##__VA_ARGS__))))\(,P##x,P##f,P##__VA_ARGS__)
# define ORDER_CM_DN_14(P,x,f,...) ORDER_CM_D_13(ORDER_CM_D_13(ORDER_CM_##f(,P##x,P##__VA_ARGS__)))\(,P##x,P##f,P##__VA_ARGS__)
# define ORDER_CM_UP_14(P,x,f,...) ORDER_CM_U_14(ORDER_CM_U_14(ORDER_CM_D_14(ORDER_CM_##f(,P##x,P##__VA_ARGS__))))\(,P##x,P##f,P##__VA_ARGS__)
# define ORDER_CM_DN_15(P,x,f,...) ORDER_CM_D_14(ORDER_CM_D_14(ORDER_CM_##f(,P##x,P##__VA_ARGS__)))\(,P##x,P##f,P##__VA_ARGS__)
# define ORDER_CM_UP_15(P,x,f,...) ORDER_CM_U_15(ORDER_CM_U_15(ORDER_CM_D_15(ORDER_CM_##f(,P##x,P##__VA_ARGS__))))\(,P##x,P##f,P##__VA_ARGS__)
# define ORDER_CM_DN_16(P,x,f,...) ORDER_CM_D_15(ORDER_CM_D_15(ORDER_CM_##f(,P##x,P##__VA_ARGS__)))\(,P##x,P##f,P##__VA_ARGS__)
# define ORDER_CM_UP_16(P,x,f,...) ORDER_CM_U_16(ORDER_CM_U_16(ORDER_CM_D_16(ORDER_CM_##f(,P##x,P##__VA_ARGS__))))\(,P##x,P##f,P##__VA_ARGS__)
# define ORDER_CM_DN_17(P,x,f,...) ORDER_CM_D_16(ORDER_CM_D_16(ORDER_CM_##f(,P##x,P##__VA_ARGS__)))\(,P##x,P##f,P##__VA_ARGS__)
# define ORDER_CM_UP_17(P,x,f,...) ORDER_CM_U_17(ORDER_CM_U_17(ORDER_CM_D_17(ORDER_CM_##f(,P##x,P##__VA_ARGS__))))\(,P##x,P##f,P##__VA_ARGS__)
# define ORDER_CM_DN_18(P,x,f,...) ORDER_CM_D_17(ORDER_CM_D_17(ORDER_CM_##f(,P##x,P##__VA_ARGS__)))\(,P##x,P##f,P##__VA_ARGS__)
# define ORDER_CM_UP_18(P,x,f,...) ORDER_CM_U_18(ORDER_CM_U_18(ORDER_CM_D_18(ORDER_CM_##f(,P##x,P##__VA_ARGS__))))\(,P##x,P##f,P##__VA_ARGS__)
# define ORDER_CM_DN_19(P,x,f,...) ORDER_CM_D_18(ORDER_CM_D_18(ORDER_CM_##f(,P##x,P##__VA_ARGS__)))\(,P##x,P##f,P##__VA_ARGS__)
# define ORDER_CM_UP_19(P,x,f,...) ORDER_CM_U_19(ORDER_CM_U_19(ORDER_CM_D_19(ORDER_CM_##f(,P##x,P##__VA_ARGS__))))\(,P##x,P##f,P##__VA_ARGS__)
# define ORDER_CM_DN_20(P,x,f,...) ORDER_CM_D_19(ORDER_CM_D_19(ORDER_CM_##f(,P##x,P##__VA_ARGS__)))\(,P##x,P##f,P##__VA_ARGS__)
# define ORDER_CM_UP_20(P,x,f,...) ORDER_CM_U_20(ORDER_CM_U_20(ORDER_CM_D_20(ORDER_CM_##f(,P##x,P##__VA_ARGS__))))\(,P##x,P##f,P##__VA_ARGS__)
# define ORDER_CM_DN_21(P,x,f,...) ORDER_CM_D_20(ORDER_CM_D_20(ORDER_CM_##f(,P##x,P##__VA_ARGS__)))\(,P##x,P##f,P##__VA_ARGS__)
# define ORDER_CM_UP_21(P,x,f,...) ORDER_CM_U_21(ORDER_CM_U_21(ORDER_CM_D_21(ORDER_CM_##f(,P##x,P##__VA_ARGS__))))\(,P##x,P##f,P##__VA_ARGS__)
# define ORDER_CM_DN_22(P,x,f,...) ORDER_CM_D_21(ORDER_CM_D_21(ORDER_CM_##f(,P##x,P##__VA_ARGS__)))\(,P##x,P##f,P##__VA_ARGS__)
# define ORDER_CM_UP_22(P,x,f,...) ORDER_CM_U_22(ORDER_CM_U_22(ORDER_CM_D_22(ORDER_CM_##f(,P##x,P##__VA_ARGS__))))\(,P##x,P##f,P##__VA_ARGS__)
# define ORDER_CM_DN_23(P,x,f,...) ORDER_CM_D_22(ORDER_CM_D_22(ORDER_CM_##f(,P##x,P##__VA_ARGS__)))\(,P##x,P##f,P##__VA_ARGS__)
# define ORDER_CM_UP_23(P,x,f,...) ORDER_CM_U_23(ORDER_CM_U_23(ORDER_CM_D_23(ORDER_CM_##f(,P##x,P##__VA_ARGS__))))\(,P##x,P##f,P##__VA_ARGS__)
# define ORDER_CM_DN_24(P,x,f,...) ORDER_CM_D_23(ORDER_CM_D_23(ORDER_CM_##f(,P##x,P##__VA_ARGS__)))\(,P##x,P##f,P##__VA_ARGS__)
# define ORDER_CM_UP_24(P,x,f,...) ORDER_CM_U_24(ORDER_CM_U_24(ORDER_CM_D_24(ORDER_CM_##f(,P##x,P##__VA_ARGS__))))\(,P##x,P##f,P##__VA_ARGS__)
# define ORDER_CM_DN_25(P,x,f,...) ORDER_CM_D_24(ORDER_CM_D_24(ORDER_CM_##f(,P##x,P##__VA_ARGS__)))\(,P##x,P##f,P##__VA_ARGS__)
# define ORDER_CM_UP_25(P,x,f,...) ORDER_CM_U_25(ORDER_CM_U_25(ORDER_CM_D_25(ORDER_CM_##f(,P##x,P##__VA_ARGS__))))\(,P##x,P##f,P##__VA_ARGS__)
# define ORDER_CM_DN_26(P,x,f,...) ORDER_CM_D_25(ORDER_CM_D_25(ORDER_CM_##f(,P##x,P##__VA_ARGS__)))\(,P##x,P##f,P##__VA_ARGS__)
# define ORDER_CM_UP_26(P,x,f,...) ORDER_CM_U_26(ORDER_CM_U_26(ORDER_CM_D_26(ORDER_CM_##f(,P##x,P##__VA_ARGS__))))\(,P##x,P##f,P##__VA_ARGS__)
# define ORDER_CM_DN_27(P,x,f,...) ORDER_CM_D_26(ORDER_CM_D_26(ORDER_CM_##f(,P##x,P##__VA_ARGS__)))\(,P##x,P##f,P##__VA_ARGS__)
# define ORDER_CM_UP_27(P,x,f,...) ORDER_CM_U_27(ORDER_CM_U_27(ORDER_CM_D_27(ORDER_CM_##f(,P##x,P##__VA_ARGS__))))\(,P##x,P##f,P##__VA_ARGS__)
# define ORDER_CM_DN_28(P,x,f,...) ORDER_CM_D_27(ORDER_CM_D_27(ORDER_CM_##f(,P##x,P##__VA_ARGS__)))\(,P##x,P##f,P##__VA_ARGS__)
# define ORDER_CM_UP_28(P,x,f,...) ORDER_CM_U_28(ORDER_CM_U_28(ORDER_CM_D_28(ORDER_CM_##f(,P##x,P##__VA_ARGS__))))\(,P##x,P##f,P##__VA_ARGS__)
# define ORDER_CM_DN_29(P,x,f,...) ORDER_CM_D_28(ORDER_CM_D_28(ORDER_CM_##f(,P##x,P##__VA_ARGS__)))\(,P##x,P##f,P##__VA_ARGS__)
# define ORDER_CM_UP_29(P,x,f,...) ORDER_CM_U_29(ORDER_CM_U_29(ORDER_CM_D_29(ORDER_CM_##f(,P##x,P##__VA_ARGS__))))\(,P##x,P##f,P##__VA_ARGS__)
# define ORDER_CM_DN_30(P,x,f,...) ORDER_CM_D_29(ORDER_CM_D_29(ORDER_CM_##f(,P##x,P##__VA_ARGS__)))\(,P##x,P##f,P##__VA_ARGS__)
# define ORDER_CM_UP_30(P,x,f,...) ORDER_CM_U_30(ORDER_CM_U_30(ORDER_CM_D_30(ORDER_CM_##f(,P##x,P##__VA_ARGS__))))\(,P##x,P##f,P##__VA_ARGS__)
# define ORDER_CM_UP_31(P,x,f,...) ORDER_CM_##f(,P##x,P##__VA_ARGS__)\(,P##x,P##f,P##__VA_ARGS__)
#endif

#endif