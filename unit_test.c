#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include "quadratic.h"
#include "unit_test.h"

int unit_test()
{
    double tests[10][6] = {
        {1,  4,  2,  -0.585786, -3.41421,  2}, // 1
        {0,  0,  0,  0,         0,         -1}, // 2
        {0,  0,  1,  0,         0,         -2}, // 3
        {1,  1,  1,  0,         0,         -2}, // 4
        {1,  1,  1,  0,         1,         -2}, // 5 error
        {1,  12, 12, -1.10102,  -10.899,   2}, // 6
        {2,  5,  3,  -1,        -1.5,      2}, // 7
        {12, 23, 11, -0.916667, -1,        2}, // 8
        {0,  5,  3,  -1.66667,  0,         1}, // 9
        {3,  65, 32, -0.504033, -21.1626,  2}  // 10
    };// a,  b,  c,  x1,        x2,        n_ans

    for (int i = 0; i < 10; i++)
    {
        double x1 = 0, x2 = 0;

        int n_ans = solver (tests[i][0], tests[i][1], tests[i][2], &x1, &x2);

        //printf("got %d roots (ref. %lg), x1 = %lg (ref. %lg), x2 = %lg (ref. %lg)\n\t", n_ans, tests[i][5], x1, tests[i][3], x2, tests[i][4]);

        if (tests[i][5] == n_ans &&
            is_zero (x1 - tests[i][3]) &&
            is_zero (x2 - tests[i][4]))

            printf ("Test number %3d - OK\n", i+1);
        else
        {
            printf ("Test number %3d - ERROR\n", i+1);
            printf ("In: a=%lg b=%lg c=%lg\n", tests[i][0], tests[i][1], tests[i][2]);
            printf ("Expected out: x1=%lg x2=%lg n_roots=%d\n", tests[i][3], tests[i][4], tests[i][5]);
            printf ("Real     out: x1=%lg x2=%lg n_roots=%d\n\n", x1, x2, n_ans);
        }
    }
}