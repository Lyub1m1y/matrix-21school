#include "common.h"

START_TEST(test_s21_remove_matrix_1) {
  matrix_t matrix = {0};
  double **pmatrix = matrix.matrix;
  int rows = 3, columns = 7;
  s21_create_matrix(rows, columns, &matrix);
  s21_remove_matrix(&matrix);
  ck_assert_ptr_null(pmatrix);
}
END_TEST

TCase *tcase_matrix_s21_remove_matrix() {
  TCase *tcase = tcase_create("matrix_s21_remove_matrix");
  tcase_add_test(tcase, test_s21_remove_matrix_1);
  return tcase;
}
