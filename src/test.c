#include "test.h"

START_TEST(eq_1) {
  matrix_t A, B;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 4;
  ck_assert_int_eq(s21_eq_matrix(&A, &B), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_2) {
  matrix_t A, B;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 3, &B);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 4;
  ck_assert_int_eq(s21_eq_matrix(&A, &B), 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(eq_3) {
  matrix_t A, B;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  B.matrix[0][0] = 4;
  B.matrix[0][1] = 4;
  B.matrix[1][0] = 4;
  B.matrix[1][1] = 4;
  ck_assert_int_eq(s21_eq_matrix(&A, &B), 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

Suite *suite_s21_eq(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("\033[35m====-{s21_equal}-====\033[0m");
  tc = tcase_create("s21_equal_case");
  tcase_add_test(tc, eq_1);
  tcase_add_test(tc, eq_2);
  tcase_add_test(tc, eq_3);
  suite_add_tcase(s, tc);
  return s;
}

START_TEST(sum_1) {
  matrix_t A, B, RES, CHECK;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  s21_create_matrix(2, 2, &CHECK);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 4;
  s21_sum_matrix(&A, &B, &RES);
  CHECK.matrix[0][0] = 2;
  CHECK.matrix[0][1] = 4;
  CHECK.matrix[1][0] = 6;
  CHECK.matrix[1][1] = 8;
  ck_assert_int_eq(s21_eq_matrix(&RES, &CHECK), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&CHECK);
  s21_remove_matrix(&RES);
}
END_TEST

START_TEST(sum_2) {
  matrix_t A, B, RES, CHECK;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 3, &B);
  s21_create_matrix(2, 2, &CHECK);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 4;
  s21_sum_matrix(&A, &B, &RES);
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &RES), 2);
  CHECK.matrix[0][0] = 2;
  CHECK.matrix[0][1] = 4;
  CHECK.matrix[1][0] = 6;
  CHECK.matrix[1][1] = 8;
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&CHECK);
}
END_TEST

Suite *suite_s21_sum(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("\033[35m====-{s21_sum}-====\033[0m");
  tc = tcase_create("s21_sum_case");
  tcase_add_test(tc, sum_1);
  tcase_add_test(tc, sum_2);
  suite_add_tcase(s, tc);
  return s;
}

START_TEST(sub_1) {
  matrix_t A, B, RES, CHECK;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &B);
  s21_create_matrix(2, 2, &CHECK);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  B.matrix[0][0] = 1;
  B.matrix[0][1] = 2;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 4;
  s21_sub_matrix(&A, &B, &RES);
  CHECK.matrix[0][0] = 0;
  CHECK.matrix[0][1] = 0;
  CHECK.matrix[1][0] = 0;
  CHECK.matrix[1][1] = 0;
  ck_assert_int_eq(s21_eq_matrix(&RES, &CHECK), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&CHECK);
  s21_remove_matrix(&RES);
}
END_TEST

Suite *suite_s21_sub(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("\033[35m====-{s21_sub}-====\033[0m");
  tc = tcase_create("s21_sub_case");
  tcase_add_test(tc, sub_1);
  suite_add_tcase(s, tc);
  return s;
}

START_TEST(mult_num_1) {
  matrix_t A, RES, CHECK;
  double num = 2.3;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &CHECK);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  s21_mult_number(&A, num, &RES);
  CHECK.matrix[0][0] = 2.3;
  CHECK.matrix[0][1] = 4.6;
  CHECK.matrix[1][0] = 6.9;
  CHECK.matrix[1][1] = 9.2;
  ck_assert_int_eq(s21_eq_matrix(&RES, &CHECK), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&CHECK);
  s21_remove_matrix(&RES);
}
END_TEST

Suite *suite_s21_mult_num(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("\033[35m====-{s21_mult_num}-====\033[0m");
  tc = tcase_create("s21_mult_num_case");
  tcase_add_test(tc, mult_num_1);
  suite_add_tcase(s, tc);
  return s;
}

START_TEST(mul_1) {
  matrix_t A, B, RES, CHECK;
  s21_create_matrix(1, 2, &A);
  s21_create_matrix(2, 1, &B);
  s21_create_matrix(1, 1, &CHECK);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  B.matrix[0][0] = 3;
  B.matrix[1][0] = 4;
  s21_mult_matrix(&A, &B, &RES);
  CHECK.matrix[0][0] = 11;
  ck_assert_int_eq(s21_eq_matrix(&RES, &CHECK), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&CHECK);
  s21_remove_matrix(&RES);
}
END_TEST

START_TEST(mul_2) {
  matrix_t A, B, RES, CHECK;
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(2, 1, &B);
  s21_create_matrix(1, 1, &CHECK);
  A.matrix[0][0] = 1;
  B.matrix[0][0] = 3;
  B.matrix[1][0] = 4;
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &RES), 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&CHECK);
}
END_TEST

