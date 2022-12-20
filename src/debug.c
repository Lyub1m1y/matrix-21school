// #include "s21_matrix.h"

// int s21_create_matrix(int rows, int columns, matrix_t *result) {
//   int status = 0;
//   if (result != NULL) {
//     status = OK;
//     result->rows = rows;
//     result->columns = columns;
//     result->matrix = (double **)malloc(rows * sizeof(double *));
//     if (result->matrix != NULL) {
//       for (int i = 0; i < rows; i++) {
//         result->matrix[i] = (double *)malloc(columns * sizeof(double));
//       }
//     }
//   } else {
//     status = ERROR;
//   }
//   return status;
// }

// void s21_remove_matrix(matrix_t *A) {
//   for (int i = 0; i < A->rows; i++) {
//     free(A->matrix[i]);
//   }
//   free(A->matrix);
// }

// int main() {
//   matrix_t matrix = {0};
//   matrix_t *pmatrix = &matrix;
//   int rows = 5, columns = 5;
//   printf("1. |%p|\n", pmatrix);
//   s21_create_matrix(rows, columns, pmatrix);
//   s21_remove_matrix(pmatrix);
//   if (pmatrix == NULL) {
//     printf("2. |%p|\n", pmatrix);
//   }
//   return 0;
// }