// tests/test_logistic_regression.c
#include <stdio.h>
#include "logistic_regression.h"
#include "matrix.h"

int main() {
    size_t n_samples = 6;
    size_t n_features = 1;

    // Simple dataset: X and y
    Matrix* X = create_matrix(n_samples, n_features);
    Matrix* y = create_matrix(n_samples, 1);

    double x_vals[] = {1, 2, 3, 4, 5, 6};
    double y_vals[] = {0, 0, 0, 1, 1, 1};

    for(size_t i=0;i<n_samples;i++){
        X->data[i][0] = x_vals[i];
        y->data[i][0] = y_vals[i];
    }

    LogisticRegression* model = create_logistic_regression(n_features, 0.1);
    train_logistic_regression(model, X, y, 1000);

    Matrix* preds = logistic_predict(model, X);
    printf("\nPredictions:\n");
    print_matrix(preds);

    free_matrix(X);
    free_matrix(y);
    free_matrix(preds);
    free_logistic_regression(model);

    return 0;
}
