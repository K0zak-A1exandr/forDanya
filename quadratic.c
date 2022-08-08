// GitHub




#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "quadratic.h"


double coef_read()
{
    double x = NAN;
    int numb_in = -1;
    char scan_end = NAN;

    while(1)
    {
        printf("coef = ");
        numb_in = scanf ("%lg", &x);
        scan_end = getchar();

        if (!isfinite (x) || numb_in != 1 || scan_end != '\n')
        {
            printf ("Wrong input\n");
            clear_input ();
        }
        else
            return x;
    }
    return NAN;
}



void clear_input ()
{
    while (getchar () != '\n') { ; }
}

int is_zero(double u)
{
    double EPSILON = 0.000001;
    return fabs(u) < EPSILON;
}

int solver(double a, double b, double c, double *x1, double *x2)
{
    a = coef_read();
    b = coef_read();
    c = coef_read();
    printf("\n\ncoefs: %lg %lg %lg", a, b, c);
    int numRoots = solve_square(a, b, c, x1, x2); 
    print_roots (numRoots, *x1, *x2);
}

int solve_square(double a, double b, double c, double *x1, double *x2)
{
    if(is_zero(a))
    {
        if(is_zero(b))
        {
            if(is_zero(c))
            {
                return INF_ROOTS;
            }
            else
            {
                return NO_ROOTS;
            }
        }
        else
        {  
            //printf("%lg %lg\n", b, c);
            *x1 = - c / b; 
            return ONE_ROOTS;
        }
    }
    else
    {
        double discr = (b * b - 4 * a * c);
        double sqrtD = sqrt(discr);
        double two_a = 2 * a;
        if (discr > 0)
        {
            *x1 = ( - b + sqrtD) / two_a; 
            *x2 = ( - b - sqrtD) / two_a;
            return TWO_ROOTS;
        }
        else
        {
            if(is_zero(discr))
            {
                if(is_zero(c))
                {
                    return INF_ROOTS;
                }
                else
                {
                    *x1 = *x2 = - b / (2 * a);  
                    return TWO_ROOTS;
                }
            }
            else
            {  
                return NO_ROOTS;
            }
        }
    }
}
int print_roots (int numRoots, double x1, double x2) {
    switch (numRoots) 
    {
        case NO_ROOTS:
            printf(" No Solution\n");
            break;
        case ONE_ROOTS:
            printf(" x = %lg\n", x1 );
            break;
        case TWO_ROOTS:
            printf(" x1 = %lg\n x2 = %lg\n", x1, x2); 
            break;
        case INF_ROOTS:
            printf(" Any number\n");
            break;
        default:
            printf ("ERROR: expected 0-3 roots, received: %d\n", numRoots);
            break;
    }
}
