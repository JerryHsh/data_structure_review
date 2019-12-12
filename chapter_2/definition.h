#ifndef DEFINITION_H
#define DEFINITION_H

#include<iostream>
#include<stdlib.h>

const int ok=1;
const int error=0;

using namespace std;

typedef struct element
{
        int coef;
        int expo;
        struct element *next;
}poly_elem;

typedef int status;

status create_poly(poly_elem * &my_poly);
status poly_plus(poly_elem *a,poly_elem *b,poly_elem*&result);
status poly_times(poly_elem* a,poly_elem*b,poly_elem *&result);
void free_poly(poly_elem *&a);
status print_poly(poly_elem *a);

#endif // !DEFINITION_H
