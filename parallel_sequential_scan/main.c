#include "read_file.h"
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // check if file path provided or not
    if (argc != 3) {
        printf("Please provide the file path and number to search respectively!\n");
        return 1;
    }

    bool status = false;
    int *arr_size = (int *)malloc(sizeof(int));

    char *filepath = argv[1];
    int num = atoi(argv[2]);
    /*
    printf("argc: %d\n",argc);
    printf("filepath: %s\n", filepath);
    printf("number: %d\n", num);
    */

    int *arr = read_file(filepath, arr_size, &status);

    if (status && *arr_size > 0 && arr != NULL) {
        printf("%d\n", *arr_size);
    } else {
        printf("Error happened!!\n");
        return 1;
    }
    if (arr != NULL)
        free(arr);
    free(arr_size);
    return 0;
}
