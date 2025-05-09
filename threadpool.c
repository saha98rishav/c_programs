#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define THREAD_NUM 4

typedef struct Task {
    void (*taskFunction)(int, int);
    int arg1;
    int arg2;
} Task;

Task taskQueue[256];
int taskCount = 0;

pthread_mutex_t mutexQueue;
pthread_cond_t condQueue;

// void sumAndProduct(int a, int b) {
//     usleep(50000);
//     int sum = a + b;
//     int prod = a * b;
//     printf("The sum and product of %d and %d is %d and %d respectively.\n", a, b, sum, prod);
// }

void sum(int a, int b) {
    usleep(50000);
    int sum = a + b;
    printf("The sum of %d and %d is %d.\n", a, b, sum);
}

void prod(int a, int b) {
    usleep(50000);
    int prod = a * b;
    printf("The product of %d and %d is %d.\n", a, b, prod);
}

void executeTask(Task *task) {
    // usleep(50000);
    // int result = task->a + task->b;
    // printf("The sum of %d and %d is %d\n", task->a, task->b, result);
    task->taskFunction(task->arg1, task->arg2);
}

void submitTask(Task task) {
    pthread_mutex_lock(&mutexQueue);
    taskQueue[taskCount] = task;
    taskCount += 1;
    pthread_mutex_unlock(&mutexQueue);
    pthread_cond_signal(&condQueue);
}

void *startThread(void *args) {
    while (1) {
        Task task;
        int found = 0;
        pthread_mutex_lock(&mutexQueue);

        while (taskCount == 0)
            pthread_cond_wait(&condQueue, &mutexQueue);

        task = taskQueue[0];
        int i;
        for (i = 0; i < taskCount - 1; i += 1)
            taskQueue[i] = taskQueue[i + 1];
        taskCount -= 1;
        pthread_mutex_unlock(&mutexQueue);

        executeTask(&task);
    }
}

int main(int argc, char *argv[]) {

    pthread_t th[THREAD_NUM];

    pthread_mutex_init(&mutexQueue, NULL);
    pthread_cond_init(&condQueue, NULL);

    int i;
    for (i = 0; i < THREAD_NUM; i += 1) {
        if (pthread_create(&th[i], NULL, &startThread, NULL) != 0) {
            perror("Failed to create thread");
        }
    }

    srand(time(NULL));
    for (i = 0; i < 100; i += 1) {
        Task t = {
            .taskFunction = i%2==0 ? &sum : &prod,
            .arg1 = rand() % 100,
            .arg2 = rand() % 100
		};
        submitTask(t);
    }

    for (i = 0; i < THREAD_NUM; i += 1) {
        if (pthread_join(th[i], NULL) != 0) {
            perror("Failed to join thread");
        }
    }

    pthread_mutex_destroy(&mutexQueue);
    pthread_cond_destroy(&condQueue);
    return 0;
}
