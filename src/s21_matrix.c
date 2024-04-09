#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  if (rows < 0 || columns < 0) {
    return INVALID_MATRIX;
  } else {
    result->matrix = (double **)calloc(rows, sizeof(double *));
    for (int i = 0; i < rows; i++) {
      result->matrix[i] = (double *)calloc(columns, sizeof(double));
    }
    result->columns = columns;
    result->rows = rows;
  }
  return OK;
}

void s21_remove_matrix(matrix_t *A) {
  for (int i = 0; i < A->rows; i++) {
    free(A->matrix[i]);
  }
  free(A->matrix);
  A->columns = 0;
  A->rows = 0;
  // A = NULL;
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  if (A->columns != B->columns || A->rows != B->rows || A == NULL ||
      B == NULL || A->matrix == NULL || B->matrix == NULL) {
    return FAILURE;
  }
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      if (fabs(A->matrix[i][j] - B->matrix[i][j]) > 1e-07) return FAILURE;
    }
  }
  return SUCCESS;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (!(A->columns == B->columns && A->rows == B->rows)) {
    return CALCULATION_ERROR;
  }
  if (s21_create_matrix(A->rows, A->columns, result) != 0)
    return INVALID_MATRIX;
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = B->matrix[i][j] + A->matrix[i][j];
    }
  }
  return OK;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (!(A->columns == B->columns && A->rows == B->rows)) {
    return CALCULATION_ERROR;
  }
  if (s21_create_matrix(A->rows, A->columns, result) != 0)
    return INVALID_MATRIX;

  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = -B->matrix[i][j] + A->matrix[i][j];
    }
  }
  return OK;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  if (s21_create_matrix(A->rows, A->columns, result) != 0)
    return INVALID_MATRIX;
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = number * A->matrix[i][j];
    }
  }
  return OK;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  if (A->columns != B->rows) {
    return CALCULATION_ERROR;
  }
  if (s21_create_matrix(A->rows, B->columns, result) != 0)
    return INVALID_MATRIX;
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < B->columns; j++) {
      for (int r = 0; r < A->columns; r++) {
        result->matrix[i][j] += A->matrix[i][r] * B->matrix[r][j];
      }
    }
  }
  return OK;
}

int s21_transpose(matrix_t *A, matrix_t *result) {
  if (s21_create_matrix(A->columns, A->rows, result) != 0)
    return INVALID_MATRIX;

  for (int i = 0; i < A->columns; i++) {
    for (int j = 0; j < A->rows; j++) {
      result->matrix[i][j] = A->matrix[j][i];
    }
  }
  return OK;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  if (A->columns != A->rows) return CALCULATION_ERROR;
  double res;
  matrix_t temp;
  s21_create_matrix(A->rows, A->columns, result);
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      s21_create_matrix(A->rows - 1, A->columns - 1, &temp);
      for (int l = 0, k = 0; l < A->rows - 1; l++, k++) {
        if (k == i) k++;
        for (int m = 0, h = 0; m < A->columns - 1; m++, h++) {
          if (h == j) h++;
          temp.matrix[l][m] = A->matrix[k][h];
        }
      }
      s21_determinant(&temp, &res);
      s21_remove_matrix(&temp);
      result->matrix[i][j] = res * pow(-1, i + j);
      res = 1;
    }
  }
  return OK;
}

int s21_determinant(matrix_t *A, double *result) {
  if (A->columns != A->rows) return CALCULATION_ERROR;
  int swapCount = 0;
  double res = 1.0;
  matrix_t res1;
  s21_create_matrix(A->rows, A->columns, &res1);
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      res1.matrix[i][j] = A->matrix[i][j];
    }
  }
  for (int i = 0; i < A->rows - 1; i++) {
    for (int k = i + 1; k < A->rows; k++) {
      if (fabs(res1.matrix[i][i]) < fabs(res1.matrix[k][i])) {
        swapCount++;
        for (int j = 0; j < A->rows; j++) {
          double temp = res1.matrix[i][j];
          res1.matrix[i][j] = res1.matrix[k][j];
          res1.matrix[k][j] = temp;
        }
      }
    }
    for (int k = i + 1; k < A->rows; k++) {
      double temp = res1.matrix[k][i] / res1.matrix[i][i];
      for (int j = 0; j < A->rows; j++) {
        res1.matrix[k][j] = res1.matrix[k][j] - temp * res1.matrix[i][j];
      }
    }
  }
  for (int i = 0; i < A->rows; i++) {
    res = res * res1.matrix[i][i];
  }
  res = res * pow(-1, swapCount);
  res = round(res * pow(10, 7)) * pow(10, -7);
  *result = res;
  s21_remove_matrix(&res1);
  return OK;
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  double res;
  matrix_t res1;
  if (s21_determinant(A, &res) != OK || res == 0) {
    return CALCULATION_ERROR;
  }
  if (A->rows == 1) {
    A->matrix[0][0] = 1 / A->matrix[0][0];
  }
  s21_calc_complements(A, &res1);
  s21_remove_matrix(A);
  s21_transpose(&res1, A);
  s21_remove_matrix(&res1);
  s21_mult_number(A, 1.0 / res, result);
  return OK;
}