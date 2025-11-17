#ifndef losses_h
#define losses_h

#include "matrix.h"

float mse_loss(const Matrix* preds, const Matrix* targets, Matrix **grad_out);

float cross_entropy_loss_from_probs(const Matrix* preds, const Matrix* targets, Matrix **grad_out);

float softmax_cross_entropy_loss_from_probs(const Matrix* logits, const Matrix* targets, Matrix **grad_out);

#endif