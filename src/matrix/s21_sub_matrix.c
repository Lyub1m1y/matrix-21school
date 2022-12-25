#include "../s21_matrix.h"
#include "common.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int status = OK;
  if (s21_is_correct(A) && s21_is_correct(B)) {
    if (A->rows == B->rows && A->columns == B->columns) {
      status = s21_create_matrix(A->rows, A->columns, result);
      if (status != ERROR) {
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < A->columns; j++) {
            result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
          }
        }
      }
    } else {
      status = ERROR_CALC;
    }
  } else {
    status = ERROR;
  }
  return status;
}
