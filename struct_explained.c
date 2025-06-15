#include <stdio.h>

typedef struct {
    char name[50];
    int age;
} emp;

typedef struct {
    emp *e;
    char deptname[50];
} dept;

void printEmployee(emp e) {
    printf("Employee name: %s\n", e.name);
    printf("Employee age: %d\n", e.age);
}

void printDepartment(dept d) {
    printf("Department name: %s\n", d.deptname);
    printEmployee(*d.e);
}

int main() {
    emp e1 = {name : "Rishav", age : 26};
    dept accounts = {e : &e1, deptname : "Accounts"};

    // printEmployee(e1);
    printDepartment(accounts);
    return 0;
}