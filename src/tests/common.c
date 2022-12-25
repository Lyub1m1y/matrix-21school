#include "common.h"

void s21_gen_matrix(matrix_t *A) {
  double num = 1;
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++, num++) {
      A->matrix[i][j] = num;
    }
  }
}

void s21_anti_gen_matrix(matrix_t *A) {
  double num = 32;
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++, num--) {
      A->matrix[i][j] = num;
    }
  }
}

void s21_fill(matrix_t *matrixStruct, double value) {
  for (int i = 0; i < matrixStruct->rows; i++) {
    for (int j = 0; j < matrixStruct->columns; j++) {
      matrixStruct->matrix[i][j] = value;
    }
  }
}

// TODO удавлить комменты
// matrix_t init_matrix(int rows, int columns) {
//   matrix_t m;
//   m.rows = rows;
//   m.columns = columns;
//   m.matrix = NULL;
//   return m;
// }

// void fill_matrix_increment(matrix_t *matrix, int value) {
//   for (int i = 0; i < matrix->rows; i++) {
//     for (int j = 0; j < matrix->columns; j++) {
//       matrix->matrix[i][j] = value++;
//     }
//   }
// }
