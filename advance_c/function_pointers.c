#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int foo(int x, int y);
bool p(int x);
void print_if(int xs[10], bool (*predicate)(int));
int compar(const void *a, const void *b);

int main() {
    int xs[] = {3, 2, 4, 5, 7, 6, 8, 9, 10, -2};
    printf("Size of array in bytes: %d\n", (int)(sizeof(xs)));
    printf("Size: %d\n", (int)(sizeof(xs) / sizeof(xs[0])));

    // print_if(xs, p);
    qsort(xs, 10, sizeof(int), compar);
    for (int i = 0; i < 10; i += 1) {
        printf("%d\n", xs[i]);
    }
    return 0;
}

int foo(int x, int y) {
    return x + y;
}

bool p(int x) {
    return (x % 2 == 0);
}

void print_if(int xs[10], bool (*predicate)(int)) {
    for (int i = 0; i < 10; i += 1) {
        if (predicate(xs[i]))
            printf("%d\n", xs[i]);
    }
}

int compar(const void *a, const void *b) {
    return (*(int *)a) - (*(int *)b);
}
