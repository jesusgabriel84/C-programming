#include <stdlib.h>
#include <assert.h>
#include "fraction.h"

/* Algorithm for determining greatest common divisor, needed in (d) */
/* The function returns gcd between the two parameters, u and v */
/* Taken from http://en.wikipedia.org/wiki/Binary_GCD_algorithm */

/* Allocates a new Fraction from heap */
Fraction* setFraction(unsigned int numerator, unsigned int denominator){
    Fraction *f = malloc(sizeof(struct fraction_st));
    f->numerator = numerator;
    f->denominator = denominator;
    return f;
}

/* Returns the numerator of the given fraction */
unsigned int getNum(const Fraction *f){
    return f->numerator;
}

/* Returns the denominator of the given fraction */
unsigned int getDenom(const Fraction *f){
    return f->denominator;
}

/* Releases the Fraction from heap */
void freeFraction(Fraction *f){
    assert(f);  // fails if v is NULL
    free(f);
}

/* Compares two fractions */
int compFraction(const Fraction *a, const Fraction *b){
    int Y;
    int flag;
    Y = (a->numerator*b->denominator)-(a->denominator*b->numerator);
    if (Y>0) flag = 1;
    if (Y<0) flag = -1;
    if (Y==0) flag = 0;
    return flag;
}

/* Adds the given fractions and creates new object for the result */
Fraction* addFraction(const Fraction *a, const Fraction *b){
    Fraction *f = malloc(sizeof(struct fraction_st));
    if(a->denominator==b->denominator) {
        f->numerator=a->numerator+b->numerator;
        f->denominator=a->denominator;
    }
    else{
    f->numerator=(a->numerator*b->denominator)+(b->numerator*a->denominator);
    f->denominator=a->denominator*b->denominator;
    }
    return f;
}

unsigned int gcd(unsigned int u, unsigned int v)
{
    // simple cases (termination)
    if (u == v)
        return u;
 
    if (u == 0)
        return v;
 
    if (v == 0)
        return u;
 
    // look for factors of 2
    if (~u & 1) // u is even
    {
        if (v & 1) // v is odd
            return gcd(u >> 1, v);
        else // both u and v are even
            return gcd(u >> 1, v >> 1) << 1;
    }
 
    if (~v & 1) // u is odd, v is even
        return gcd(u, v >> 1);
 
    // reduce larger argument
    if (u > v)
        return gcd((u - v) >> 1, v);
 
    return gcd((v - u) >> 1, u);
}

/* Reduce fraction */
void reduceFraction(Fraction *val){
    int unsigned factor;
    factor = gcd(val->numerator,val->denominator);
    val->numerator=val->numerator/factor;
    val->denominator=val->denominator/factor;
}