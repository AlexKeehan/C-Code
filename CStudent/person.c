#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "person.h"
#include "student.h"

// Create new_person(char *name, int age)
struct person *new_person(char *name, int age) {
    struct person *p = malloc(sizeof(struct person));
    p->name = strdup(name);
    p->age = age;
    return p;
}
