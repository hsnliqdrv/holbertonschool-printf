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
	unsigned char *cp = (unsigned char *) &ptr;
	char *s;
	int i;

	if (ptr == NULL)
		return (_strdup("(nil)"));
	s = malloc(15);
	assert(s != NULL);
	s[0] = '0';
	s[1] = 'x';
	for (i = 0; i < 6; i++)
	{
		char *s2 = base_tostring(cp[i], 16, 0);

		s[14 - 2 * (i + 1)] = s2[1] ? s2[0] : '0';
		s[14 - 2 * (i + 1) + 1] = s2[1] ? s2[1] : s2[0];
		free(s2);
	}
	s[14] = '\0';
	return (s);
}
