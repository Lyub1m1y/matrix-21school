#include "common.h"

int s21_is_correct(matrix_t *matrix) {
  int status = 0;
  if (matrix != NULL && matrix->matrix != NULL && matrix->rows > 0 &&
      matrix->columns > 0) {
    status = 1;
  } else {
    status = 0;
  }
  return status;
}

void s21_get_minor(int row, int col, matrix_t *A, matrix_t *result) {
  int act_row = 0, act_col = 0;
  for (int i = 0; i < A->rows; i++) {
    if (i == row) continue;
    act_col = 0;
    for (int j = 0; j < A->rows; j++) {
      if (j == col) continue;
      result->matrix[act_row][act_col] = A->matrix[i][j];
      act_col++;
    }
    act_row++;
  }
}

double s21_get_determinant(matrix_t *A) {
  double det = 0;
  if (A->rows == 1) {
    det = A->matrix[0][0];
  } else {
    double sign = 1;
    matrix_t tmp;
    int ret = s21_create_matrix(A->rows - 1, A->columns - 1, &tmp);
    if (ret != ERROR) {
      for (int i = 0; i < A->rows; i++) {
        s21_get_minor(0, i, A, &tmp);
        det += A->matrix[0][i] * sign * s21_get_determinant(&tmp);
        sign *= -1;
      }
      s21_remove_matrix(&tmp);
    } else {
      det = 0;
    }
  }
  return det;
}
