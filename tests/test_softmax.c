#include <stdio.h>
#include "matrix.h"
#include "activations.h"

int main() {
    // Create a 2x3 matrix: 2 samples, 3 class scores each
    Matrix* logits = create_matrix(2, 3);

    // Sample 1
    logits->data[0][0] = 2.0;
    logits->data[0][1] = 1.0;
    logits->data[0][2] = 0.1;

    // Sample 2
    logits->data[1][0] = 1.0;
    logits->data[1][1] = 3.0;
    logits->data[1][2] = 2.0;

    // Create output matrix for softmax probabilities
    Matrix* probs = softmax(logits);

    // Print results
    printf("Softmax probabilities:\n");
    for (size_t i = 0; i < probs->rows; i++) {
        for (size_t j = 0; j < probs->cols; j++) {
            printf("%0.4f ", probs->data[i][j]);
        }
        printf("\n");
    }

    free_matrix(logits);
    free_matrix(probs);

    return 0;
}
