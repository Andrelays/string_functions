/*!
\file
\brief Программа содержит функции, вызываемые в main.cpp чтобы протестировать программу для решения квадратных уравнений
*/

#include "test.h"

FILE * check_isopen (const char file_name[])
{
    MYASSERT(file_name != NULL, NULL_POINTER_PASSED_TO_FUNC, return NULL);

    FILE * file_pointer = NULL;

    if ((file_pointer = fopen (file_name, "r")) == NULL || ferror (file_pointer)) // todo func, check isopen-
        printf("MISTAKE! Could not open the file \"%s\"!\n", file_name);

    return file_pointer;
}

void test()
{
    const char file_name[] = test.txt";

    FILE * file_pointer = check_isopen (file_name);

    if (file_pointer == NULL)
        return;

    int number_tests = 0, index_test = 0;

    fscanf(file_pointer, "%d", &number_tests);

    for (index_test = 0; index_test < number_tests; index_test++)
    {
        double coefficients[3] = {NAN, NAN, NAN};
        enum solutions number_solutions_correct = NOT_VALID;
        double x_1_correct = NAN, x_2_correct = NAN;

        number_solutions_correct = read_test (coefficients, &x_1_correct, &x_2_correct, file_pointer);

        test_equasion (coefficients, x_1_correct, x_2_correct, number_solutions_correct, index_test);
    }
    fclose(file_pointer);
}
