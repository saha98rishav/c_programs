#include <stdio.h>

int main() {
    int a=5;
    int b=10;
    int *p;
    p = &b;
    printf("%d", *p);

    p = &a;

    *p += 1;

    printf("\n%d\n", a);
    return 0;
}