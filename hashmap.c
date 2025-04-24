#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Map structures
typedef struct Node {
    int key;
    int value;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
    Node *tail;
    int size;
} Map;

// Function declarations
Map *createMap();
int size(Map *map);
bool isEmpty(Map *map);
void printMap(Map *map);
Node *isElementPresent(Map *map, int val, bool *status);
void insertIntoMap(Map *map, int value);

// Main function
int main() {
    Map *map = createMap();
    int n;
    printf("Enter 10 numbers to insert into Map:\n");

    for (int i = 0; i < 10; i += 1) {
        scanf("%d", &n);
        insertIntoMap(map, n);
    }
    printf("Here is you Hashmap:\n");
    printMap(map);

    return 0;
}

// Function definitions
Map *createMap() {
    Map *map = malloc(sizeof(map));
    map->head = NULL;
    map->tail = NULL;
    map->size = 0;

    return map;
}

int size(Map *map) {
    return map->size;
}

bool isEmpty(Map *map) {
    return (map->size == 0);
}

void printMap(Map *map) {
    Node *currentNode = map->head;

    while (currentNode != NULL) {
        printf("%d -> %d\n", currentNode->key, currentNode->value);
        currentNode = currentNode->next;
    }
}

Node *isElementPresent(Map *map, int val, bool *status) {
    Node *currentNode = map->head;

    while (currentNode != NULL) {
        if (currentNode->key == val) {
            *status = true;
            return currentNode;
        }
        currentNode = currentNode->next;
    }
    return currentNode;
}

void insertIntoMap(Map *map, int value) {
    if (isEmpty(map)) {
        Node *newNode = malloc(sizeof(Node));
        newNode->key = value;
        newNode->value = 1;
        map->head = newNode;
        map->tail = newNode;
        map->size += 1;
    } else {
        bool status = false;
        Node *node = isElementPresent(map, value, &status);
        if (status) {
            // if element is already present
            // then update the value
            node->value += 1;
        } else {
            // if element is not present
            // insert a node into the map
            Node *newNode = malloc(sizeof(Node));
            newNode->key = value;
            newNode->value = 1;
            map->tail->next = newNode;
            map->tail = newNode;
        }
    }
}