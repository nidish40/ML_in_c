#ifndef logistic_regression_h
#define logistic_regression_h

#include "matrix.h"

typedef struct{
    Matrix* weights;
    double bias;
    double learning_rate;
}LogisticRegression;

//create & free model
LogisticRegression* create_logistic_regression(size_t n_features, double lr);
void free_logisitc_regression(LogisticRegression* model);

//forward Prediction (using sigmoid activation)
Matrix* logistic_predict(const LogisticRegression* model, const Matrix* X);

//compute binary cross-entropy loss
double compute_binary_crossentropy(const Matrix* y_true, const Matrix* y_pred);

//training loop with gradient descent
void train_logistic_regression(LogisticRegression* model, const Matrix* X, const Matrix* y, size_t epochs);

#endif