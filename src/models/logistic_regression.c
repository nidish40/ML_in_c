#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matrix.h"
#include "logistic_regression.h"
#include "activations.h"

//create model 
LogisticRegression* create_logistic_regression(size_t n_features, double lr){
    LogisticRegression* model = (LogisticRegression*)malloc(sizeof(LogisticRegression));
    model->weights = create_matrix(n_features,1); //n features as rows and 1 col
    model->bias = 0.0;
    model->learning_rate = lr;

    //intialize weights randomly
    for(size_t i=0;i<n_features;i++){
        model->weights->data[i][0] = ((double)rand()/RAND_MAX) -0.5;
    }

    return model;
}

//free model memory
void free_logistic_regression(LogisticRegression* model){
    if(!model) return;
    free_matrix(model->weights);
    free(model);
}

//Forward pass: y_hat = sigmoid(X*W+b)
Matrix* logistic_predict(const LogisticRegression* model, const Matrix* X){
    Matrix* z = multiply_matrices(X, model->weights); //X*W
    for(size_t i=0;i<z->rows;i++){
        z->data[i][0] += model->bias; //add bias
    }

    Matrix* y_pred = sigmoid(z); //apply sigmoid
    free_matrix(z);
    return y_pred;
}

//compute binary cross-entropy loss
double compute_binary_crossentropy(const Matrix* y_true, const Matrix* y_pred){
    double loss = 0.0;
    size_t n = y_true->rows;
    for(size_t i=0;i<n;i++){
        double y = y_true->data[i][0];
        double p = y_pred->data[i][0];

        //clipping p to avoid log(0)
        if(p < 1e-15) p = 1e-15;
        if(p > 1.0 -1e-15) p = 1.0 -1e-15;

        loss += - (y *log(p) + (1 -y)*log(1 -p));
    }
    return loss/n;
}

//training logistic regression using gradient descent
void train_logistic_regression(LogisticRegression* model, const Matrix* X, const Matrix* y, size_t epochs){
    size_t n_samples = X->rows;
    size_t n_features = X->cols;

    for(size_t epoch=0;epoch<epochs;epoch++){
        //forward pass
        Matrix* y_pred = logistic_predict(model, X);

        //compute error (y_pred - y)
        Matrix* error = elementwise_subtract(y_pred, y);

        //compute gradient wrt weights: X^T * error / n_samples
        Matrix* X_T = transpose_matrix(X);
        Matrix* grad_w = multiply_matrices(X_T, error);
        for(size_t i=0;i<n_features;i++){
            grad_w->data[i][0] /= n_samples;
        }

        //compute gradient wrt bias: sum(error)/n_sampels
        double grad_b = 0.0;
        for(size_t i=0;i<n_samples;i++){
            grad_b += error->data[i][0];
        }
        grad_b /= n_samples;

        //update weights and bias
        for(size_t i=0;i<n_features;i++){
            model->weights->data[i][0] -= model->learning_rate * grad_w->data[i][0];
        }
        model->bias -= model->learning_rate * grad_b;

        if(epoch%50 == 0){
            double loss = compute_binary_crossentropy(y, y_pred);
            printf("Epoch %zu, Loss: %.6f\n", epoch, loss);
        }

        free_matrix(y_pred);
        free_matrix(error);
        free_matrix(X_T);
        free_matrix(grad_w);
    }
}

