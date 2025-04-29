#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOTAL_NUM 50000000

int main() {
    // Open the file to save random integers
    FILE *file = fopen("parallel_sequential_scan/random_integers.txt", "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Seed the random number generator
    srand(time(NULL));

    // Generate 1000 random integers
    for (int i = 0; i < TOTAL_NUM; i++) {
        int randomNumber = rand() % TOTAL_NUM + 1; // Random integers between 1 and 1000
        fprintf(file, "%d\n", randomNumber);
    }

    fclose(file);
    printf("%d random integers written to 'random_integers.txt'.\n", TOTAL_NUM);

    return 0;
}
