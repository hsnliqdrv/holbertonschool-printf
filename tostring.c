#include "main.h"
#include <stdlib.h>
/**
 * to_upper - convert char to upper case
 * @c: character
 *
 * Return: upper case
 */
char to_upper(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}
/**
 * get_digits - gets digits from base
 * @base: base number
 *
 * Return: string containing digits
 */
char *get_digits(unsigned int base)
{
	char *digits = "";

	switch (base)
	{
		case 2:
			digits = "01";
			break;
		case 8:
			digits = "01234567";
			break;
		case 10:
			digits = "0123456789";
			break;
		case 16:
			digits = "0123456789abcdef";
	}
	return (digits);
}
/**
 * base_tostring - convert unsigned to different bases
 * @n: unsigned int
 * @base: base
 * @upper: if convert in upper case
 *
 * Return: string
 */
char *base_tostring(unsigned int n, unsigned int base, int upper)
{
	char *digits = get_digits(base), c, *s;
	unsigned int l = 1, i = 0;
	unsigned int m = 1, num = n;

	while (num > 0)
	{
		l++;
		num /= base;
		m *= base;
	}
	m /= base;
	s = malloc(l + 1);
	assert(s != NULL);
	while (m > 0)
	{
		c = digits[n / m % base];
		c = upper ? to_upper(c) : c;
		s[i] = c;
		i++;
		m /= base;
	}
	if (i == 0)
		s[0] = digits[0];
	s[l] = '\0';
	return (s);
}
/**
 * int_tostring - integer as string
 * @n: integer to be converted
 *
 * Return: string representation
 */
char *int_tostring(int n)
{
	char *s = malloc(12);
	unsigned int num = n >= 0 ? n : -n;
	unsigned int m = 1000000000, i = 0, k;

	assert(s != NULL);
	while (m > num)
		m /= 10;
	if (n < 0)
	{
		s[0] = '-';
		i++;
	}
	while (m > 0)
	{
		k = num / m % 10;
		if (k == 0 && i == (n < 0))
		{
			m /= 10;
			continue;
		}
		s[i] = '0' + k;
		i++;
		m /= 10;
	}
	s[i] = '\0';
	return (s);
}
/**
 * ptr_tostring - pointer to string
 * @ptr: pointer
 *
 * Return: pointer as hex
 */
char *ptr_tostring(void *ptr)
{
	int i, p = 0, f = 0;
	unsigned char *cp = (unsigned char *) &ptr, c;
	char *s, *ss;

	if (!ptr)
		return (_strdup("(nil)"));
	s = malloc(19);
	assert(s != NULL);
	s[0] = '0';
	s[1] = 'x';
	for (i = 0; i < 8; i++)
	{
		c = cp[7 - i];
		if (!f && i < 2)
		{
			if (!c)
				continue;
			else
				f = 1;
		}
		ss = base_tostring(c, 16, 0);
		s[2 * (p + 1)] = ss[1] ? ss[0] : '0';
		s[2 * (p + 1) + 1] = ss[1] ? ss[1] : ss[0];
		p++;
		free(ss);
	}
	return (s);
}
