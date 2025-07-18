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
/**
 * spec_S - specifier printer
 * @list: argument list
 *
 * Return: string representation
 */
char *spec_S(va_list list)
{
	int l = 0, i = 0, d = 0;
	unsigned char c;
	char *str = va_arg(list, char *), *s, *s2;

	while (str[i])
	{
		c = str[i];
		if (!(c >= 32 && c <= 126))
			l += 4;
		else
			l++;
		i++;
	}
	s = malloc(l + 1);
	assert(s != NULL);
	i = 0;
	while (str[i])
	{
		c = str[i];
		if (!(c >= 32 && c <= 126))
		{
			s[d] = '\\';
			s[d + 1] = 'x';
			s2 = base_tostring(c, 16, 1);
			s[d + 2] = s2[1] ? s2[0] : '0';
			s[d + 3] = s2[1] ? s2[1] : s2[0];
			free(s2);
			d += 4;
		}
		else
		{
			s[d] = str[i];
			d++;
		}
		i++;
	}
	s[l] = '\0';
	return (s);
}
