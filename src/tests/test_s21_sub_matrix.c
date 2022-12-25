#include "common.h"

START_TEST(test_s21_sub_matrix_1) {
  matrix_t temp;
  matrix_t temp2;
  matrix_t result;
  matrix_t result_defolt;
  s21_create_matrix(3, 3, &temp);
  s21_create_matrix(3, 3, &temp2);
  s21_create_matrix(3, 3, &result_defolt);
  s21_gen_matrix(&temp);
  s21_anti_gen_matrix(&temp2);
  for (int i = 0; (i < temp.rows); i++) {
    for (int j = 0; j < temp.columns; j++) {
      result_defolt.matrix[i][j] = temp.matrix[i][j] - temp2.matrix[i][j];
    }
  }
  ck_assert_int_eq(s21_sub_matrix(&temp, &temp2, &result), 0);
  ck_assert_int_eq(s21_eq_matrix(&result_defolt, &result), 1);
  s21_remove_matrix(&temp);
  s21_remove_matrix(&temp2);
  s21_remove_matrix(&result);
  s21_remove_matrix(&result_defolt);
}
END_TEST

START_TEST(test_s21_sub_matrix_2) {
  matrix_t temp;
  matrix_t temp2;
  matrix_t result;
  s21_create_matrix(3, 3, &temp);
  s21_create_matrix(3, 3, &temp2);
  s21_gen_matrix(&temp);
  s21_gen_matrix(&temp2);
  ck_assert_int_eq(s21_sub_matrix(&temp, &temp2, &result), 0);
  s21_remove_matrix(&temp);
  s21_remove_matrix(&temp2);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_sub_matrix_3) {
  matrix_t temp;
  matrix_t temp2;
  matrix_t result;
  s21_create_matrix(3, 1, &temp);
  s21_create_matrix(3, 3, &temp2);
  s21_gen_matrix(&temp);
  s21_gen_matrix(&temp2);
  ck_assert_int_eq(s21_sub_matrix(&temp, &temp2, &result), ERROR_CALC);
  s21_remove_matrix(&temp);
  s21_remove_matrix(&temp2);
}
END_TEST

TCase *tcase_matrix_s21_sub_matrix() {
  TCase *tcase = tcase_create("matrix_s21_sub_matrix");
  tcase_add_test(tcase, test_s21_sub_matrix_1);
  tcase_add_test(tcase, test_s21_sub_matrix_2);
  tcase_add_test(tcase, test_s21_sub_matrix_3);
  return tcase;
}
