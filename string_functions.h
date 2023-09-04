#ifndef TEST_H_INCLUDED
#define TEST_H_INCLUDED

#include <stdio.h>

int myputs(const char *str);
char *mystrchr(const char *str, int symbol);
size_t mystrlen(const char *str);
char *mystrcpy(char *str_destination, const char *str_source);
char *mystrncpy(char *str_destination, const char *str_source, size_t count); 
char *mystrcat(char *str_destination, const char *str_source); 
char *mystrncat(char *str_destination, const char *str_source, size_t count);
char *myfgets(char *str, int num_chars, FILE *pointer); 
char *mystrdup(const char *str_source);
size_t mygetline (char **string, size_t *n, FILE *stream);
void print_data(const char *str);


#endif