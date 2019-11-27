#include <stdio.h>
#include <string.h>  // for memcpy
#include <stdlib.h>  // for malloc

struct date {
    int day;
    int month;
    int year;
};

struct student {
    const char *name;
    struct date birthdate;
    int points[10];  // points on different exercise rounds
};

void print_array(const struct student *a)
{
    for (int i = 0; a[i].name != NULL; i++) {
        printf("%s, born: %d.%d.%d\n", a[i].name, a[i].birthdate.day,
                a[i].birthdate.month, a[i].birthdate.year);
        printf("Points: ");
        for (int j = 0; j < 10; j++) {
            printf("%d  ", a[i].points[j]);
        }
        printf("\n");
    }
};

void update_points(struct student *p, int ptidx, int points)
{
    p->points[ptidx] = points;
}

struct student *add_student(struct student *array, const char *name, int bd, int bm, int by)
{
    int i;
    // Increase i until we arrive at array member with NULL name
    for (i = 0; array[i].name != NULL; i++);

    // Increase size of the array by one, and reserve space for final NULL member
    struct student *newarray = realloc(array, sizeof(struct student) * (i + 2));
    if (newarray == NULL) {
        return NULL; // allocating memory did not work
    }

    newarray[i].name = name;  // this time we assume constant name
    newarray[i].birthdate.day = bd;
    newarray[i].birthdate.month = bm;
    newarray[i].birthdate.year = by;

    // Set the points array to all 0
    memset(newarray[i].points, 0, sizeof(int) * 10);

    // Set the new NULL member at end
    newarray[i+1].name = NULL;

    return newarray;
}

int main(void)
{
    // Initialize array with one NULL member
    struct student *array = malloc(sizeof(struct student));
    array[0].name = NULL;

    // Add Jussi to array. Realloc in function may have changed the pointer of array
    array = add_student(array, "Jussi", 2, 3, 1996);
    if (array == NULL) {
        printf("Creating Jussi failed\n");
        return -1;
    }

    // update_points wants pointer to an array member. array[0] is Jussi.
    update_points(&array[0], 2, 75);
    update_points(&array[0], 3, 12);

    array = add_student(array, "Riitta", 12, 4, 1993);
    if (array == NULL) {
        printf("Creating Riitta failed\n");
        return -1;
    }
    update_points(&array[1], 0, 100);

    print_array(array);

    // free memory dynamically allocated for Jussi and Riitta
    free(array);

    return 0;
}