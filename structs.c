#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char first_name[50];
    char last_name[50];
    int age;
} Student;


void addAgeStudent(Student *s);

int main() {

    Student *s1;

    s1 = malloc(sizeof(Student) * 1);
    s1->age = 20;

    printf("Age: %d\n", s1->age);
    addAgeStudent(s1);
    printf("Age: %d\n", s1->age);

    free(s1);
    return 0;
}

void addAgeStudent(Student *s) {
    s->age += 1;
}