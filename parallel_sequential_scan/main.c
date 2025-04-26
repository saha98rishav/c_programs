#include "read_file.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // check if file path provided or not
    if (argc != 2) {
        printf("Please provide the file path\n");
        return 1;
    }
    bool status = false;
    int *arr_size = (int *)malloc(sizeof(int));

    char *filepath = argv[1];
    int *arr = read_file(filepath, arr_size, &status);

    if (status && *arr_size > 0 && arr != NULL) {
        for (int i = 0; i < *arr_size; i += 1) {
            printf("%d\n", *(arr + i));
        }
    } else {
        printf("Error happened!!\n");
        return 1;
    }
    if (arr != NULL)
        free(arr);
    free(arr_size);
    return 0;
}
