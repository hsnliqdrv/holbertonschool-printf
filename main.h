#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

/**
 * struct pair_s - pair structure
 * @c: character
 * @f: function
 */
typedef struct pair_s
{
        char c;
        int (*f)(va_list);
} pair_t;

int print(const char *s);
int _printf(const char *format, ...);
int _strlen(const char *s);
int print_int(int n);
int print_base(unsigned int n, unsigned int base, int upper);

int spec_c(va_list);
int spec_s(va_list);
int spec_per(va_list);
int spec_int(va_list);
int spec_b(va_list);
int spec_u(va_list);
int spec_o(va_list);
int spec_x(va_list);
int spec_X(va_list);

#endif
