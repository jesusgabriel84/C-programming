#include <stdio.h>
#include <string.h>  // for memcpy
#include <stdlib.h>  // for malloc

struct date {
    int day;
    int month;
    int year;
};

struct student {
    char *name;
    struct date birthdate;
    int points[10];  // points on different exercise rounds
};

void print_person(const struct student *p)
{
    printf("%s, born: %d.%d.%d\n", p->name, p->birthdate.day,
            p->birthdate.month, p->birthdate.year);
    printf("Points: ");
    for (int i = 0; i < 10; i++) {
        printf("%d  ", p->points[i]);
    }
    printf("\n");
};

void update_points(struct student *p, int ptidx, int points)
{
    p->points[ptidx] = points;
}

struct student *create_student(const char *name, int bd, int bm, int by)
{
    // Allocate memory for student structure
    struct student *newstudent = malloc(sizeof(struct student));
    if (newstudent == NULL) {
        return NULL;  // allocating memory did not work
    }

    // Allocate memory for name, and copy the name into right location
    newstudent->name = malloc(strlen(name) + 1);//This is a memory address
    if (newstudent->name == NULL) {
        free(newstudent);  // because it was already allocated
        return NULL;
    }
    strcpy(newstudent->name, name);

    newstudent->birthdate.day = bd;
    newstudent->birthdate.month = bm;
    newstudent->birthdate.year = by;

    // Set the points array to all 0
    memset(newstudent->points, 0, sizeof(int) * 10);

    return newstudent;
}

void release_person(struct student *s)
{
    free(s->name);
    free(s);
}

int main(void)
{
    /* The following sets up Jussi, born 2.3.1996,
    initially zero points on all rounds */
    struct student *jussi = create_student("Jussi", 2, 3, 1996);
    if (jussi == NULL) {
        printf("Creating Jussi failed\n");
        return -1;
    }

    update_points(jussi, 2, 75);
    update_points(jussi, 3, 12);

    print_person(jussi);

    struct student *riitta = create_student("Riitta", 12, 4, 1993);
    if (riitta == NULL) {
        printf("Creating Riitta failed\n");
        return -1;
    }
    update_points(riitta, 0, 100);
    print_person(riitta);

    // free memory dynamically allocated for Jussi and Riitta
    release_person(jussi);
    release_person(riitta);

    return 0;
}