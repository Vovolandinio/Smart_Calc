#include <check.h>

#include "calculator.h"

#define EPS 1e-7
#define EPS2 1e-2

START_TEST(test_case_1) {
  char *input_str = "1+2*3";
  char result_str[200];
  double x_value = 0;
  int ex_code;
  ex_code = compute(input_str, result_str, x_value);
  ck_assert_int_eq(ex_code, 0);
  ck_assert_pstr_eq(result_str, "7.0000000");
}
END_TEST

START_TEST(test_case_2) {
  char *input_str = "2.0/(3.0+2.0)*5.0";
  char result_str[200];
  double x_value = 0;
  int ex_code;
  ex_code = compute(input_str, result_str, x_value);
  ck_assert_int_eq(ex_code, 0);
  ck_assert_pstr_eq(result_str, "2.0000000");
}
END_TEST

START_TEST(test_case_3) {
  char *input_str = "1+2+(3*4)+(5.1+6.8)";
  char result_str[200];
  double x_value = 0;
  int ex_code;
  ex_code = compute(input_str, result_str, x_value);
  ck_assert_int_eq(ex_code, 0);
  ck_assert_pstr_eq(result_str, "26.9000000");
}
END_TEST

START_TEST(test_case_4) {
  char *input_str = "10.0+10.0*10.0";
  char result_str[200];
  double x_value = 0;
  int ex_code;
  ex_code = compute(input_str, result_str, x_value);
  ck_assert_int_eq(ex_code, 0);
  ck_assert_pstr_eq(result_str, "110.0000000");
}
END_TEST

START_TEST(test_case_5) {
  char *input_str = "5.0mod3.0";
  char result_str[200];
  double x_value = 0;
  int ex_code;
  ex_code = compute(input_str, result_str, x_value);
  ck_assert_int_eq(ex_code, 0);
  ck_assert_pstr_eq(result_str, "2.0000000");
}
END_TEST

START_TEST(test_case_6) {
  char *input_str = "1.0/2.0*(2.0-1.0)";
  char result_str[200];
  double x_value = 0;
  int ex_code;
  ex_code = compute(input_str, result_str, x_value);
  ck_assert_int_eq(ex_code, 0);
  ck_assert_pstr_eq(result_str, "0.5000000");
}
END_TEST

START_TEST(test_case_7) {
  char *input_str = "(1-2-(0-3)-4)-5-(0-6)";
  char result_str[200];
  double x_value = 0;
  int ex_code;
  ex_code = compute(input_str, result_str, x_value);
  ck_assert_int_eq(ex_code, 0);
  ck_assert_pstr_eq(result_str, "-1.0000000");
}
END_TEST

START_TEST(test_case_8) {
  char *input_str = "(1+2)*((3-4)+1+(5-6+7))";
  char result_str[200];
  double x_value = 0;
  int ex_code;
  ex_code = compute(input_str, result_str, x_value);
  ck_assert_int_eq(ex_code, 0);
  ck_assert_pstr_eq(result_str, "18.0000000");
}
END_TEST

START_TEST(test_case_9) {
  char *input_str = "sqrt(4)-1/2*sin(3^2-2)";
  char result_str[200];
  double x_value = 0;
  int ex_code;
  ex_code = compute(input_str, result_str, x_value);
  ck_assert_int_eq(ex_code, 0);
  ck_assert_pstr_eq(result_str, "1.6715067");
}
END_TEST

START_TEST(test_case_10) {
  char *input_str = "sin(3)";
  char result_str[200];
  double x_value = 0;
  int ex_code;
  ex_code = compute(input_str, result_str, x_value);
  ck_assert_int_eq(ex_code, 0);
  ck_assert_pstr_eq(result_str, "0.1411200");
}
END_TEST

START_TEST(test_case_11) {
  char *input_str = "-1+8";
  char result_str[200];
  double x_value = 0;
  int ex_code;
  ex_code = compute(input_str, result_str, x_value);
  ck_assert_int_eq(ex_code, 0);
  ck_assert_pstr_eq(result_str, "7.0000000");
}
END_TEST

