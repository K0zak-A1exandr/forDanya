#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "quadratic.h"

void flush_input_buffer()
{
    while (getchar () != '\n') { ; }
}

double coef_read()
{
    double coef = NAN;
    int numb_in = -1;
    int scan_end = -228;

    while(1)
    {
        printf("coef = ");
        numb_in = scanf ("%lg", &coef); //возвращает количество успешно введённых переменных(проверка)
        scan_end = getchar(); // завершил ли пользователь ентер

        if (!isfinite (coef) || numb_in != 1 || scan_end != '\n')
        {
            printf ("Wrong input, try again:\n");
            flush_input_buffer ();
        }
        else
            return coef;
    }
}

int is_zero(double u)
{
    const double EPSILON = 1e-4; 
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
        return solve_linear(b, c, x1);
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
                    *x1 = *x2 = - b / two_a;  
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

int print_roots (int numRoots, double x1, double x2) 
{
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
            printf(" Any number\n");#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "quadratic.h"

void flush_input_buffer()
{
    while (getchar () != '\n') { ; }
}

double coef_read()
{
    double coef = NAN;
    int numb_in = -1;
    int scan_end = -228;

    while(1)
    {
        printf("coef = ");
        numb_in = scanf ("%lg", &coef); //возвращает количество успешно введённых переменных(проверка)
        scan_end = getchar(); // завершил ли пользователь ентер

        if (!isfinite (coef) || numb_in != 1 || scan_end != '\n')
        {
            printf ("Wrong input, try again:\n");
            flush_input_buffer ();
        }
        else
            return coef;
    }
}

int is_zero(double u)
{
    const double EPSILON = 1e-4; 
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
        return solve_linear(b, c, x1);
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
                    *x1 = *x2 = - b / two_a;  
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

int print_roots (int numRoots, double x1, double x2) 
{
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

int solve_linear(double b, double c, double *x1)
{
    if(is_zero(b))
        {
            assert (isfinite (b));    
            assert (isfinite (c));
            assert (x1 != NULL);

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
            *x1 = - c / b; 
            return ONE_ROOTS;
        }
}

            break;
        default:
            printf ("ERROR: expected 0-3 roots, received: %d\n", numRoots);
            break;
    }
}

int solve_linear(double b, double c, double *x1)
{
    if(is_zero(b))
        {
            assert (isfinite (b));    
            assert (isfinite (c));
            assert (x1 != NULL);

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
            *x1 = - c / b; 
            return ONE_ROOTS;
        }
}
