// unit_tests в отдельный .h файл и .c файл
// 
// 

#define EPSILON 0.00001 // TODO

#include <stdio.h>
#include <math.h>
#include "quadratic.h"

int main()
{   
   printf("              \n"
           "a*x^2+b*x+c  \n"
           "enter a b c: \n");

    double a = 0;
    double b = 0;
    double c = 0;
    double x1 = 0;
    double x2 = 0;
    int giga = unit_test(a, b, c, &x1, &x2);
    int numsRot = solver(a, b, c, &x1, &x2);

    return 0;
}
