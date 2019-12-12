#include "definition.h"

int main(void)
{
    poly_elem *a, *b, *result;
    create_poly(a);
    print_poly(a);
    create_poly(b);
    print_poly(b);
    poly_times(a, b, result);
    cout << "result" << endl;
    print_poly(result);
    return 0;
}

status print_poly(poly_elem *a)
{
    a = a->next;
    while (a != NULL)
    {
        cout << a->coef << '*' << "x^" << a->expo;
        if (a->next != NULL)
        {
            cout << '+';
        }
        a = a->next;
    }
    cout << endl;
    return ok;
}

void free_poly(poly_elem *&a)
{
    poly_elem *p, *q;
    p = a;
    q = p->next;
    while (q != NULL)
    {
        free(p);
        p = q;
        q = p->next;
    }
}

status poly_times(poly_elem *a, poly_elem *b, poly_elem *&result)
{
    cout << "in poly times" << endl;
    poly_elem *temp_result[3];
    poly_elem *p1, *q1, *p2, *p;
    p1 = a->next;
    q1 = p1->next;
    p2 = b->next;
    temp_result[0] = (poly_elem *)malloc(sizeof(poly_elem));
    p = temp_result[0];
    p->next = NULL;
    while (p2 != NULL)
    {
        p->next = (poly_elem *)malloc(sizeof(poly_elem));
        p = p->next;
        p->next = NULL;
        p->coef = p2->coef * p1->coef;
        p->expo = p2->expo + p1->expo;
        p2 = p2->next;
    }
    cout << "temp[0] is";
    print_poly(temp_result[0]);
    while (q1 != NULL)
    {
        temp_result[1] = (poly_elem *)malloc(sizeof(poly_elem));
        p = temp_result[1];
        p->next = NULL;
        p2=b->next;
        while (p2 != NULL)
        {
            p->next = (poly_elem *)malloc(sizeof(poly_elem));
            p = p->next;
            p->next = NULL;
            p->coef = p2->coef * q1->coef;
            p->expo = p2->expo + q1->expo;
            p2 = p2->next;
        }
        cout << "temp[1] is";
        print_poly(temp_result[1]);
        poly_plus(temp_result[0], temp_result[1], temp_result[2]);
        free_poly(temp_result[0]);
        free_poly(temp_result[1]);
        temp_result[0] = temp_result[2];
        temp_result[2] = NULL;
        cout << "temp[0] is";
        print_poly(temp_result[0]);
        q1 = q1->next;
    }
    result = temp_result[0];
    return ok;
}

status create_poly(poly_elem *&my_poly)
{
    int n;
    cout << "input the number of the elem" << endl;
    cin >> n;
    int i;
    poly_elem *p;
    my_poly = (poly_elem *)malloc(sizeof(poly_elem));
    my_poly->next = NULL;
    for (i = 0, p = my_poly; i < n; i++)
    {
        p->next = (poly_elem *)malloc(sizeof(poly_elem));
        p = p->next;
        cout << "input the expo" << endl;
        cin >> p->expo;
        cout << "input the coef" << endl;
        cin >> p->coef;
        p->next = NULL;
    }
    return ok;
}

status poly_plus(poly_elem *a, poly_elem *b, poly_elem *&result)
{
    poly_elem *p1, *p2, *p3;
    result = (poly_elem *)malloc(sizeof(poly_elem));
    result->next = NULL;
    p3 = result;
    p1 = a->next;
    p2 = b->next;
    while ((p1 != NULL) || (p2 != NULL))
    {
        p3->next = (poly_elem *)malloc(sizeof(poly_elem));
        p3 = p3->next;
        p3->next = NULL;
        if (p2 == NULL)
        {
            p3->expo = p1->expo;
            p3->coef = p1->coef;
            p1 = p1->next;
        }
        else if (p1 == NULL)
        {
            p3->expo = p2->expo;
            p3->coef = p2->coef;
            p2 = p2->next;
        }
        else if (p1->expo > p2->expo)
        {
            p3->expo = p1->expo;
            p3->coef = p1->coef;
            p1 = p1->next;
        }
        else if (p2->expo > p1->expo)
        {
            p3->expo = p2->expo;
            p3->coef = p2->coef;
            p2 = p2->next;
        }
        else
        {
            p3->expo = p1->expo;
            p3->coef = p1->coef + p2->coef;
            p1 = p1->next;
            p2 = p2->next;
        }
    }
    return ok;
}
