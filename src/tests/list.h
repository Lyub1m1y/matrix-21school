#ifndef SRC_TESTS_LIST_H_
#define SRC_TESTS_LIST_H_

#include <check.h>

TCase *tcase_matrix_s21_create_matrix();
TCase *tcase_matrix_s21_remove_matrix();
TCase *tcase_matrix_s21_eq_matrix();

#define suite_add_tcase_list(suite)                             \
  do {                                                          \
    suite_add_tcase((suite), tcase_matrix_s21_create_matrix()); \
    suite_add_tcase((suite), tcase_matrix_s21_remove_matrix()); \
    suite_add_tcase((suite), tcase_matrix_s21_eq_matrix());     \
  } while (0)

#endif  // SRC_TESTS_LIST_H_
