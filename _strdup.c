#include "main.h"
#include <stdlib.h>
/**
 * _strdup - duplicate string
 * @s: string
 *
 * Result: duplicate
 */
char *_strdup(const char *s)
{
	int l = _strlen(s);
	char *dup = malloc(l + 1);

	_strncpy(dup, s, l);
	dup[l] = '\0';
	return (dup);
}
