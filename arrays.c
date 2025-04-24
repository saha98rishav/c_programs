#include <stdio.h>

void addOne(int *array, int length);

int main() {
    int a[] = {1,2,3,4,5,6,7,8,9,10};
    addOne(a + 5, 5);
    for (int i=0; i<10; i+=1)
        printf("a[%d] = %d\n", i, a[i]);
    return 0;
}

void addOne(int *array, int length) {
    for (int i=0; i<length; i+=1)
        array[i] += 1;
}