#include <stdbool.h>
#include <stdio.h>

typedef unsigned int t_flag;
#define FLAG_A (1 << 0)
#define FLAG_B (1 << 1)
#define FLAG_B (1 << 2)

int main() {
    printf("%d\n", (1 << 0));
    printf("%d\n", (1 << 1));
    printf("%d\n", (1 << 2));
    return 0;
}