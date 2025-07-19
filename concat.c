#include "main.h"
#include <stdlib.h>
/**
 * included - cheeck if char included in string
 * @s: string
 * @c: char
 *
 * Return: 0 if not included, 1 if included
 */
int included(char *s, char c)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}
/**
 * concat - concatenates strings
 * @s1: string 1
 * @s2: string 2
 *
 * Return: concatenated string
 */
char *concat(char *s1, char *s2)
{
	int l1 = _strlen(s1), l2 = _strlen(s2);
	char *s = malloc(l1 + l2 + 1);

	assert(s != NULL);
	_strncpy(s, s1, l1);
	_strncpy(s + l1, s2, l2);
	s[l1 + l2] = '\0';
	return (s);
}
