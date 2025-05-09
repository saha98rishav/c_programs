#include "read_file.h"
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define THREAD_NUM 2

typedef struct ThreadArgs {
    int *arg1; // Array
    int arg2;  // Index from where to start search
    int arg3;  // Index to stop search
    int arg4;  // Number to search
    int *arg5; // occurence count of number to search
} ThreadArgs;

void *threadFunction(void *args) {
    ThreadArgs *threadArgs = (ThreadArgs *)args;
    printf("\nReceived arguements\n");
    printf("Array memory location: %p\n", threadArgs->arg1);
    printf("Start searching at index: %d\n", threadArgs->arg2);
    printf("Stop searching at index: %d\n", threadArgs->arg3);
    printf("Number to search: %d\n", threadArgs->arg4);
    printf("Initial occurence count: %d\n", *(threadArgs->arg5));

    for (int i = threadArgs->arg2; i < threadArgs->arg3; i += 1) {
        if (threadArgs->arg1[i] == threadArgs->arg4) {
            *threadArgs->arg5 += 1;
        }
    }
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    // check if file path provided or not
    if (argc != 4) {
        printf("Please provide the File path, Number to search, and Thread flag!\n");
        return 1;
    }

    bool status = false;
    int *arr_size = (int *)malloc(sizeof(int));
    int thread1Occurence = 0;
    int thread2Occurence = 0;

    char *filepath = argv[1];
    int num = atoi(argv[2]);
    int threadFlag = atoi(argv[3]);

    int *arr = read_file(filepath, arr_size, &status);

    pthread_t th[THREAD_NUM];
    ThreadArgs args[THREAD_NUM];

    if (status && *arr_size > 0 && arr != NULL) {
        if (threadFlag == 1) {
            args[0].arg1 = arr;
            args[0].arg2 = 0;
            args[0].arg3 = *arr_size;
            args[0].arg4 = num;
            args[0].arg5 = &thread1Occurence;

            pthread_create(&th[0], NULL, threadFunction, (void *)&args[0]);
            pthread_join(th[0], NULL);

            if (thread1Occurence == 0) {
                printf("\nNumber not found\n");
            } else {
                printf("\nNumber found and occurence is %d\n", thread1Occurence);
            }
        } else if (threadFlag == 2) {
            args[0].arg1 = arr;
            args[0].arg2 = 0;
            args[0].arg3 = (*arr_size / 2);
            args[0].arg4 = num;
            args[0].arg5 = &thread1Occurence;

            args[1].arg1 = arr;
            args[1].arg2 = (*arr_size / 2);
            args[1].arg3 = *arr_size;
            args[1].arg4 = num;
            args[1].arg5 = &thread2Occurence;

            pthread_create(&th[0], NULL, threadFunction, (void *)&args[0]);
            pthread_create(&th[1], NULL, threadFunction, (void *)&args[1]);

            pthread_join(th[0], NULL);
            pthread_join(th[1], NULL);

            if ((thread1Occurence + thread2Occurence) == 0) {
                printf("\nNumber not found\n");
            } else {
                printf("\nNumber found and occurence is %d\n", (thread1Occurence + thread2Occurence));
            }
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
