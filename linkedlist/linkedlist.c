#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Linked List structures
typedef struct Node {
    int value;
    struct Node *next;
} Node;

typedef struct List {
    Node *head;
    Node *tail;
    int size;
} List;

// Function declarations
List *createList();
int size(List *list);
bool isEmpty(List *list);
void insertAtEnd(List *list, int value);
void insertAtBeginning(List *list, int value);
void printList(List *list);

// main function
int main() {
    List *list = createList();

    printf("Enter 5 numbers to insert into List at End:\n");
    int n;

    for (int i = 0; i < 5; i += 1) {
        scanf("%d", &n);
        insertAtEnd(list, n);
    }

    printf("Enter 5 numbers to insert into List at Begninning:\n");

    for (int i = 0; i < 5; i += 1) {
        scanf("%d", &n);
        insertAtBeginning(list, n);
    }
    printf("\nPrinting the Linked List:\n");
    printList(list);
    return 0;
}

List *createList() {
    List *list = malloc(sizeof(List));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;

    return list;
}

int size(List *list) {
    return list->size;
}

bool isEmpty(List *list) {
    return (list->size == 0);
}

void insertAtEnd(List *list, int value) {
    Node *newNode = malloc(sizeof(Node));

    newNode->value = value;
    newNode->next = NULL;

    if (isEmpty(list)) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->tail->next = newNode;
        list->tail = newNode;
    }

    list->size += 1;
}

void insertAtBeginning(List *list, int value) {
    Node *newNode = malloc(sizeof(Node));

    newNode->value = value;
    newNode->next = NULL;

    if (isEmpty(list)) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        newNode->next = list->head;
        list->head = newNode;
    }

    list->size += 1;
}

void printList(List *list) {
    Node *currentNode = list->head;

    while (currentNode != NULL) {
        printf("%d\n", currentNode->value);
        currentNode = currentNode->next;
    }
}