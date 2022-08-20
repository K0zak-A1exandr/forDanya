// GitHub
/**
 @file
 ыыыыы
 */

/*!
     \brief Говорящие константы, отвечающие за количество решений       
 */
enum NRoots_e 
{
    NO_ROOTS      = 0,
    ONE_ROOTS     = 1,
    TWO_ROOTS     = 2,
    INF_ROOTS     = 3,
};

/*!
     \brief Функция-отец, связывающая другие в одно целое
     Заносит значения a b c в функцию, решающую квадратное уравнение
     Содержит                 
 */
int solver(double a, double b, double c, double *x1, double *x2);


/*!
     \brief функция, решающая дискриминант   


 */
void solve_discr(); 

/*!
     \brief функция, решающая квадратное уравнение          
 */
int solve_square(double a, double b, double c, double *x1, double *x2);

/*!
     \brief Сравнивает значение с нулём                 
 */
int is_zero(double u);

/*!
     \brief функция, которая выводит решения                 
 */
int print_roots (int numRoots, double x1, double x2);

/*!
     \brief Подфункция, решающая линейное уравнение                
 */
int solve_linear(double b, double c, double *x1);

/*!
     \brief функция, котрая считывает коефициенты                
 */
double coef_read();

/*!
    \brief очищает буфер ввода
*/
void flush_input_buffer();

