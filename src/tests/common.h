#ifndef SRC_TESTS_COMMON_H_
#define SRC_TESTS_COMMON_H_

#include <check.h>

#include "../s21_matrix.h"

void s21_gen_matrix(matrix_t *A);
void s21_anti_gen_matrix(matrix_t *A);
void s21_fill(matrix_t *matrixStruct, double value);

#endif  // SRC_TESTS_COMMON_H_