START_TEST(test_case_12) {
  char *input_str = "-5.0mod(-3.0)";
  char result_str[200];
  double x_value = 0;
  int ex_code;
  ex_code = compute(input_str, result_str, x_value);
  ck_assert_int_eq(ex_code, 0);
  ck_assert_pstr_eq(result_str, "-2.0000000");
}
END_TEST

START_TEST(test_case_13) {
  char *input_str = "4+4*2/(1-5)";
  char result_str[200];
  double x_value = 0;
  int ex_code;
  ex_code = compute(input_str, result_str, x_value);
  ck_assert_int_eq(ex_code, 0);
  ck_assert_pstr_eq(result_str, "2.0000000");
}
END_TEST

START_TEST(test_case_14) {
  char *input_str = "4+4*2/1-5";
  char result_str[200];
  double x_value = 0;
  int ex_code;
  ex_code = compute(input_str, result_str, x_value);
  ck_assert_int_eq(ex_code, 0);
  ck_assert_pstr_eq(result_str, "7.0000000");
}
END_TEST

START_TEST(test_case_15) {
  char *input_str = "4+4*(2/1-5)";
  char result_str[200];
  double x_value = 0;
  int ex_code;
  ex_code = compute(input_str, result_str, x_value);
  ck_assert_int_eq(ex_code, 0);
  ck_assert_pstr_eq(result_str, "-8.0000000");
}
END_TEST

START_TEST(test_case_16) {
  char *input_str = "4+(4*2/1-5)";
  char result_str[200];
  double x_value = 0;
  int ex_code;
  ex_code = compute(input_str, result_str, x_value);
  ck_assert_int_eq(ex_code, 0);
  ck_assert_pstr_eq(result_str, "7.0000000");
}
END_TEST

START_TEST(test_case_17) {
  char *input_str = "4+4*(2/1)-5";
  char result_str[200];
  double x_value = 0;
  int ex_code;
  ex_code = compute(input_str, result_str, x_value);
  ck_assert_int_eq(ex_code, 0);
  ck_assert_pstr_eq(result_str, "7.0000000");
}
END_TEST

START_TEST(test_case_18) {
  char *input_str = "4+(4*2/1)-5";
  char result_str[200];
  double x_value = 0;
  int ex_code;
  ex_code = compute(input_str, result_str, x_value);
  ck_assert_int_eq(ex_code, 0);
  ck_assert_pstr_eq(result_str, "7.0000000");
}
END_TEST

START_TEST(test_case_19) {
  char *input_str = "(4+4*2/1)-5";
  char result_str[200];
  double x_value = 0;
  int ex_code;
  ex_code = compute(input_str, result_str, x_value);
  ck_assert_int_eq(ex_code, 0);
  ck_assert_pstr_eq(result_str, "7.0000000");
}
END_TEST

START_TEST(test_case_20) {
  char *input_str = "4+(4*2)/1-5";
  char result_str[200];
  double x_value = 0;
  int ex_code;
  ex_code = compute(input_str, result_str, x_value);
  ck_assert_int_eq(ex_code, 0);
  ck_assert_pstr_eq(result_str, "7.0000000");
}
END_TEST

START_TEST(test_case_21) {
  char *input_str = "(4+4*2)/1-5";
  char result_str[200];
  double x_value = 0;
  int ex_code;
  ex_code = compute(input_str, result_str, x_value);
  ck_assert_int_eq(ex_code, 0);
  ck_assert_pstr_eq(result_str, "7.0000000");
}
END_TEST

START_TEST(test_case_22) {
  char *input_str = "8*(7+6*4)+3";
  char result_str[200];
  double x_value = 0;
  int ex_code;
  ex_code = compute(input_str, result_str, x_value);
  ck_assert_int_eq(ex_code, 0);
  ck_assert_pstr_eq(result_str, "251.0000000");
}
END_TEST

START_TEST(test_case_23) {
  char *input_str = "2/(3+2)*5";
  char result_str[200];
  double x_value = 0;
  int ex_code;
  ex_code = compute(input_str, result_str, x_value);
  ck_assert_int_eq(ex_code, 0);
  ck_assert_pstr_eq(result_str, "2.0000000");
}
END_TEST

START_TEST(test_case_24) {
  char *input_str = "2+9.3-8^3/4+56.2";
  char result_str[200];
  double x_value = 0;
  int ex_code;
  ex_code = compute(input_str, result_str, x_value);
  ck_assert_int_eq(ex_code, 0);
  ck_assert_pstr_eq(result_str, "-60.5000000");
}
END_TEST

