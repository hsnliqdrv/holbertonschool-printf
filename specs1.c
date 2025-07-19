#include "main.h"
#include <stdlib.h>
/**
 * spec_c - specifier printer
 * @list: argument list
 * @flags: flag string
 *
 * Return: string representation
 */
char *spec_c(va_list list, char *flags)
{
	char *s = malloc(2);

	(void) flags;
	assert(s != NULL);
	s[0] = va_arg(list, int);
	s[1] = '\0';
	return (s);
}
/**
 * spec_s - specifier printer
 * @list: argument list
 * @flags: flag string
 *
 * Return: string representation
 */
char *spec_s(va_list list, char *flags)
{
	char *str = va_arg(list, char *);
	int l = _strlen(str);
	char *s = malloc(l + 1);

	(void) flags;
	assert(s != NULL);
	_strncpy(s, str, l);
	s[l] = '\0';
	return (s);
}
/**
 * spec_per - specifier printer
 * @list: argument list
 * @flags: flag string
 *
 * Return: string representation
 */
char *spec_per(va_list list, char *flags)
{
	char *s = malloc(2);

	(void) flags;
	assert(s != NULL);
	(void) list;
	s[0] = '%';
	s[1] = '\0';
	return (s);
}
/**
 * spec_int - specifier printer
 * @list: argument list
 * @flags: flag string
 *
 * Return: string representation
 */
char *spec_int(va_list list, char *flags)
{
	int i = 0, num = va_arg(list, int);
	char *ss = int_tostring(num), *s = NULL;

	while (flags[i])
	{
		switch(flags[i])
		{
			case '+':
				if (num < 0)
				{
					return (ss);
				}
				s = concat("+", ss);
				break;
			case ' ':
				if (num < 0)
				{
					return (ss);
				}
				s = concat(" ", ss);
				break;
		}
		i++;
	}
	if (s)
	{
		free(ss);
		return (s);
	}
	return (ss);
}
/**
 * spec_b - specifier printer
 * @list: argument list
 * @flags: flag string
 *
 * Return: string representation
 */
char *spec_b(va_list list, char *flags)
{
	unsigned int a = va_arg(list, unsigned int);
	char *s = base_tostring(a, 2, 0);

	(void) flags;
	return (s);
}
