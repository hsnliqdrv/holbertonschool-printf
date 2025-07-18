#include "main.h"
/**
 * spec_c - specifier printer
 * @list: argument list
 *
 * Return: number of characters printed
 */
int spec_c(va_list list)
{
	char c = va_arg(list, int);

	return (write(STDOUT_FILENO, &c, 1));
}
/**
 * spec_s - specifier printer
 * @list: argument list
 *
 * Return: number of characters printed
 */
int spec_s(va_list list)
{
	return (print(va_arg(list, char *)));
}
/**
 * spec_per - specifier printer
 * @list: argument list
 *
 * Return: number of characters printed
 */
int spec_per(va_list list)
{
	(void) list;
	return (print("%"));
}
/**
 * spec_int - specifier printer
 * @list: argument list
 *
 * Return: number of characters printed
 */
int spec_int(va_list list)
{
	return (print_int(va_arg(list, int)));
}
/**
 * spec_b - specifier printer
 * @list: argument list
 *
 * Return: number of characters printed
 */
int spec_b(va_list list)
{
	return (print_base(va_arg(list, unsigned int), 2, 0));
}
