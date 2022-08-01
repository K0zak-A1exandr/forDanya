#define EPSILON 0.00001 // TODO

enum NRoots_e 
{
    NO_ROOTS      = 0,
    ONE_ROOTS     = 1,
    TWO_ROOTS     = 2,
    INF_ROOTS     = 3,
};

int solver(double a, double b, double c, double *x1, double *x2);

void solve_quadratic(); // TODO

void solve_discr(); // TODO

int solve_square(double a, double b, double c, double *x1, double *x2);

int is_zero(double u);

int print_roots (numRoots, x1, x2);

