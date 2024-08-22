#include <stdio.h>

struct Polynomial {
    int coeff;
    int exp;
};

void addPolynomials(struct Polynomial p1[], int n1, struct Polynomial p2[], int n2) {
    int i = 0, j = 0;
    printf("Sum: ");
    while (i < n1 && j < n2) {
        if (p1[i].exp > p2[j].exp) {
            printf("%dx^%d ", p1[i].coeff, p1[i].exp);
            i++;
        } else if (p1[i].exp < p2[j].exp) {
            printf("%dx^%d ", p2[j].coeff, p2[j].exp);
            j++;
        } else {
            printf("%dx^%d ", p1[i].coeff + p2[j].coeff, p1[i].exp);
            i++;
            j++;
        }
    }
    while (i < n1) {
        printf("%dx^%d ", p1[i].coeff, p1[i].exp);
        i++;
    }
    while (j < n2) {
        printf("%dx^%d ", p2[j].coeff, p2[j].exp);
        j++;
    }
    printf("\n");
}

int main() {
    struct Polynomial p1[] = {{3, 2}, {5, 1}, {6, 0}};
    struct Polynomial p2[] = {{4, 2}, {2, 1}, {3, 0}};
    int n1 = sizeof(p1) / sizeof(p1[0]);
    int n2 = sizeof(p2) / sizeof(p2[0]);
    addPolynomials(p1, n1, p2, n2);
    return 0;
}
