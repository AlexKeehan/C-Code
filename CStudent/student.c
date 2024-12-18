#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "person.h"
#include "student.h"

struct student *students[MAX_STUDENTS] = {0};
int num_students = 0;


// Create new_student(char *name, enum major m, double gpa)
struct student *new_student(struct person *p, enum major m, double gpa) {
    struct student *s = malloc(sizeof(struct student));
    s->p = p;
    s->major = m;
    s->gpa = gpa;
    return s;
}

enum major str2enum(char *s) {
    if (strcmp(s, "CPSC") == 0)
        return CPSC;
    else if (strcmp(s, "MATH") == 0)
        return MATH;
    else
        return MUSIC;
}

static char *majors[] = { "CPSC", "MATH", "MUSIC" };

char *enum2string(enum major m) {
	printf("%s:", majors[m]);
    return majors[m];
}

int read_db(char *fn) {
    int age;
    char name[50], major[50]; 
    double gpa;
    FILE *fin  = fopen(fn,  "r");
    if (fin == NULL)
        return -1;
    while (fscanf(fin, "%s %d %s %lf", name, &age, major, &gpa) != EOF) {
        students[num_students] = new_student(new_person(name, age), str2enum(major), gpa);
	printf("%lf", students[num_students]->gpa);
        num_students++; // count students lines
    }
    fclose(fin); 
    return num_students;
}

struct student *highest_gpa() {
    struct student *highest = students[0];
    for (int i = 0; i < num_students; i++)
        if (students[i]->gpa > highest->gpa)
            highest = students[i];
    return highest;
}

struct student *get_student(int i) {
    if (i >= 0 && i < num_students)
        return students[i];
    return 0;
}
