#include "../s21_matrix.h"
#include "common.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int status = OK;
  if (s21_is_correct(A)) {
    status = s21_create_matrix(A->rows, A->columns, result);
    if (status != ERROR) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] * number;
        }
      }
    }
  } else {
    status = ERROR;
  }
  return status;
}
