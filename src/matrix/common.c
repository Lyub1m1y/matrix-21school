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
