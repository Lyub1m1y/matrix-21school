#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int status = 0;
  if (result != NULL) {
    status = OK;
    result->rows = rows;
    result->columns = columns;
    (result->matrix) = (double **)malloc(rows * sizeof(double *));
    for (int i = 0; i < rows; i++) {
      result->matrix[i] = (double *)malloc(columns * sizeof(double));
    }
  } else {
    status = ERROR;
  }
  return status;
}
