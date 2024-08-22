#include <stdio.h>

struct Polynomial {
    int coeff, exp1, exp2;
};

void multiplyPolynomials(struct Polynomial p1[], int n1, struct Polynomial p2[], int n2) {
    printf("Product: ");
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            int newCoeff = p1[i].coeff * p2[j].coeff;
            int newExp1 = p1[i].exp1 + p2[j].exp1;
            int newExp2 = p1[i].exp2 + p2[j].exp2;
            printf("%dx^%dy^%d ", newCoeff, newExp1, newExp2);
        }
    }
    printf("\n");
}

int main() {
    struct Polynomial p1[] = {{3, 2, 1}, {4, 1, 2}};
    struct Polynomial p2[] = {{5, 1, 1}, {2, 0, 1}};
    int n1 = sizeof(p1) / sizeof(p1[0]);
    int n2 = sizeof(p2) / sizeof(p2[0]);
    multiplyPolynomials(p1, n1, p2, n2);
    return 0;
}
