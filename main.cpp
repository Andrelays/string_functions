#include "string_functions.h"
#include <string.h>
#include <stdlib.h>

int main()
{
    FILE *file_pointer = fopen("file.txt", "r");

    char *str_pointer = NULL;

    size_t n = 0;

    printf("%d", mygetline(&str_pointer, &n, file_pointer));
    
    print_data(str_pointer);

    fclose(file_pointer);

    free(str_pointer);
    return 0;
}