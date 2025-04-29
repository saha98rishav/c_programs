#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int *read_file(char *filepath, int *arr_size, bool *status) {
    FILE *file; // FILE pointer
    int *arr;   // Integer pointer for array
    int num, size = 0, capacity = 10;

    // Open file in read mode
    file = fopen(filepath, "r");
    if (file == NULL) {
        printf("Error: Unable to open file.\n");
        *status = false;
    }

    // Dynamically allocate memory for the array
    arr = (int *)malloc(capacity * sizeof(int));
    if (arr == NULL) {
        printf("Error: Memory allocation failed.\n");
        fclose(file);
        *status = false;
    }

    // Read integers from file and store in array
    while (fscanf(file, "%d", &num) != EOF) {
        if (size == capacity) {
            capacity *= 2;
            arr = (int *)realloc(arr, capacity * sizeof(int));
            if (arr == NULL) {
                printf("Error: Memory allocation failed.\n");
                fclose(file);
                *status = false;
            }
        }
        arr[size++] = num;
    }

    // Close the file since reading is completed
    fclose(file);
    *arr_size = size;
    *status = true;
    
    return arr;
}
