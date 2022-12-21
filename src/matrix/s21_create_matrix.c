#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int status = 0;
  if (result != NULL && rows > 0 && columns > 0) {
    status = OK;
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double **)calloc(rows, sizeof(double *));
    if (result->matrix != NULL) {
      for (int i = 0; (i < rows) && (status != ERROR); i++) {
        result->matrix[i] = (double *)calloc(columns, sizeof(double));
        if (result->matrix[i] == NULL) {
          status = ERROR;
        }
      }
    } else {
      status = ERROR;
    }
  } else {
    status = ERROR;
  }
  return status;
}
