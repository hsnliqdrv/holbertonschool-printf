#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * print - prints characters
 * @s: string
 *
 * Return: number of characters printed
 */
int print(char *s)
{
	int l = _strlen(s);

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

	va_start(list, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
			{
				write(STDOUT_FILENO, "%", 1);
				count++;
				break;
			}
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
			}
			i += 2;
		}
		else
		{
			write(STDOUT_FILENO, format + i, 1);
			count++;
			i++;
		}
	}
	va_end(list);
	return (count);
}
