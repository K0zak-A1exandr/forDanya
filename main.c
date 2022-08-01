// unit_tests в отдельный .h файл и .c файл
// 
// 

#define EPSILON 0.00001 // TODO

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

    double a = 0;
    double b = 0;
    double c = 0;
    double x1 = 0;
    double x2 = 0;
   // int giga = unit_test(a, b, c, &x1, &x2);
   // int numsRot = solver(a, b, c, &x1, &x2);
    solver(a, b, c, &x1, &x2);

    /*char* s = "1\0\04\0\02\0\0-0.585786\0\0-3.41421\0\02";
    char* s1 = s;
    char* s2 = s + 3 * sizeof(char);

    char* strS = "1.12";
    double strD = atof(strS);
    printf("str - %s, double - %g\n", strS, strD);
   
    return 0;*/
}
