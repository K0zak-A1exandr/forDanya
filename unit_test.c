#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "quadratic.h"
#include "unit_test.h"
#include <stdlib.h>



int unit_test()
{   
    double a = NAN;
    double b = NAN;
    double c = NAN;
    double x_1_expected = NAN;
    double x_2_expected = NAN;
    int n_ans_expected = 0;
    double x_1 = NAN;
    double x_2 = NAN;
    int n_tests;
    int ** tests;
    int i;
    int j;
    
    FILE* input_file = fopen("test.txt", "r");
    fscanf(input_file, "%d", &n_tests);
    printf("got %d tests\n", n_tests);
    
    for (int i = 0; i < 4; i++)
    {   
       

        fscanf(input_file, "%lf %lf %lf", &a, &b, &c);
        fscanf(input_file, "%lf %lf %d", &x_1_expected, &x_2_expected, &n_ans_expected);

        
        int n_ans = solve_square (a, b, c, &x_1, &x_2 );

        //printf("got %d roots , x1 = %lg , x2 = %lg \n\t", n_ans, x_1, x_2);
        if (n_ans_expected == n_ans)
        {
        
            if (is_zero (x_1_expected - x_1) &&
            is_zero (x_2_expected - x_2) ||
            n_ans == 3 || n_ans == 1)
            { 
                printf ("Test number %d - OK\n", i+1);
                printf ("Expected out: x1=%lg x2=%lg n_roots=%d\n", x_1_expected, x_2_expected, n_ans_expected);
                printf ("Real     out: x1=%lg x2=%lg n_roots=%d\n\n", x_1, x_2, n_ans);
            }
            else   
            {
                printf ("ERROR\n");
                printf ("Test number %d - ERROR\n", i+1);
                printf ("In: a=%lg b=%lg c=%lg\n", a, b,c);
                printf ("Expected out: x1=%lg x2=%lg n_roots=%d\n", x_1_expected, x_2_expected, n_ans_expected);
                printf ("Real     out: x1=%lg x2=%lg n_roots=%d\n\n", x_1, x_2, n_ans);
            }
           
        }
        else
        {
            printf ("Test number %d - ERROR\n", i+1);
            printf ("In: a=%lg b=%lg c=%lg\n", a, b,c);
            printf ("Expected out: x1=%lg x2=%lg n_roots=%d\n", x_1_expected, x_2_expected, n_ans_expected);
            printf ("Real     out: x1=%lg x2=%lg n_roots=%d\n\n", x_1, x_2, n_ans);
        }
    }
}
