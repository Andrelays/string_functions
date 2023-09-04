#include "string_functions.h"
#include "myassert.h"
#include <malloc.h>

int myputs(const char *str)
{
    MYASSERT(str != NULL, NULL_POINTER_PASSED_TO_FUNC, return EOF);    

    for (size_t index = 0; *(str + index) != '\0' ; index++ )
        putchar(*(str + index));

    putchar('\n');
    
    return 1;        

}

char *mystrchr(const char *str, int symbol)
{
    MYASSERT(str != NULL, NULL_POINTER_PASSED_TO_FUNC, return NULL);

    size_t index = 0;

    for (index = 0; *(str + index) != symbol && *(str + index) != '\0'; index++)
        continue;

    if (*(str + index) == symbol) //todo str++  
        return const_cast<char*>(str + index);
    
    return NULL;
}

size_t mystrlen(const char *str)
{
    MYASSERT(str != NULL, NULL_POINTER_PASSED_TO_FUNC, return 0);

    size_t count = 0;

    for(count = 0; *(str + count) != '\0'; count++) { ; }
    return count;    
}

char *mystrcpy(char *str_destination, const char *str_source)
{
    MYASSERT(str_destination != NULL, NULL_POINTER_PASSED_TO_FUNC, return NULL);
    MYASSERT(str_source      != NULL, NULL_POINTER_PASSED_TO_FUNC, return NULL);

    size_t index = 0;

    for(index = 0; *(str_source + index) != '\0'; index++)
        *(str_destination + index) = *(str_source + index);//todo index not
    
    *(str_destination + index) = '\0';

    return str_destination;
}

char *mystrncpy(char *str_destination, const char *str_source, size_t count)
{
    MYASSERT(str_destination != NULL, NULL_POINTER_PASSED_TO_FUNC, return NULL);
    MYASSERT(str_source      != NULL, NULL_POINTER_PASSED_TO_FUNC, return NULL);

    size_t index = 0; 
    
    for(index = 0; index < count && *(str_source + index) != '\0'; index++)
        *(str_destination + index) = *(str_source + index); 

    while(index < count)
    {
        *(str_destination + index) = '\0';
        index++;
    }
        
    return str_destination;
}

char *mystrcat(char *str_destination, const char *str_source)
{
    MYASSERT(str_destination != NULL, NULL_POINTER_PASSED_TO_FUNC, return NULL);
    MYASSERT(str_source      != NULL, NULL_POINTER_PASSED_TO_FUNC, return NULL);

    size_t index = 0;
    size_t size_destination = 0;

    for(index = 0; *(str_destination + index) != '\0'; index++)
        continue;

    size_destination = index;

    for(index = 0; *(str_source + index) != '\0'; index++)
        *(str_destination + index + size_destination) = *(str_source + index);
    
    *(str_destination + index + size_destination) = '\0';

    return str_destination;
}

char *mystrncat(char *str_destination, const char *str_source, size_t count)
{
    MYASSERT(str_destination != NULL, NULL_POINTER_PASSED_TO_FUNC, return NULL);
    MYASSERT(str_source      != NULL, NULL_POINTER_PASSED_TO_FUNC, return NULL);

    size_t index = 0;
    size_t size_destination = 0;

    for(index = 0; *(str_destination + index) != '\0'; index++)
        continue;

    size_destination = index;

    for(index = 0; index < count && *(str_source + index) != '\0'; index++)
        *(str_destination + index + size_destination) = *(str_source + index);
    
    *(str_destination + index + size_destination) = '\0';

    return str_destination;
}

char *myfgets(char *str, int num_chars, FILE *pointer)
{
    MYASSERT(pointer != NULL, NULL_POINTER_PASSED_TO_FUNC, return NULL);
    MYASSERT(str     != NULL, NULL_POINTER_PASSED_TO_FUNC, return NULL);

    int symbol = 0;
    size_t index = 0; 

    // 1 : 0001
    // -1: 1111 / todo assert
    // -a = ~a + 1

    for(index = 0; index < (size_t) (num_chars - 1) && (symbol = getc(pointer)) != EOF && symbol != '\n'; index++)
        *(str + index) = (char)symbol;
    
    *(str + index) = '\0';

    return str;
}

char *mystrdup(const char *str_source)
{
    MYASSERT(str_source != NULL, NULL_POINTER_PASSED_TO_FUNC, return NULL);

    size_t count = 0;
    size_t index = 0;

    for(count = 0; *(str_source + count) != '\0'; count++)
        continue;

    char *str_destination = (char *) malloc(count);

    MYASSERT(str_destination != NULL, NULL_POINTER_PASSED_TO_FUNC, return NULL);
    
    for(index = 0; index < count; index++)
        *(str_destination + index) = *(str_source + index);

    *(str_destination + index) = '\0';

    return str_destination;     
}

//#define test(func) 
//    if (my##func == func)
//        ok
//    else 
//        error
        
size_t mygetline (char **string, size_t *n, FILE *stream)
{
    MYASSERT(stream != NULL, NULL_POINTER_PASSED_TO_FUNC, return 0);

    if (*string == NULL)
    {
        if (*n > 0)
            *string = (char *) malloc(*n);

        else
        {
            *n = 1;
            *string = (char *) malloc(*n);
         }   
    }

    MYASSERT(*string != NULL, NULL_POINTER_PASSED_TO_FUNC, return 0);

    int symbol = 0;
    size_t index = 0;

    for(index = 0; (symbol = getc(stream)) != EOF && symbol != '\n'; index++)
    {
        if (*n < index + 1)
        {
            *n += 1;
            *string = (char *) realloc(*string, *n);   
        }

        *(*string + index) = (char)symbol;
    }

    *(*string + index) = '\0';

    return (index + 1);
}

void print_data(const char *str)
{
    int symbol = 0;

    while((symbol = getchar()) != '\0')   
        printf("<%c %d>", symbol, symbol);
}