START_TEST(mul_3) {
  matrix_t A, B, RES, CHECK;
  s21_create_matrix(1, 2, &A);
  s21_create_matrix(2, 2, &B);
  s21_create_matrix(1, 2, &CHECK);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  B.matrix[0][0] = 3;
  B.matrix[0][1] = 4;
  B.matrix[1][0] = 3;
  B.matrix[1][1] = 4;
  s21_mult_matrix(&A, &B, &RES);
  CHECK.matrix[0][0] = 9;
  CHECK.matrix[0][1] = 12;
  ck_assert_int_eq(s21_eq_matrix(&RES, &CHECK), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&CHECK);
  s21_remove_matrix(&RES);
}
END_TEST

Suite *suite_s21_mult_matrix(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("\033[35m====-{s21_mult_matrix}-====\033[0m");
  tc = tcase_create("s21_mult_matrix_case");
  tcase_add_test(tc, mul_1);
  tcase_add_test(tc, mul_2);
  tcase_add_test(tc, mul_3);
  suite_add_tcase(s, tc);
  return s;
}

START_TEST(trans_1) {
  matrix_t A, RES, CHECK;
  s21_create_matrix(1, 2, &A);
  s21_create_matrix(2, 1, &CHECK);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  s21_transpose(&A, &RES);
  CHECK.matrix[0][0] = 1;
  CHECK.matrix[1][0] = 2;
  ck_assert_int_eq(s21_eq_matrix(&RES, &CHECK), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&CHECK);
  s21_remove_matrix(&RES);
}
END_TEST

START_TEST(trans_2) {
  matrix_t A, RES, CHECK;
  s21_create_matrix(2, 2, &A);
  s21_create_matrix(2, 2, &CHECK);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[1][0] = 1;
  A.matrix[1][1] = 2;
  s21_transpose(&A, &RES);
  CHECK.matrix[0][0] = 1;
  CHECK.matrix[0][1] = 1;
  CHECK.matrix[1][0] = 2;
  CHECK.matrix[1][1] = 2;
  ck_assert_int_eq(s21_eq_matrix(&RES, &CHECK), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&CHECK);
  s21_remove_matrix(&RES);
}
END_TEST

Suite *suite_s21_trans_matrix(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("\033[35m====-{s21_trans_matrix}-====\033[0m");
  tc = tcase_create("s21_trans_matrix_case");
  tcase_add_test(tc, trans_1);
  tcase_add_test(tc, trans_2);
  suite_add_tcase(s, tc);
  return s;
}

START_TEST(calc_comp_1) {
  matrix_t A, RES, CHECK;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &CHECK);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 4;
  A.matrix[1][2] = 2;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = 2;
  A.matrix[2][2] = 1;
  s21_calc_complements(&A, &RES);
  CHECK.matrix[0][0] = 0;
  CHECK.matrix[0][1] = 10;
  CHECK.matrix[0][2] = -20;
  CHECK.matrix[1][0] = 4;
  CHECK.matrix[1][1] = -14;
  CHECK.matrix[1][2] = 8;
  CHECK.matrix[2][0] = -8;
  CHECK.matrix[2][1] = -2;
  CHECK.matrix[2][2] = 4;
  ck_assert_int_eq(s21_eq_matrix(&RES, &CHECK), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&CHECK);
  s21_remove_matrix(&RES);
}
END_TEST

START_TEST(calc_comp_2) {
  matrix_t A, RES, CHECK;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &CHECK);
  A.matrix[0][0] = 12;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 5;
  A.matrix[1][1] = 7;
  A.matrix[1][2] = 8;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 5;
  A.matrix[2][2] = 4;
  s21_calc_complements(&A, &RES);
  CHECK.matrix[0][0] = -12;
  CHECK.matrix[0][1] = -20;
  CHECK.matrix[0][2] = 25;
  CHECK.matrix[1][0] = 7;
  CHECK.matrix[1][1] = 48;
  CHECK.matrix[1][2] = -60;
  CHECK.matrix[2][0] = -5;
  CHECK.matrix[2][1] = -81;
  CHECK.matrix[2][2] = 74;
  ck_assert_int_eq(s21_eq_matrix(&RES, &CHECK), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&CHECK);
  s21_remove_matrix(&RES);
}
END_TEST

Suite *suite_s21_calc_matrix(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("\033[35m====-{s21_calc_matrix}-====\033[0m");
  tc = tcase_create("s21_calc_matrix_case");
  tcase_add_test(tc, calc_comp_1);
  tcase_add_test(tc, calc_comp_2);
  suite_add_tcase(s, tc);
  return s;
}

