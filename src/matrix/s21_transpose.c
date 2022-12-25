#include "../s21_matrix.h"
#include "common.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int status = OK;
  if (s21_is_correct(A)) {
    status = s21_create_matrix(A->columns, A->rows, result);
    if (status != ERROR) {
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          result->matrix[j][i] = A->matrix[i][j];
        }
      }
    }
  } else {
    status = ERROR;
  }
  return status;
}
