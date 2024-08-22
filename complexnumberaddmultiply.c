#include <stdio.h>
typedef struct {
    float real;
    float imag;
} Complex;

// Function to add two complex numbers
Complex addComplex(Complex c1, Complex c2) {
    Complex result;
    result.real = c1.real + c2.real;
    result.imag = c1.imag + c2.imag;
    return result;
}

// Function to multiply two complex numbers
Complex multiplyComplex(Complex c1, Complex c2) {
    Complex result;
    result.real = c1.real * c2.real - c1.imag * c2.imag;
    result.imag = c1.real * c2.imag + c1.imag * c2.real;
    return result;
}

int main() {
    Complex num1, num2, sum, product;

    printf("Enter the real and imaginary parts of the first complex number:\n");
    scanf("%f %f", &num1.real, &num1.imag);

    printf("Enter the real and imaginary parts of the second complex number:\n");
    scanf("%f %f", &num2.real, &num2.imag);

    sum = addComplex(num1, num2);
    product = multiplyComplex(num1, num2);

    printf("Sum = %.2f + %.2fi\n", sum.real, sum.imag);
    printf("Product = %.2f + %.2fi\n", product.real, product.imag);

    return 0;
}