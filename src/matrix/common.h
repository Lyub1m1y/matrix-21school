#ifndef SRC_MATRIX_COMMON_H_
#define SRC_MATRIX_COMMON_H_

#include "../s21_matrix.h"

int s21_is_correct(matrix_t *matrix);
void s21_get_minor(int row, int col, matrix_t *A, matrix_t *result);
double s21_get_determinant(matrix_t *A);

#endif  // SRC_MATRIX_COMMON_H_
