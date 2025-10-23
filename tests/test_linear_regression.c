// tests/test_linear_regression.c
#include <stdio.h>
#include "linear_regression.h"
#include "matrix.h"

int main() {
    size_t n_samples = 5;
    size_t n_features = 1;

    // X = [1,2,3,4,5], y = 2*X + 1
    Matrix* X = create_matrix(n_samples, n_features);
    Matrix* y = create_matrix(n_samples, 1);
    double x_vals[] = {1,2,3,4,5};
    double y_vals[] = {3,5,7,9,11};

    for(size_t i=0;i<n_samples;i++){
        X->data[i][0] = x_vals[i];
        y->data[i][0] = y_vals[i];
    }

    LinearRegression* model = create_linear_regression(n_features, 0.01);
    train_linear_regression(model, X, y, 1000);

    printf("\nFinal Weights:\n");
    print_matrix(model->weights);
    printf("Final Bias: %.6f\n", model->bias);

    Matrix* preds = linear_predict(model, X);
    printf("\nPredictions:\n");
    print_matrix(preds);

    free_matrix(X);
    free_matrix(y);
    free_matrix(preds);
    free_linear_regression(model);

    return 0;
}
