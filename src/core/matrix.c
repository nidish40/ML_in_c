#include "matrix.h"
#include <stdio.h>
#include <stdlib.h>

#define ELEMENTWISE_OP(op) \
    if(!a || !b || a->rows != b->rows || a->cols != b->cols) return NULL; \
    Matrix* res = create_matrix(a->rows, a->cols); \
    for(size_t i=0;i<a->rows;i++){ \
        for(size_t j=0;j<a->cols;j++){ \
            res->data[i][j] = a->data[i][j] op b->data[i][j]; \
        } \
    } \
    return res;

Matrix* elementwise_add(const Matrix* a, const Matrix* b){
    ELEMENTWISE_OP(+)
}

Matrix* elementwise_subtract(const Matrix* a, const Matrix* b){
    ELEMENTWISE_OP(-)
}

Matrix* elementwise_multiply(const Matrix* a, const Matrix* b){
    ELEMENTWISE_OP(*)
}

Matrix* elementwise_divide(const Matrix* a, const Matrix* b){
    ELEMENTWISE_OP(/)
}

Matrix* create_matrix(size_t row, size_t cols){
    //allocate memory for matrix strucutre
    Matrix* m = (Matrix*)malloc(sizeof(Matrix));
    m->rows = row;
    m->cols = cols;

    //allocate memoroy for row pointers
    m->data = (double**)malloc(row*sizeof(double*));

    for(size_t i=0; i<row; i++){
        //allocate memory for each row
        m->data[i] = (double*)malloc(cols*sizeof(double));
    }

    return m;
}

void free_matrix(Matrix* m){
    if(!m) return;

    for(size_t i=0; i<m->rows; i++){
        free(m->data[i]); //free cols
    }

    free(m->data);//free row pointers
    free(m); //free matrix struct
}

void print_matrix(const Matrix* m){
    if(!m) return;

    for(size_t i=0; i<m->rows; i++){
        for(size_t j=0; j<m->cols; j++){
            printf("%8.2f ", m->data[i][j]);
        }
        printf("\n");
    }
}

Matrix* add_matrices(const Matrix* a, const Matrix* b){
    //checks for size compatibility
    if(!a || !b || a->rows != b->rows || a->cols != b->cols) return NULL;

    Matrix* res = create_matrix(a->rows, a->cols);

    for(size_t i=0;i<a->rows;i++){
        for(size_t j=0;j<a->cols;j++){
            res->data[i][j] = a->data[i][j] + b->data[i][j];
        }
    }

    return res;
}

Matrix* multiply_matrices(const Matrix *a, const Matrix *b){
    //check for size compatibility
    if(!a || !b || a->cols != b->rows) return NULL;

   Matrix *res = create_matrix(a->rows, b->cols);

   for(size_t i=0;i<a->rows;i++){
    for(size_t j=0;j<b->cols;j++){
        double sum = 0.0;
        for(size_t k=0;k<a->cols;k++){
            sum += a->data[i][k] * b->data[k][j];
        }
        res->data[i][j] = sum;
    }
   }
    return res;
}

Matrix* transpose_matrix(const Matrix* m){
    if(!m) return NULL;

    Matrix *t = create_matrix(m->cols, m->rows);

    for(size_t i=0;i<m->rows;i++){
        for(size_t j=0;j<m->cols;j++){
            t->data[j][i] = m->data[i][j];
        }
    }
    return t;
}

double dot_product(const double* a, const double *b, size_t n){
    if(!a||!b) return 0.0;

    double sum = 0.0;
    for(size_t i=0;i<n;i++){
        sum += a[i]*b[i];
    }
    return sum;
}