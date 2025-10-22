#include "matrix.h"
#include <stdio.h>

int main(void) {
    printf("=== Testing Matrix Module ===\n");

   
    Matrix* A = create_matrix(2, 2);
    Matrix* B = create_matrix(2, 2);

   
    A->data[0][0] = 1; A->data[0][1] = 2;
    A->data[1][0] = 3; A->data[1][1] = 4;

    B->data[0][0] = 5; B->data[0][1] = 6;
    B->data[1][0] = 7; B->data[1][1] = 8;


    printf("Matrix A:\n"); print_matrix(A);
    printf("Matrix B:\n"); print_matrix(B);

 
    Matrix* C = add_matrices(A, B);
    printf("A + B:\n"); print_matrix(C);

    Matrix* D = multiply_matrices(A, B);
    printf("A * B:\n"); print_matrix(D);

    // 6️⃣ Test transpose
    Matrix* T = transpose_matrix(A);
    printf("Transpose of A:\n");
    print_matrix(T);
    free_matrix(T);

    //Free all allocated memory
    free_matrix(A);
    free_matrix(B);
    free_matrix(C);
    free_matrix(D);

    printf("=== All tests completed successfully ===\n");
    return 0;
}
