#include "../s21_matrix.h"
#include "common.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int status = 0;
  if (s21_is_correct(A)) {
    if (A->rows != A->columns) {
      status = ERROR_CALC;
    } else {
      status = s21_create_matrix(A->rows, A->columns, result);
      if (status != ERROR) {
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < A->columns; j++) {
            matrix_t tmp;
            s21_create_matrix(A->rows - 1, A->columns - 1, &tmp);
            s21_get_minor(i, j, A, &tmp);
            result->matrix[i][j] = s21_get_determinant(&tmp);
            if ((j + i) % 2) {
              result->matrix[i][j] *= (-1);
            }
            s21_remove_matrix(&tmp);
          }
        }
      }
    }
  } else {
    status = ERROR;
  }
  return status;
}