#include "common.h"

START_TEST(test_s21_determinant_1) {
  matrix_t result1;
  double result2;
  s21_create_matrix(3, 3, &result1);
  result1.matrix[0][0] = 1;
  result1.matrix[0][1] = 2;
  result1.matrix[0][2] = 3;

  result1.matrix[1][0] = 4;
  result1.matrix[1][1] = 5;
  result1.matrix[1][2] = 6;

  result1.matrix[2][0] = 7;
  result1.matrix[2][1] = 8;
  result1.matrix[2][2] = 9;
  double expected_result = 0;
  s21_determinant(&result1, &result2);
  ck_assert_ldouble_eq(expected_result, result2);
  s21_remove_matrix(&result1);
}
END_TEST

START_TEST(test_s21_determinant_2) {
  matrix_t result1;
  double result3;
  s21_create_matrix(3, 4, &result1);
  int actual_result = ERROR_CALC;
  int expected_result = s21_determinant(&result1, &result3);
  ck_assert_uint_eq(expected_result, actual_result);
  s21_remove_matrix(&result1);
}
END_TEST

START_TEST(test_s21_determinant_3) {
  matrix_t temp;
  double result;
  int result_defolt;
  s21_create_matrix(3, 2, &temp);
  s21_gen_matrix(&temp);
  result_defolt = s21_determinant(&temp, &result);
  ck_assert_int_eq(result_defolt, 2);
  s21_remove_matrix(&temp);
}
END_TEST

START_TEST(test_s21_determinant_4) {
  matrix_t temp;
  double result;
  int result_defolt;
  s21_create_matrix(3, 3, &temp);
  temp.matrix[0][0] = 0;
  temp.matrix[0][1] = 9;
  temp.matrix[0][2] = 5;

  temp.matrix[1][0] = 4;
  temp.matrix[1][1] = 3;
  temp.matrix[1][2] = -5;

  temp.matrix[2][0] = -1;
  temp.matrix[2][1] = 6;
  temp.matrix[2][2] = -4;
  result_defolt = s21_determinant(&temp, &result);
  ck_assert_int_eq(result_defolt, 0);
  ck_assert_uint_eq(result, 324);
  s21_remove_matrix(&temp);
}
END_TEST

START_TEST(test_s21_determinant_5) {
  matrix_t temp;
  double result;
  int result_defolt;
  s21_create_matrix(3, 3, &temp);
  temp.matrix[0][0] = 1;
  temp.matrix[1][1] = 1;
  temp.matrix[2][2] = 1;

  result_defolt = s21_determinant(&temp, &result);
  ck_assert_int_eq(result_defolt, 0);
  ck_assert_uint_eq(result, 1);
  s21_remove_matrix(&temp);
}
END_TEST

TCase *tcase_matrix_s21_determinant() {
  TCase *tcase = tcase_create("matrix_s21_determinant");
  tcase_add_test(tcase, test_s21_determinant_1);
  tcase_add_test(tcase, test_s21_determinant_2);
  tcase_add_test(tcase, test_s21_determinant_3);
  tcase_add_test(tcase, test_s21_determinant_4);
  tcase_add_test(tcase, test_s21_determinant_5);
  return tcase;
}
