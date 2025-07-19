#include "main.h"
#include <stdlib.h>
/**
 * spec_p - specifier printer
 * @list: argument list
 * @flags: flag string
 *
 * Return: string representation
 */
char *spec_p(va_list list, char *flags)
{
	void *ptr = va_arg(list, void *);
	char *ss = ptr_tostring(ptr), *s = NULL;
	int i = 0;

	while (flags[i])
	{
		switch(flags[i])
		{
			case '+':
				if (ss[0] != '0')
					return (ss);
				s = concat("+", ss);
				break;
			case ' ':
				if (ss[0] != '0')
					return (ss);
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
