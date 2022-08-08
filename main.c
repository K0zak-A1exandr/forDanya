// unit_tests в отдельный .h файл и .c файл
// 
// 

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "quadratic.h"
#include "unit_test.h"

int main()
{   
    printf("              \n"
           "a*x^2+b*x+c   \n"
           "enter a b c:  \n");


    //int giga = unit_test(a, b, c, &x1, &x2);
    //int numsRot = solver(a, b, c, &x1, &x2);
    double a = NAN;
    double b = NAN; 
    double c = NAN; 
    double x1 = NAN;
    double x2 = NAN;


    solver(a, b, c, &x1, &x2);

}
