#ifndef ACTIVATIONS_H
#define ACTIVATIONS_H

#include "matrix.h"

Matrix* relu(const Matrix* m);
Matrix* sigmoid(const Matrix* m);
Matrix* tanh_matrix(const Matrix* m);
Matrix* softmax(const Matrix* input);


#endif