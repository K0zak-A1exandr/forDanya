#include <stdio.h>
#include <math.h>
#include <assert.h>
#include "quadratic.h"

double a  = NAN;
double b  = NAN;
double c  = NAN;
double x2 = NAN;
double x1 = NAN;



int main()
{   
   printf("             \n"
           "a*x^2+b*x+c  \n"
           "enter a b c: \n");
    solver();
}