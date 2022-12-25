#include "common.h"

START_TEST(test_s21_inverse_matrix_1) {
  matrix_t temp, result_defolt, result_defolt_2;
  s21_create_matrix(3, 3, &temp);
  s21_create_matrix(3, 3, &result_defolt);
  temp.matrix[0][0] = 2;
  temp.matrix[0][1] = 5;
  temp.matrix[0][2] = 7;
  temp.matrix[1][0] = 6;
  temp.matrix[1][1] = 3;
  temp.matrix[1][2] = 4;
  temp.matrix[2][0] = 5;
  temp.matrix[2][1] = -2;
  temp.matrix[2][2] = -3;
  result_defolt.matrix[0][0] = 1;
  result_defolt.matrix[0][1] = -1;
  result_defolt.matrix[0][2] = 1;
  result_defolt.matrix[1][0] = -38;
  result_defolt.matrix[1][1] = 41;
  result_defolt.matrix[1][2] = -34;
  result_defolt.matrix[2][0] = 27;
  result_defolt.matrix[2][1] = -29;
  result_defolt.matrix[2][2] = 24;

  s21_inverse_matrix(&temp, &result_defolt_2);

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_uint_eq(result_defolt.matrix[i][j],
                        result_defolt_2.matrix[i][j]);
    }
  }
  s21_remove_matrix(&temp);
  s21_remove_matrix(&result_defolt);
  s21_remove_matrix(&result_defolt_2);
}
END_TEST

START_TEST(test_s21_inverse_matrix_2) {
  matrix_t result1;
  matrix_t result2;
  matrix_t result3;
  s21_create_matrix(3, 3, &result1);
  result1.matrix[0][0] = 2;
  result1.matrix[0][1] = 5;
  result1.matrix[0][2] = 7;

  result1.matrix[1][0] = 6;
  result1.matrix[1][1] = 3;
  result1.matrix[1][2] = 4;

  result1.matrix[2][0] = 5;
  result1.matrix[2][1] = -2;
  result1.matrix[2][2] = -3;

  int expected_result = s21_create_matrix(3, 3, &result2);
  result2.matrix[0][0] = 1;
  result2.matrix[0][1] = -1;
  result2.matrix[0][2] = 1;
  result2.matrix[1][0] = -38;
  result2.matrix[1][1] = 41;
  result2.matrix[1][2] = -34;
  result2.matrix[2][0] = 27;
  result2.matrix[2][1] = -29;
  result2.matrix[2][2] = 24;
  int actual_result = s21_inverse_matrix(&result1, &result3);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_double_eq_tol(result2.matrix[i][j], result3.matrix[i][j], 1e-6);
    }
  }
  ck_assert_uint_eq(expected_result, actual_result);
  s21_remove_matrix(&result3);
  s21_remove_matrix(&result2);
  s21_remove_matrix(&result1);
}
END_TEST

START_TEST(test_s21_inverse_matrix_3) {
  matrix_t result1;
  matrix_t result3;
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
  int expected_result = ERROR_CALC;
  int actual_result = s21_inverse_matrix(&result1, &result3);
  ck_assert_uint_eq(expected_result, actual_result);

  s21_remove_matrix(&result1);
}
END_TEST

TCase *tcase_matrix_s21_inverse_matrix() {
  TCase *tcase = tcase_create("matrix_21_inverse_matrix");
  tcase_add_test(tcase, test_s21_inverse_matrix_1);
  tcase_add_test(tcase, test_s21_inverse_matrix_2);
  tcase_add_test(tcase, test_s21_inverse_matrix_3);
  return tcase;
}