START_TEST(det_1) {
  matrix_t A;
  double res;
  double check = 0;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 2;
  A.matrix[0][2] = 3;
  A.matrix[1][0] = 4;
  A.matrix[1][1] = 5;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 7;
  A.matrix[2][1] = 8;
  A.matrix[2][2] = 9;
  s21_determinant(&A, &res);
  ck_assert_double_eq(res, check);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(det_2) {
  matrix_t A;
  double res;
  double check = -965641;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 3;
  A.matrix[0][2] = 2;
  A.matrix[1][0] = 123;
  A.matrix[1][1] = 2;
  A.matrix[1][2] = 321;
  A.matrix[2][0] = 213;
  A.matrix[2][1] = 312;
  A.matrix[2][2] = 3124;
  s21_determinant(&A, &res);
  ck_assert_double_eq(res, check);
  s21_remove_matrix(&A);
}
END_TEST

Suite *suite_det_matrix(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("\033[35m====-{s21_det_matrix}-====\033[0m");
  tc = tcase_create("s21_det_case");
  tcase_add_test(tc, det_1);
  tcase_add_test(tc, det_2);
  suite_add_tcase(s, tc);
  return s;
}

START_TEST(inv_1) {
  matrix_t A, RES, CHECK;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &CHECK);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;
  s21_inverse_matrix(&A, &RES);
  CHECK.matrix[0][0] = 1;
  CHECK.matrix[0][1] = -1;
  CHECK.matrix[0][2] = 1;
  CHECK.matrix[1][0] = -38;
  CHECK.matrix[1][1] = 41;
  CHECK.matrix[1][2] = -34;
  CHECK.matrix[2][0] = 27;
  CHECK.matrix[2][1] = -29;
  CHECK.matrix[2][2] = 24;
  ck_assert_int_eq(s21_eq_matrix(&RES, &CHECK), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&CHECK);
  s21_remove_matrix(&RES);
}
END_TEST

START_TEST(inv_2) {
  matrix_t A, RES, CHECK;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &CHECK);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 3;
  A.matrix[0][2] = 4;
  A.matrix[1][0] = 5;
  A.matrix[1][1] = 2;
  A.matrix[1][2] = 13;
  A.matrix[2][0] = 9;
  A.matrix[2][1] = 7;
  A.matrix[2][2] = 2;
  s21_inverse_matrix(&A, &RES);
  CHECK.matrix[0][0] = -87.0 / 302;
  CHECK.matrix[0][1] = 11.0 / 151;
  CHECK.matrix[0][2] = 31.0 / 302;
  CHECK.matrix[1][0] = 107.0 / 302;
  CHECK.matrix[1][1] = -17.0 / 151;
  CHECK.matrix[1][2] = 7.0 / 302;
  CHECK.matrix[2][0] = 17.0 / 302;
  CHECK.matrix[2][1] = 10.0 / 151;
  CHECK.matrix[2][2] = -13.0 / 302;
  ck_assert_int_eq(s21_eq_matrix(&RES, &CHECK), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&CHECK);
  s21_remove_matrix(&RES);
}
END_TEST

START_TEST(inv_3) {
  matrix_t A, RES, CHECK;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &CHECK);
  A.matrix[0][0] = 0;
  A.matrix[0][1] = 3;
  A.matrix[0][2] = 4;
  A.matrix[1][0] = 5;
  A.matrix[1][1] = 0;
  A.matrix[1][2] = 13;
  A.matrix[2][0] = 9;
  A.matrix[2][1] = 7;
  A.matrix[2][2] = 0;
  s21_inverse_matrix(&A, &RES);
  CHECK.matrix[0][0] = -87.0 / 302;
  CHECK.matrix[0][1] = 11.0 / 151;
  CHECK.matrix[0][2] = 31.0 / 302;
  CHECK.matrix[1][0] = 107.0 / 302;
  CHECK.matrix[1][1] = -17.0 / 151;
  CHECK.matrix[1][2] = 7.0 / 302;
  CHECK.matrix[2][0] = 17.0 / 302;
  CHECK.matrix[2][1] = 10.0 / 151;
  CHECK.matrix[2][2] = -13.0 / 302;
  ck_assert_int_eq(s21_eq_matrix(&RES, &CHECK), 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&CHECK);
  s21_remove_matrix(&RES);
}
END_TEST

START_TEST(inv_4) {
  matrix_t A, RES, CHECK;
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &CHECK);
  A.matrix[0][0] = 2;

  s21_inverse_matrix(&A, &RES);
  CHECK.matrix[0][0] = 0.5;
  ck_assert_int_eq(s21_eq_matrix(&RES, &CHECK), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&CHECK);
  s21_remove_matrix(&RES);
}
END_TEST

Suite *suite_inv_matrix(void) {
  Suite *s;
  TCase *tc;
  s = suite_create("\033[35m====-{s21_inv_matrix}-====\033[0m");
  tc = tcase_create("s21_inv_case");
  tcase_add_test(tc, inv_1);
  tcase_add_test(tc, inv_2);
  tcase_add_test(tc, inv_3);
  tcase_add_test(tc, inv_4);
  suite_add_tcase(s, tc);
  return s;
}