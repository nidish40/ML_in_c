# 📦 ML in C — Custom Machine Learning Framework

This project is a from-scratch implementation of a **minimal machine learning framework written in C**, designed to understand how ML models work internally without relying on external libraries.

The framework builds up from matrix operations → regression models → activation functions → loss functions → neural network components.

This README describes **everything completed so far**.

---

## ✅ Current Features Implemented

---

## 🧮 1. Matrix Module

A custom `Matrix` type with all the core operations required for ML calculations.

### ✔ Completed:
- Matrix creation & deletion  
- Addition, subtraction, multiplication  
- Transpose  
- Element-wise operations  
- Shape validation  
- Debug printing  

These form the foundation for all models.

---

## 🧠 2. Regression Models

### ✔ **Linear Regression**
- Forward pass (`y = XW + b`)  
- MSE loss  
- Gradient computation  
- Training via Gradient Descent  

### ✔ **Logistic Regression**
- Sigmoid activation  
- Binary cross-entropy loss  
- Gradient updates  
- Predicting probabilities & binary classes  

These give you a complete understanding of classical ML models before neural networks.

---

## 🔌 3. Activation Functions

Fully implemented activation functions used in neural networks.

### ✔ Completed:
- ReLU  
- Sigmoid  
- Tanh  
- Softmax (numerically stable, subtract-max trick)

---

## 📉 4. Loss Functions

All loss functions also return gradients for backpropagation.

### ✔ **Mean Squared Error (MSE)**
Used in regression.  
Measures squared difference between predictions and targets.

### ✔ **Cross Entropy (from probabilities)**
Used for classification when softmax probabilities are already computed.

### ✔ **Softmax Cross Entropy (with logits)**
Recommended version.  
Computes softmax + cross-entropy + gradient in a single, numerically stable step.

---

## 🏗️ 5. Current Project Status

So far, the following are fully functional:
- Core matrix engine  
- Linear regression  
- Logistic regression  
- Activation functions  
- Loss functions + gradients  
- Softmax & numerical stability handling  

The foundation is now ready for building neural network layers and backpropagation.

---



