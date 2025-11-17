# 📦 ML in C — Custom Machine Learning Framework

This project is a from-scratch implementation of a **minimal machine learning framework written entirely in C**, built to understand how neural networks work internally without relying on external ML libraries.

The project focuses on implementing all key components manually:
- Matrix operations  
- Activation functions  
- Loss functions  
- Neural network building blocks  
- Gradients & backprop  
- Training logic  

This README documents **everything completed so far**.

---

## ✅ Current Features Implemented

---

## 🧮 1. Matrix Module

A custom `Matrix` struct and collection of low-level operations that serve as the foundation of all ML computations.

### ✔ Completed:
- Dynamic matrix creation & deletion  
- Matrix printing (debugging)  
- Matrix addition  
- Matrix subtraction  
- Matrix multiplication (dot product)  
- Matrix transpose  
- Element-wise operations  
- Safety checks for shape mismatch  

These functions power all later layers, activations, and loss functions.

---

## 🔌 2. Activation Functions

Implemented common neural network activation functions in pure C.

### ✔ Completed:
- **ReLU**  
- **Sigmoid**  
- **Tanh**  
- **Softmax (row-wise, numerically stable)**

The softmax implementation uses the standard *“subtract max trick”* to avoid overflow:

\[
\text{softmax}(x_i) = \frac{e^{x_i - \max(x)}}{\sum_j e^{x_j - \max(x)}}
\]

---

## 📉 3. Loss Functions

Loss functions implemented so far, including their gradients, which will be used during backpropagation.

### ✔ Completed:

### **1. Mean Squared Error (MSE)**
For regression-style problems.  
Computes:

\[
\text{MSE} = \frac{1}{N} \sum (p - t)^2
\]

Also returns gradient:

\[
\nabla = \frac{2(p - t)}{N}
\]

---

### **2. Cross Entropy Loss (from probabilities)**
Used for classification when probabilities are already softmaxed.

\[
\text{CE} = -\sum t \log(p)
\]

Gradient:

\[
\nabla = \frac{p - t}{\text{batch}}
\]

---

### **3. Softmax + Cross Entropy (with logits)**
Numerically stable version used in all real ML frameworks.

Computes:

1. Softmax  
2. Cross entropy  
3. Gradient  

all in a single efficient pass.

Gradient:

\[
\nabla = \frac{\text{softmax}(z) - t}{\text{batch}}
\]

---

## 🏗️ 4. Project Status

The framework currently supports:

- Core matrix math  
- Activation functions  
- Loss functions and their gradients  
- Testing utilities  
- A working basis for building neural network layers

This is the complete foundation needed to start:

- Implementing Dense (Fully Connected) layers  
- Implementing backpropagation  
- Building a complete neural network  

---