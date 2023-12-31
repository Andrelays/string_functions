/*!
\file
\brief Header файл с макросом MYASSERT и списком возможных ошибок
*/

#ifndef MYASSERT_H_INCLUDED
#define MYASSERT_H_INCLUDED

#include"colors.h"

//#define DEBUG

#ifdef DEBUG
/// Макрос, используемый для нахождения логических ошибкок, похож на assert, но в случае ошибки завершает функцию, а не программу, печатает файл, строку, функцию, в которой произошла ошибка и номер ошибки
#define MYASSERT(condition, error_code, finish)                                                                     \
 do {                                                                                                               \
    if (!(condition))                                                                                               \
    {                                                                                                               \
        printf(MAGENTA "suddenly: Logical error: Error code: %d\n", error_code);                                    \
        printf("File: %s\n" "line: %d\n" "Function: %s\n" RESET_COLOR, __FILE__, __LINE__, __PRETTY_FUNCTION__);    \
                                                                                                                    \
        finish;                                                                                                     \
    }                                                                                                               \
}  while(0)

#else
#define MYASSERT(condition, error_code, finish)

#endif

/// Список возможных ошибок, которые печатает MYASSERT
enum errors_code {
    NON_FINITE_NUM_PASSED_TO_FUNC   = 1,///< Указывает, что в функцию было передано не конечное число
    NULL_POINTER_PASSED_TO_FUNC     = 2,///< Указывает, что в функцию был передан 0 указатель
    EQUAL_POINTERS_PASSED_TO_FUNC   = 3 ///< Указывает, что в функцию были переданы равные указатели
};


#endif // MYASSERT_H_INCLUDED
