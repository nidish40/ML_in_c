#include "matrix.h"
#include "activations.h"
#include <stdio.h>

int main() {
    // 1. Create a sample matrix
    Matrix* input = create_matrix(2, 3);
    input->data[0][0] = -1.0; input->data[0][1] = 0.0; input->data[0][2] = 1.0;
    input->data[1][0] = -0.5; input->data[1][1] = 0.5; input->data[1][2] = 2.0;

    print_matrix(input);

    // 2. Apply ReLU
    Matrix* relu_m = relu(input);
    print_matrix(relu_m);

    // 3. Apply Sigmoid
    Matrix* sigmoid_m = sigmoid(input);
    print_matrix(sigmoid_m);

    // 4. Apply Tanh
    Matrix* tanh_m = tanh_matrix(input);
    print_matrix(tanh_m);

    // 5. Free memory
    free_matrix(input);
    free_matrix(relu_m);
    free_matrix(sigmoid_m);
    free_matrix(tanh_m);

    return 0;
}
