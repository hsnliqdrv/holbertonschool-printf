#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
#include <assert.h>
/**
 * struct pair_s - pair structure
 * @c: character
 * @f: function
 */
typedef struct pair_s
{
        char c;
        char *(*f)(va_list, char *);
} pair_t;

unsigned int _strncpy(char *, const char *, unsigned int);

int included(char *s, char c);
int print(const char *s);
int _printf(const char *format, ...);
int _strlen(const char *s);
char *_strdup(const char *);
char *int_tostring(int n);
char *base_tostring(unsigned int n, unsigned int base, int upper);
char *ptr_tostring(void *);
char *concat(char *, char *);

char *spec_p(va_list, char *);
char *spec_S(va_list, char *);
char *spec_c(va_list, char *);
char *spec_s(va_list, char *);
char *spec_per(va_list, char *);
char *spec_int(va_list, char *);
char *spec_b(va_list, char *);
char *spec_u(va_list, char *);
char *spec_o(va_list, char *);
char *spec_x(va_list, char *);
char *spec_X(va_list, char *);

#endif
