#include "../s21_matrix.h"
#include "common.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  double det;
  int status = s21_determinant(A, &det);
  if (!status) {
    double eps = pow(10, -7);
    if (fabs(det - 0) < eps) {
      status = ERROR_CALC;
    } else {
      matrix_t comp_mat;
      status = s21_calc_complements(A, &comp_mat);
      if (status != ERROR) {
        matrix_t trans_mat;
        status = s21_transpose(&comp_mat, &trans_mat);
        if (status != ERROR) {
          s21_mult_number(&trans_mat, 1 / det, result);
          s21_remove_matrix(&trans_mat);
        }
        s21_remove_matrix(&comp_mat);
      }
    }
  }
  return status;
}
