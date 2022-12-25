#ifndef SRC_TESTS_COMMON_H_
#define SRC_TESTS_COMMON_H_

#include <check.h>

#include "../s21_matrix.h"
// TODO удавлить комменты
// matrix_t init_matrix(int rows, int columns);
// void fill_matrix_increment(matrix_t *matrix, int value);
void s21_gen_matrix(matrix_t *A);
void s21_anti_gen_matrix(matrix_t *A);

#endif  // SRC_TESTS_COMMON_H_
