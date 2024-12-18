#define MAX_STUDENTS 100

enum major { CPSC, MATH, MUSIC };

struct student {
    struct person *p;
    enum major major;
    double gpa;
};

struct student *new_student(struct person *p, enum major m, double gpa);
enum major str2enum(char *s);
char *enum2string(enum major m);
int read_db(char *fn);
struct student *get_student(int i);
struct student *highest_gpa();
