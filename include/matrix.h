#ifndef ML_in_c_matrix_h
#define ML_in_c_matrix_h

#include <stddef.h>

typedef struct {
    size_t rows;
    size_t cols;
    double **data;
} Matrix;

Matrix* create_matrix(size_t rows, size_t cols);
void free_matrix(Matrix* matrix);
void print_matrix(const Matrix* matrix);
Matrix* add_matrices(const Matrix* a, const Matrix* b);
Matrix* multiply_matrices(const Matrix* a, const Matrix* b);
Matrix* transpose_matrix(const Matrix* m);

#endif