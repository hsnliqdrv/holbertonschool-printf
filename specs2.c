#include "main.h"
#include <stdlib.h>
/**
 * spec_u - specifier printer
 * @list: argument list
 *
 * Return: string representation
 */
char *spec_u(va_list list)
{
	return (base_tostring(va_arg(list, unsigned int), 10, 0));
}
/**
 * spec_o - specifier printer
 * @list: argument list
 *
 * Return: string representation
 */
char *spec_o(va_list list)
{
	return (base_tostring(va_arg(list, unsigned int), 8, 0));
}
/**
 * spec_x - specifier printer
 * @list: argument list
 *
 * Return: string representation
 */
char *spec_x(va_list list)
{
	return (base_tostring(va_arg(list, unsigned int), 16, 0));
}
/**
 * spec_X - specifier printer
 * @list: argument list
 *
 * Return: string representation
 */
char *spec_X(va_list list)
{
	return (base_tostring(va_arg(list, unsigned int), 16, 1));
}
