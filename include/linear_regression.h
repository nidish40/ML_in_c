#ifndef LINEAR_REGRESSION_H
#define LINEAR_REGRESSION_H

#include "matrix.h"

typedef struct{
    Matrix* weights;
    double bias;
    double learning_rate;
}LinearRegression;

//create & free model
LinearRegression* create_Linear_Regression(size_t n_features, double lr);
void free_Linear_Regression(LinearRegression* model);

//Forward prediction
Matrix* lr_predict(const LinearRegression* model, const Matrix* X);

//Loss compute
double compute_mse(const Matrix* y_true, const Matrix* y_pred);

//training 
void train_linear_regression(LinearRegression* model, const Matrix* X, const Matrix* y, size_t epochs);

#endif

