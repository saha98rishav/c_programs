#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

typedef struct
{
    Node *head;
    Node *tail;
    int size;
} Queue;

Queue *createQueue();
int size(Queue *queue);
bool isEmpty(Queue *queue);
int peek(Queue *queue, bool *status);
void enQueue(Queue *queue, int value);
int deQueue(Queue *queue, bool *status);
void destroyQueue(Queue *queue);

int main() {
    Queue *queue = createQueue();

    if (isEmpty(queue))
        printf("Queue is empty.\n");

    enQueue(queue, 4);

    if (!isEmpty(queue))
        printf("Queue is not empty.\n");

    enQueue(queue, 5);
    enQueue(queue, 6);

    printf("Queue size: %d\n", size(queue));

    bool status = false;
    int value = 0;

    value = peek(queue, &status);
    if (status)
        printf("Peek successful: %d\n", value);

    value = deQueue(queue, &status);
    if (status)
        printf("Dequeue succesful: %d\n", value);

    value = peek(queue, &status);
    if (status)
        printf("Peek successful: %d\n", value);

    value = deQueue(queue, &status);
    if (status)
        printf("Dequeue succesful: %d\n", value);

    value = peek(queue, &status);
    if (status)
        printf("Peek successful: %d\n", value);

    value = deQueue(queue, &status);
    if (status)
        printf("Dequeue succesful: %d\n", value);

    value = peek(queue, &status);
    if (!status)
        printf("Peek unsuccessful.\n");

    value = deQueue(queue, &status);
    if (!status)
        printf("Dequeue unsuccesful.\n");

    destroyQueue(queue);
    return 0;
}

Queue *createQueue() {
    Queue *queue = malloc(sizeof(Queue));
    queue->head = NULL;
    queue->tail = NULL;
    queue->size = 0;

    return queue;
}

int size(Queue *queue) {
    return queue->size;
}

bool isEmpty(Queue *queue) {
    return (queue->size == 0);
}

int peek(Queue *queue, bool *status) {
    if (isEmpty(queue)) {
        *status = false;
        return 0;
    }
    *status = true;
    return queue->head->value;
}

void enQueue(Queue *queue, int value) {
    Node *newNode = malloc(sizeof(Node));

    newNode->value = value;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        queue->head = newNode;
        queue->tail = newNode;
    } else {
        queue->tail->next = newNode;
        queue->tail = newNode;
    }

    queue->size += 1;
}

int deQueue(Queue *queue, bool *status) {
    if (isEmpty(queue)) {
        *status = false;
        return 0;
    } else {
        *status = true;
        int value = queue->head->value;
        Node *oldHead = queue->head;
        if (queue->size == 1) {
            queue->head = NULL;
            queue->tail = NULL;
        } else {
            queue->head = queue->head->next;
        }
        free(oldHead);
        queue->size -= 1;
        return value;
    }
}

void destroyQueue(Queue *queue) {
    Node *currentNode = queue->head;

    while (currentNode != NULL) {
        Node *temp = currentNode;
        currentNode = currentNode->next;
        free(temp);
    }
    free(queue);
}