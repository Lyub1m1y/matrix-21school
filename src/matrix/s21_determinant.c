#include "../s21_matrix.h"
#include "common.h"

double s21_det(double **A, int n) {
  double sum = 0;
  if (n == 1) {
    sum = A[0][0];
  } else {
    if (n == 2) {
      sum = A[0][0] * A[1][1] - A[0][1] * A[1][0];
    } else {
      int number = 0;
      double **temp = calloc((n - 1), sizeof(double *));
      for (int i = 0; i < n; i++) {
        number = 0;
        for (int j = 0; j < n; j++) {
          if (i == j) continue;
          temp[number++] = A[j];
        }
        sum += pow(-1, i + n - 1) * A[i][n - 1] * s21_det(temp, n - 1);
      }
      free(temp);
    }
  }
  return sum;
}

int s21_determinant(matrix_t *A, double *result) {
  int status = 0;
  if (s21_is_correct(A) && (result != NULL)) {
    if (A->rows == A->columns) {
      *result = s21_det(A->matrix, A->rows);
    } else {
      status = 2;
    }
  } else {
    status = 1;
  }
  return status;
}
