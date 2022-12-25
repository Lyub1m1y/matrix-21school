#ifndef SRC_TESTS_LIST_H_
#define SRC_TESTS_LIST_H_

#include <check.h>

TCase *tcase_matrix_s21_create_matrix();
TCase *tcase_matrix_s21_remove_matrix();
TCase *tcase_matrix_s21_eq_matrix();
TCase *tcase_matrix_s21_sum_matrix();
TCase *tcase_matrix_s21_sub_matrix();
TCase *tcase_matrix_s21_mult_number();
TCase *tcase_matrix_s21_mult_matrix();
TCase *tcase_matrix_s21_transpose();
TCase *tcase_matrix_s21_calc_complements();
TCase *tcase_matrix_s21_determinant();
TCase *tcase_matrix_s21_inverse_matrix();

#define suite_add_tcase_list(suite)                                \
  do {                                                             \
    suite_add_tcase((suite), tcase_matrix_s21_create_matrix());    \
    suite_add_tcase((suite), tcase_matrix_s21_remove_matrix());    \
    suite_add_tcase((suite), tcase_matrix_s21_eq_matrix());        \
    suite_add_tcase((suite), tcase_matrix_s21_sum_matrix());       \
    suite_add_tcase((suite), tcase_matrix_s21_sub_matrix());       \
    suite_add_tcase((suite), tcase_matrix_s21_mult_number());      \
    suite_add_tcase((suite), tcase_matrix_s21_mult_matrix());      \
    suite_add_tcase((suite), tcase_matrix_s21_transpose());        \
    suite_add_tcase((suite), tcase_matrix_s21_calc_complements()); \
    suite_add_tcase((suite), tcase_matrix_s21_determinant());      \
    suite_add_tcase((suite), tcase_matrix_s21_inverse_matrix());   \
  } while (0)

#endif  // SRC_TESTS_LIST_H_
