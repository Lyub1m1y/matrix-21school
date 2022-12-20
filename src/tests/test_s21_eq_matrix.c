#include "common.h"

START_TEST(test_s21_eq_matrix_1) {
  matrix_t matrix_1 = {0};
  matrix_t matrix_2 = {0};
  matrix_1.rows = 2, matrix_1.columns = 3;
  matrix_2.rows = 3, matrix_2.columns = 3;
  s21_create_matrix(matrix_1.rows, matrix_1.columns, &matrix_1);
  s21_create_matrix(matrix_2.rows, matrix_2.columns, &matrix_2);
  ck_assert_int_eq(s21_eq_matrix(&matrix_1, &matrix_2), ERROR_CALC);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

START_TEST(test_s21_eq_matrix_2) {
  matrix_t matrix_1 = {0};
  matrix_t matrix_2 = {0};
  matrix_1.rows = 3, matrix_1.columns = 7;
  matrix_2.rows = 3, matrix_2.columns = 7;
  s21_create_matrix(matrix_1.rows, matrix_1.columns, &matrix_1);
  s21_create_matrix(matrix_2.rows, matrix_2.columns, &matrix_2);
  matrix_1.matrix[1][2] = 4.0000007;
  matrix_2.matrix[1][2] = 4.0000009;
  ck_assert_int_eq(s21_eq_matrix(&matrix_1, &matrix_2), FAILURE);
  s21_remove_matrix(&matrix_1);
  s21_remove_matrix(&matrix_2);
}
END_TEST

TCase *tcase_matrix_s21_eq_matrix() {
  TCase *tcase = tcase_create("matrix_s21_eq_matrix");
  tcase_add_test(tcase, test_s21_eq_matrix_1);
  tcase_add_test(tcase, test_s21_eq_matrix_2);
  return tcase;
}
