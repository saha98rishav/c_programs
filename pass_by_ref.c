#include <stdio.h>

void addOne(int *a, int *b, int *c);

int main() {
    int x1 = 10, x2 = 20, x3 = 30;
    addOne(&x1, &x2, &x3);
    printf("x1: %d\n", x1);
    printf("x2: %d\n", x2);
    printf("x3: %d\n", x3);
    return 0;
}

void addOne(int *a, int *b, int *c) {
    *a += 10;
    *b += 10;
    *c += 10;
}