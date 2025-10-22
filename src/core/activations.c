#include "activations.h"
#include <math.h>

Matrix* relu(const Matrix* m){
    if(!m) return NULL;
    Matrix *res = create_matrix(m->rows, m->cols);

    for(size_t i=0;i<m->rows;i++){
        for(size_t j=0;j<m->cols;j++){
            res->data[i][j] = (m->data[i][j]>0)? m->data[i][j] : 0.0;
        }
    }

    return res;
}

Matrix* sigmoid(const Matrix* m){
    if(!m) return NULL;
    Matrix *res = create_matrix(m->rows, m->cols);

    for(size_t i=0;i<m->rows;i++){
        for(size_t j=0;j<m->cols;j++){
            res->data[i][j] = 1.0 / (1.0 + exp(-m->data[i][j]));
        }
    }

    return res;
}

Matrix* tanh_matrix(const Matrix* m){
    if(!m) return NULL;
    Matrix *res = create_matrix(m->rows, m->cols);

    for(size_t i=0;i<m->rows;i++){
        for(size_t j=0;j<m->cols;j++){
            res->data[i][j] = tanh(m->data[i][j]);
        }
    }

    return res;
}