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

Matrix* softmax(const Matrix* input){
    if(!input) return NULL;
    Matrix *output = create_matrix(input->rows, input->cols);

    for(size_t i=0;i<input->rows;i++){
        //find the max value in the row shifitng
        float max_val = input->data[i][0];
        for(size_t j=1;j<input->cols;j++){
            if(input->data[i][j]>max_val){
                max_val = input->data[i][j];
            }
        }

        //subtract max for numerical stability and compute exponentials
        float sum_exp = 0.0f;
        for(size_t j=0;j<input->cols;j++){
            output->data[i][j] = expf(input->data[i][j] - max_val);
            sum_exp += output->data[i][j];
        }

        //normalize to get probabilities for each class
        for(size_t j=0;j<input->cols;j++){
            output->data[i][j] /= sum_exp;
        }

    }
    return output;
}