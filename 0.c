#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * print - prints characters
 * @s: string
 *
 * Return: number of characters printed
 */
int print(const char *s)
{
	int l;

	if (!s)
	{
		write(STDOUT_FILENO, "(null)", 6);
		return (6);
	}
	l = _strlen(s);
	write(STDOUT_FILENO, s, l);
	return (l);
}
/**
 * _printf - printf func
 * @format: a character string
 *
 * Return: number of characters printed,
 * excluding null byte
 */
int _printf(const char *format, ...)
{
	va_list list;
	char c, *s;
	int i = 0, count = 0;

	if (format[_strlen(format) - 1] == '%')
		return (-1);
	va_start(list, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			switch (format[i + 1])
			{
				case 'c':
					c = va_arg(list, int);
					count += write(STDOUT_FILENO, &c, 1);
					break;
				case 's':
					s = va_arg(list, char *);
					count += print(s);
					break;
				case '%':
					count += print("%");
					break;
				default:
					count += write(STDOUT_FILENO, "%", 1);
					count += write(STDOUT_FILENO, format + i + 1, 1);
			}
			i += 2;
		}
		else
		{
			count += write(STDOUT_FILENO, format + i, 1);
			i++;
		}
	}
	va_end(list);
	return (count);
}
