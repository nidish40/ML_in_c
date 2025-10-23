#include <stdio.h>
#include <stdlib.h>
#include "linear_regression.h"
#include "matrix.h"

LinearRegression* create_linear_regression(size_t n_features, double lr){
    LinearRegression* model = (LinearRegression*)malloc(sizeof(LinearRegression));
    model->weights = create_matrix(n_features, 1);
    model->bias = 0.0;
    model->learning_rate = lr;

    for(size_t i=0;i<n_features;i++){
        model->weights->data[i][0] = ((double)rand()/RAND_MAX) -0.5;
    }
    return model;
}


void free_linear_regression(LinearRegression* model){
    if(!model) return;
    free_matrix(model->weights);
    free(model);
}

Matrix* linear_predict(const LinearRegression* model, const Matrix* X){
    if(!model || !X) return NULL; //both have to be valid

    //y_pred = X*W
    Matrix* y_pred = multiply_matrices(X, model->weights);

    //add bias
    for(size_t i=0;i<y_pred->rows;i++){
        y_pred->data[i][0] += model->bias;
    }

    return y_pred;
}

//compute MSE loss 
double compute_mse(const Matrix* y_true, const Matrix* y_pred){
    if(!y_true || !y_pred || y_true->rows != y_pred->rows || y_true->cols != y_pred->cols) return -1.0;

    double mse = 0.0;
    size_t n = y_true->rows;

    for(size_t i=0;i<n;i++){
        double diff = y_true->data[i][0] - y_pred->data[i][0];
        mse += diff * diff;
    }

    return mse / n;
}


//training Linear Regression model using gradient Descent
void train_linear_regression(LinearRegression* model, const Matrix* X, const Matrix* y, size_t epochs){
    if(!model||!X||!y) return;

    size_t n_samples = X->rows;
    size_t n_features = X->cols;

    for(size_t epoch=0;epoch<epochs;epoch++){
        Matrix* y_pred = linear_predict(model, X);

        //Compute gradients
        //wrt weight: X^T * (y_pred -y)/n_samples
        Matrix* error = elementwise_subtract(y_pred, y);
        Matrix* X_T = transpose_matrix(X);
        Matrix* grad_w = multiply_matrices(X_T, error);
        for(size_t i=0;i<n_features;i++){
            grad_w->data[i][0] /= n_samples;
        }

        //wrt bias: sum(y_pred - y)/n_samples
        double grad_b = 0.0;
        for(size_t i=0;i<n_samples;i++){
            grad_b += error->data[i][0];
        }
        grad_b /= n_samples;


        //update weights and biases
        for(size_t i=0;i<n_features;i++){
            model->weights->data[i][0] -= model->learning_rate * grad_w->data[i][0];
        }
        model->bias -= model->learning_rate * grad_b;

        if(epoch%100==0){
            double loss = compute_mse(y, y_pred);
            printf("Epoch %zu - MSE: %.6f\n", epoch, loss);
        }

        free_matrix(y_pred);
        free_matrix(error);
        free_matrix(X_T);
        free_matrix(grad_w);
    }

}