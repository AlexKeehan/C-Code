#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "person.h"
#include "student.h"

int main() {

    int n_students = read_db("in_students.txt");
    if (n_students < 0) {
        fprintf(stderr, "Could not open: %s\n", "in_students.txt");
        exit(-1);
    }
    printf("Students in Database\n");
    for (int i = 0; i < n_students; i++) {
        struct student *s = get_student(i);
        printf("%s %d %s %lf\n", s->p->name, s->p->age, enum2string(s->major), s->gpa);
    }

    printf("Highest GPA: %s, GPA: %lf\n", highest_gpa()->p->name, highest_gpa()->gpa);
}