START_TEST(test_case_25) {
  char *input_str = "2+9.3-8^3/(4+56.2)";
  char result_str[200];
  double x_value = 0;
  int ex_code;
  ex_code = compute(input_str, result_str, x_value);
  ck_assert_int_eq(ex_code, 0);
  ck_assert_pstr_eq(result_str, "2.7950166");
}
END_TEST

START_TEST(test_case_26) {
  char *input_str = "2^(3^2)";
  char result_str[200];
  double x_value = 0;
  int ex_code;
  ex_code = compute(input_str, result_str, x_value);
  ck_assert_int_eq(ex_code, 0);
  ck_assert_pstr_eq(result_str, "512.0000000");
}
END_TEST

START_TEST(test_case_27) {
  char *input_str = "(2^3)^2";
  char result_str[200];
  double x_value = 0;
  int ex_code;
  ex_code = compute(input_str, result_str, x_value);
  ck_assert_int_eq(ex_code, 0);
  ck_assert_pstr_eq(result_str, "64.0000000");
}
END_TEST

START_TEST(test_case_28) {
  char *input_str = "cos(431.2*2^2/8)";
  char result_str[200];
  double x_value = 0;
  int ex_code;
  ex_code = compute(input_str, result_str, x_value);
  ck_assert_int_eq(ex_code, 0);
  ck_assert_pstr_eq(result_str, "-0.3902501");
}
END_TEST

START_TEST(test_case_29) {
  char *input_str = "3*sin(4+5)";
  char result_str[200];
  double x_value = 0;
  int ex_code;
  ex_code = compute(input_str, result_str, x_value);
  ck_assert_int_eq(ex_code, 0);
  ck_assert_pstr_eq(result_str, "1.2363555");
}
END_TEST

START_TEST(test_case_30) {
  char *input_str = "3*sin(4+5)";
  char result_str[200];
  double x_value = 0;
  int ex_code;
  ex_code = compute(input_str, result_str, x_value);
  ck_assert_int_eq(ex_code, 0);
  ck_assert_pstr_eq(result_str, "1.2363555");
}
END_TEST

START_TEST(test_case_31) {
  char *input_str = "431.2*2^2/8";
  char result_str[200];
  double x_value = 0;
  int ex_code;
  ex_code = compute(input_str, result_str, x_value);
  ck_assert_int_eq(ex_code, 0);
  ck_assert_pstr_eq(result_str, "215.6000000");
}
END_TEST

START_TEST(test_case_32) {
  char *input_str = "cos(sin(2+9*6^1.2-tan(1)))";
  char result_str[200];
  double x_value = 0;
  int ex_code;
  ex_code = compute(input_str, result_str, x_value);
  ck_assert_int_eq(ex_code, 0);
  ck_assert_pstr_eq(result_str, "0.7421823");
}
END_TEST

START_TEST(test_case_33) {
  char *input_str = "sqrt(cos(sin(2+9*6^1.2-tan(1))))";
  char result_str[200];
  double x_value = 0;
  int ex_code;
  ex_code = compute(input_str, result_str, x_value);
  ck_assert_int_eq(ex_code, 0);
  ck_assert_pstr_eq(result_str, "0.8615000");
}
END_TEST

START_TEST(test_case_34) {
  char *input_str = "sqrt(cos(sin(2+9*6^1.2-tan(1))))mod0.1";
  char result_str[200];
  double x_value = 0;
  int ex_code;
  ex_code = compute(input_str, result_str, x_value);
  ck_assert_int_eq(ex_code, 0);
  ck_assert_pstr_eq(result_str, "0.0615000");
}
END_TEST

START_TEST(test_case_35) {
  char *input_str = "sqrt(2^2)*5/(4-3mod2)*(4-sqrt(81))";
  char result_str[200];
  double x_value = 0;
  int ex_code;
  ex_code = compute(input_str, result_str, x_value);
  ck_assert_int_eq(ex_code, 0);
  ck_assert_pstr_eq(result_str, "-16.6666667");
}
END_TEST

