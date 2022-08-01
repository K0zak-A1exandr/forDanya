// GitHub




#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "quadratic.h"




int is_zero(double u)
{
    return fabs(u) < EPSILON;
}

int solver(double a, double b, double c, double *x1, double *x2)
{
    assert(a != NAN); //TODO три assert'a с указателями    // проверка на ввод числа, иначе выдать ошибку (или попросить заново ввести)
    assert(b != NAN);
    assert(c != NAN);
    int numRoots = solve_square(a, b, c, x1, x2); //assert через define
    print_roots (numRoots, x1, x2);
   /* switch(numRoots)
    {
        case NO_ROOTS:
            printf(" No Solution\n");
            break;
        case ONE_ROOTS:
            printf(" x = %lg\n", *x1 );
            break;
        case TWO_ROOTS:
            printf(" x1 = %lg\n x2 = %lg\n", *x1, *x2); 
            break;
        case INF_ROOTS:
            printf(" Any number\n");
            break;
        default:
            printf("Big brain move\n");
            return 4; //TODO enum с error'om
    }*/
}

int solve_square(double a, double b, double c, double *x1, double *x2)
{   
    if (result < 3)
    {                                                                           //TODO solver_from_keyboard
        printf("Did your cat walk on the keyboard?\n");
        return 0;
    }
    else
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
                printf("%lg %lg\n", b, c);
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
                *x1 = ( - b + sqrtD) / two_a; //TODO в переменную занести discr и по хорошему 2а
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
}
void print_roots (double x1, double x2) {
    switch (numRoots) 
    {
    printf(" No Solution\n");
            break;
        case ONE_ROOTS:
            printf(" x = %lg\n", *x1 );
            break;
        case TWO_ROOTS:
            printf(" x1 = %lg\n x2 = %lg\n", *x1, *x2); 
            break;
        case INF_ROOTS:
            printf(" Any number\n");
            break;
        default:
            printf ("ERROR: expected 0-3 roots, received: %d\n", numRoots);
            break;
    }
}

