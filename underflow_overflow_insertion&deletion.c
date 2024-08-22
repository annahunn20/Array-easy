#include <stdio.h>

#define MAX 100
int arr[MAX];
int front = -1, rear = MAX;

void insertFront(int x) {
    if (front + 1 == rear) printf("Overflow\n");
    else arr[++front] = x;
}

void insertRear(int x) {
    if (rear - 1 == front) printf("Overflow\n");
    else arr[--rear] = x;
}

void deleteFront() {
    if (front == -1) printf("Underflow\n");
    else front--;
}

void deleteRear() {
    if (rear == MAX) printf("Underflow\n");
    else rear++;
}
