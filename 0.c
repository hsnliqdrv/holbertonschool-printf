#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
/**
 * valid_format - checks if format is valid
 * @format: format string
 *
 * Return: 1 if valid, 0 if invalid
 */
int valid_format(const char *format)
{
	int l = _strlen(format), i = 0;

	while (i < l)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == ' ' || format[i + 1] == '\0')
				return (0);
			i += 2;
		}
		else
			i++;
	}
	return (1);
}

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
 * handle_specifier - handles format specifiers
 * @format: format string
 * @i: pointer to current index
 * @list: list of arguments
 *
 * Return: formatted null-terminated string
 */
char *handle_specifier(const char *format, int *i, va_list list)
{
	char *s;
	int j = 0;
	pair_t array[] = {{'c', spec_c}, {'s', spec_s}, {'%', spec_per},
		{'d', spec_int}, {'i', spec_int}, {'b', spec_b},
		{'u', spec_u}, {'o', spec_o}, {'x', spec_x}, {'X', spec_X},
		{'S', spec_S}, {'p', spec_p}, {0, NULL}};

	while ((array[j].c != 0) && (format[*i + 1] != array[j].c))
		j++;
	if (array[j].f)
		s = array[j].f(list);
	else
	{
		s = malloc(3);
		_strncpy(s, format + *i, 2);
		s[2] = '\0';
	}
	*i += 2;
	return (s);
}

/**
 * _printf - custom printf function
 * @format: format string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	const int buffer_size = 1024;
	char *buffer = malloc(buffer_size);
	va_list list;
	int i = 0, count = 0;

	if (!format || !valid_format(format))
		return (-1);
	va_start(list, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			char *s = handle_specifier(format, &i, list);

			count += _strncpy(buffer + count, s, buffer_size - count);
			free(s);
		}
		else
		{
			if (count < buffer_size)
				buffer[count++] = format[i];
			i++;
		}
	}
	va_end(list);
	write(STDOUT_FILENO, buffer, count);
	free(buffer);
	return (count);
}
