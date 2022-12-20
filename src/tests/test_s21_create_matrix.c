#include "common.h"

START_TEST(test_s21_create_matrix_1) {
  matrix_t *matrix = NULL;
  int row = 5, columns = 5;
  ck_assert_int_eq(s21_create_matrix(row, columns, matrix), ERROR);
}
END_TEST

START_TEST(test_s21_create_matrix_2) {
  matrix_t matrix = {0};
  int rows = 5, columns = 5;
  ck_assert_int_eq(s21_create_matrix(rows, columns, &matrix), OK);
  for (int i = 0; i < rows; i++) {
    free(matrix.matrix[i]);
  }
  free(matrix.matrix);
}
END_TEST

TCase *tcase_matrix_s21_create_matrix() {
  TCase *tcase = tcase_create("matrix_s21_create_matrix");
  tcase_add_test(tcase, test_s21_create_matrix_1);
  tcase_add_test(tcase, test_s21_create_matrix_2);
  return tcase;
}
