#include "common.h"

START_TEST(test_s21_calc_complements_1) {
  matrix_t test, result;
  s21_create_matrix(3, 2, &test);
  int result_status;
  s21_gen_matrix(&test);
  result_status = s21_calc_complements(&test, &result);
  ck_assert_int_eq(result_status, 2);
  s21_remove_matrix(&test);
}
END_TEST

START_TEST(test_s21_calc_complements_2) {
  matrix_t test, result;
  s21_create_matrix(3, 3, &test);
  s21_gen_matrix(&test);
  int result_status = s21_calc_complements(&test, &result);
  ck_assert_int_eq(result_status, 0);
  s21_remove_matrix(&test);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(test_s21_calc_complements_3) {
  matrix_t test, test_2, result;
  s21_create_matrix(3, 3, &test);
  test.matrix[0][0] = 1;
  test.matrix[0][1] = 2;
  test.matrix[0][2] = 3;
  test.matrix[1][0] = 0;
  test.matrix[1][1] = 4;
  test.matrix[1][2] = 2;
  test.matrix[2][0] = 5;
  test.matrix[2][1] = 2;
  test.matrix[2][2] = 1;
  s21_calc_complements(&test, &result);
  s21_create_matrix(3, 3, &test_2);
  test_2.matrix[0][0] = 0;
  test_2.matrix[0][1] = 10;
  test_2.matrix[0][2] = -20;
  test_2.matrix[1][0] = 4;
  test_2.matrix[1][1] = -14;
  test_2.matrix[1][2] = 8;
  test_2.matrix[2][0] = -8;
  test_2.matrix[2][1] = -2;
  test_2.matrix[2][2] = 4;
  for (int i = 0; i < result.rows; i++) {
    for (int j = 0; j < result.columns; j++) {
      ck_assert_uint_eq(result.matrix[i][j], test_2.matrix[i][j]);
    }
  }
  s21_remove_matrix(&test);
  s21_remove_matrix(&test_2);
  s21_remove_matrix(&result);
}
END_TEST

TCase *tcase_matrix_s21_calc_complements() {
  TCase *tcase = tcase_create("matrix_s21_calc_complements");
  tcase_add_test(tcase, test_s21_calc_complements_1);
  tcase_add_test(tcase, test_s21_calc_complements_2);
  tcase_add_test(tcase, test_s21_calc_complements_3);
  return tcase;
}
