#include "main.h"
#include <stdlib.h>
/**
 * spec_p - specifier printer
 * @list: argument list
 *
 * Return: string representation
 */
char *spec_p(va_list list)
{
	void *ptr = va_arg(list, void *);
	unsigned long long n = (unsigned long long) ptr;
	char *s = malloc(15), *s2;
	int i;

	assert(s != NULL);
	s[0] = '0';
	s[1] = 'x';
	for (i = 2; i < 14; i++)
		s[i] = '0';
	s2 = base_tostring(n, 16, 0);
	_strncpy(s + 14 - _strlen(s2), s2, _strlen(s2));
	s[14] = '\0';
	free(s2);
	return (s);
}
