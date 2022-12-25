#ifndef SRC_S21_matrix_H_
#define SRC_S21_matrix_H_

/******************************************************************************/
/* Part 1. Implementation of the matrix.h library functions                   */
/******************************************************************************/

/* lib */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/* Macros */

#ifndef OK
#define OK 0  // OK
#endif
#ifndef ERROR
#define ERROR 1  // Error, incorrect matrix
#endif
#ifndef ERROR_CALC
#define ERROR_CALC 2  // Calculation error
#endif
#ifndef SUCCESS
#define SUCCESS 1
#endif
#ifndef FAILURE
#define FAILURE 0
#endif

/* Struct */

typedef struct matrix_struct {
  double **matrix;
  int rows;
  int columns;
} matrix_t;

/* Functions */
// TODO Убрать комменты лишние
int s21_create_matrix(int rows, int columns, matrix_t *result);     // yes
void s21_remove_matrix(matrix_t *A);                                // yes
int s21_eq_matrix(matrix_t *A, matrix_t *B);                        // yes
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);     // yes
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);     // yes
int s21_mult_number(matrix_t *A, double number, matrix_t *result);  // yes
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);    // yes
int s21_transpose(matrix_t *A, matrix_t *result);                   // yes
int s21_calc_complements(matrix_t *A, matrix_t *result);
int s21_determinant(matrix_t *A, double *result);
int s21_inverse_matrix(matrix_t *A, matrix_t *result);

#endif  // SRC_S21_matrix_H_
