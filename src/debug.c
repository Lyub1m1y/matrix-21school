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

// // // void s21_remove_matrix(matrix_t *A) {
// // //   for (int i = 0; i < A->rows; i++) {
// // //     free(A->matrix[i]);
// // //   }
// // //   free(A->matrix);
// // // }

// // #include "s21_matrix.h"

// int s21_eq_matrix(matrix_t *A, matrix_t *B) {
//   int status = SUCCESS;
//   if ((A->rows != B->rows) || (A->columns != B->columns)) {
//     status = ERROR_CALC;
//   } else {
//     for (int i = 0; i < A->rows; i++) {
//       for (int j = 0; (j < A->columns) && (status != FAILURE); j++) {
//         if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-07) {
//           status = FAILURE;
//         }
//       }
//     }
//   }
//   return status;
// }

// int main() {
//   matrix_t matrix_1 = {0};
//   matrix_t matrix_2 = {0};
//   s21_create_matrix(3, 3, &matrix_1);
//   s21_create_matrix(3, 3, &matrix_2);
//   matrix_1.matrix[1][2] = 4.0000007;
//   matrix_2.matrix[1][2] = 4.0000009;
//   if (s21_eq_matrix(&matrix_1, &matrix_2)) {
//     printf("НЕГРЫ ПЕДИКИ");
//   }
//   return 0;
// }