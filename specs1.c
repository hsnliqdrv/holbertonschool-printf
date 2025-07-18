#include "main.h"
#include <stdlib.h>
/**
 * spec_c - specifier printer
 * @list: argument list
 *
 * Return: string representation
 */
char *spec_c(va_list list)
{
	char *s = malloc(2);

	s[0] = va_arg(list, int);
	s[1] = '\0';
	return (s);
}
/**
 * spec_s - specifier printer
 * @list: argument list
 *
 * Return: string representation
 */
char *spec_s(va_list list)
{
	char *str = va_arg(list, char *);
	int l = _strlen(str);
	char *s = malloc(l + 1);

	_strncpy(s, str, l);
	s[l] = '\0';
	return (s);
}
/**
 * spec_per - specifier printer
 * @list: argument list
 *
 * Return: string representation
 */
char *spec_per(va_list list)
{
	char *s = malloc(2);

	(void) list;
	s[0] = '%';
	s[1] = '\0';
	return (s);
}
/**
 * spec_int - specifier printer
 * @list: argument list
 *
 * Return: string representation
 */
char *spec_int(va_list list)
{
	return (int_tostring(va_arg(list, int)));
}
/**
 * spec_b - specifier printer
 * @list: argument list
 *
 * Return: string representation
 */
char *spec_b(va_list list)
{
	unsigned int a = va_arg(list, unsigned int);
	char *s = base_tostring(a, 2, 0);

	return (s);
}