START_TEST(test_case_36) {
  char *input_str = "cos(1/3)*sin(1.352^9/(4+3))";
  char result_str[200];
  double x_value = 0;
  int ex_code;
  ex_code = compute(input_str, result_str, x_value);
  ck_assert_int_eq(ex_code, 0);
  ck_assert_pstr_eq(result_str, "0.7876032");
}
END_TEST

START_TEST(test_case_37) {
  char *input_str = "(cos(1/3)*sin(1.352^9/(4+3))/76.56)*log(150)";
  char result_str[200];
  double x_value = 0;
  int ex_code;
  ex_code = compute(input_str, result_str, x_value);
  ck_assert_int_eq(ex_code, 0);
  ck_assert_pstr_eq(result_str, "0.0223863");
}
END_TEST

START_TEST(test_case_38) {
  char *input_str = "2+(-(-(-(-1))))";
  char result_str[200];
  double x_value = 0;
  int ex_code;
  ex_code = compute(input_str, result_str, x_value);
  ck_assert_int_eq(ex_code, 0);
  ck_assert_pstr_eq(result_str, "3.0000000");
}
END_TEST

START_TEST(test_case_39) {
  char *input_str = "cos(6*3)/5";
  char result_str[200];
  double x_value = 0;
  int ex_code;
  ex_code = compute(input_str, result_str, x_value);
  ck_assert_int_eq(ex_code, 0);
  ck_assert_pstr_eq(result_str, "0.1320633");
}
END_TEST

START_TEST(test_case_40) {
  char *input_str = "cos(10*3)/5";
  char result_str[200];
  double x_value = 0;
  int ex_code;
  ex_code = compute(input_str, result_str, x_value);
  ck_assert_int_eq(ex_code, 0);
  ck_assert_pstr_eq(result_str, "0.0308503");
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("SmartCalc");
  TCase *smart_calc = tcase_create("SmartCalc");
  suite_add_tcase(s1, smart_calc);
  tcase_add_test(smart_calc, test_case_1);
  tcase_add_test(smart_calc, test_case_2);
  tcase_add_test(smart_calc, test_case_3);
  tcase_add_test(smart_calc, test_case_4);
  tcase_add_test(smart_calc, test_case_5);
  tcase_add_test(smart_calc, test_case_6);
  tcase_add_test(smart_calc, test_case_7);
  tcase_add_test(smart_calc, test_case_8);
  tcase_add_test(smart_calc, test_case_9);
  tcase_add_test(smart_calc, test_case_10);
  tcase_add_test(smart_calc, test_case_11);
  tcase_add_test(smart_calc, test_case_12);
  tcase_add_test(smart_calc, test_case_13);
  tcase_add_test(smart_calc, test_case_14);
  tcase_add_test(smart_calc, test_case_15);
  tcase_add_test(smart_calc, test_case_16);
  tcase_add_test(smart_calc, test_case_17);
  tcase_add_test(smart_calc, test_case_18);
  tcase_add_test(smart_calc, test_case_19);
  tcase_add_test(smart_calc, test_case_20);
  tcase_add_test(smart_calc, test_case_21);
  tcase_add_test(smart_calc, test_case_22);
  tcase_add_test(smart_calc, test_case_23);
  tcase_add_test(smart_calc, test_case_24);
  tcase_add_test(smart_calc, test_case_25);
  tcase_add_test(smart_calc, test_case_26);
  tcase_add_test(smart_calc, test_case_27);
  tcase_add_test(smart_calc, test_case_28);
  tcase_add_test(smart_calc, test_case_29);
  tcase_add_test(smart_calc, test_case_30);
  tcase_add_test(smart_calc, test_case_31);
  tcase_add_test(smart_calc, test_case_32);
  tcase_add_test(smart_calc, test_case_33);
  tcase_add_test(smart_calc, test_case_34);
  tcase_add_test(smart_calc, test_case_35);
  tcase_add_test(smart_calc, test_case_36);
  tcase_add_test(smart_calc, test_case_37);
  tcase_add_test(smart_calc, test_case_38);
  tcase_add_test(smart_calc, test_case_39);
  tcase_add_test(smart_calc, test_case_40);

  SRunner *sr = srunner_create(s1);
  int nf;
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);
  return nf == 0 ? 0 : 1;
}
