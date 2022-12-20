// #include "s21_matrix.h"

// int s21_create_matrix(int rows, int columns, matrix_t *result) {
//   int status = 0;
//   if (result != NULL) {
//     status = OK;
//     result->rows = rows;
//     result->columns = columns;
//     printf("aboba");
//     (result->matrix) = (double **)malloc(rows * sizeof(double *));
//     for (int i = 0; i < rows; i++) {
//       result->matrix[i] = (double *)malloc(columns * sizeof(double));
//     }
//   } else {
//     status = ERROR;
//   }
//   return status;
// }

// int main() {
//   matrix_t *matrix = NULL;
//   int row = 5, columns = 5;
//   s21_create_matrix(row, columns, matrix);
//   return 0;
// }