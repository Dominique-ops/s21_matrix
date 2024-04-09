#ifndef TEST_H
#define TEST_H

#include <check.h>

#include "s21_matrix.h"
Suite *suite_s21_eq(void);
Suite *suite_s21_sum(void);
Suite *suite_s21_sub(void);
Suite *suite_s21_mult_num(void);
Suite *suite_s21_mult_matrix(void);
Suite *suite_s21_trans_matrix(void);
Suite *suite_s21_calc_matrix(void);
Suite *suite_det_matrix(void);
Suite *suite_inv_matrix(void);
void run_tests(void);
void run_testcase(Suite *testcase);
#endif