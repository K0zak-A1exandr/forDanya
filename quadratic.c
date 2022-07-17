
#define EPSILON 0.00001

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
enum NRoots_e
{
    INF_ROOTS     = 4,
    ONE_ROOTS     = 1,
    TWO_ROOTS     = 2,
    NO_ROOTS      = 0,
    SAME_ROOTS    = 3,
};




int is_zero(double u)
{
    return fabs(u) < EPSILON;
}

int solver(double a, double b, double c, double *x1, double *x2)
{   
int result = scanf ("%lg %lg %lg", &a, &b, &c);
    if (result < 3)
    {
        printf("Did your cat walk on the keyboard?\n");
        return 0;
    }
        assert(a != NAN || b != NAN || c != NAN);
    int numRoots = solve_square(a, b, c, &x1, &x2);
            switch(numRoots)
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
            case SAME_ROOTS:
                printf(" x1 = x2 = %lg\n", x1);
                break;
            }
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
        {   printf("shit");
            *x1 = - c / b;
            return ONE_ROOTS;
        }
    }
    else
    {
        double discr = (b * b - 4 * a * c);
        if (discr > 0)
        {
            *x1 = ( - b + sqrt(discr)) / (2 * a);
            *x2 = ( - b - sqrt(discr)) / (2 * a);
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
                    *x1 = - b / (2 * a);
                    return SAME_ROOTS;
                }
            }
            else
            {  
                return NO_ROOTS;
            }
        }
    }
    return 0;
}
