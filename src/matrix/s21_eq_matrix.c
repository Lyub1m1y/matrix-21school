#include "../s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int status = SUCCESS;
  if ((A->rows != B->rows) || (A->columns != B->columns)) {
    status = ERROR_CALC;
  } else {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; (j < A->columns) && (status != FAILURE); j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-07) {
          status = FAILURE;
        }
      }
    }
  }
  return status;
}
