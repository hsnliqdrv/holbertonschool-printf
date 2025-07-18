#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

/**
 * struct pair_s - pair structure
 * @c: character
 * @f: function
 */
typedef struct pair_s
{
        char c;
        char *(*f)(va_list);
} pair_t;

unsigned int _strncpy(char *, const char *, unsigned int);

int print(const char *s);
int _printf(const char *format, ...);
int _strlen(const char *s);
char *int_tostring(int n);
char *base_tostring(unsigned int n, unsigned int base, int upper);

char *spec_c(va_list);
char *spec_s(va_list);
char *spec_per(va_list);
char *spec_int(va_list);
char *spec_b(va_list);
char *spec_u(va_list);
char *spec_o(va_list);
char *spec_x(va_list);
char *spec_X(va_list);

#endif
