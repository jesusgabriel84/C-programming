#include <assert.h>
#include "vector.h" // to ensure that the interface is compatible

struct vector_st {
    double x, y, z;
};

Vector* vectorCreate(double x, double y, double z)
{
    Vector *v = malloc(sizeof(struct vector_st));
    v->x = x;
    v->y = y;
    v->z = z;
    return v;
}

void vectorFree(Vector *v)
{
    assert(v);  // fails if v is NULL
    free(v);
}

Vector* vectorSum(const Vector *a, const Vector *b)
{
    assert(a); // check that value is not NULL
    assert(b != NULL); // other way to check that value is not NULL
    Vector *ret = malloc(sizeof(struct vector_st));
    ret->x = a->x + b->x;
    ret->y = a->y + b->y;
    ret->z = a->z + b->z;
    return ret;
}
/* ...continues with some other Vector management functions... */