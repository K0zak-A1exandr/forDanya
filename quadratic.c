#include <stdio.h>
#include <math.h>
#include <assert.h>
double a  = NAN;
double b  = NAN;
double c  = NAN;
double x2 = NAN;
double x1 = NAN;
enum NRoots_e
{
    INF_ROOTS     = 4,
    ONE_ROOTS     = 1,
    TWO_ROOTS     = 2,
    NO_ROOTS      = 0,
    SAME_ROOTS    = 3,
};


int main()
{   
   printf("             \n"
           "a*x^2+b*x+c  \n"
           "enter a b c: \n");
    solver();
}
int is_zero(double u)
{
    return fabs(u) < 0.000001;
}

int solver()
{   


    double a  = NAN;
    double b  = NAN;
    double c  = NAN;
    double x2 = NAN;
    double x1 = NAN;
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