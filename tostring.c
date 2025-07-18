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
 * base_tostring - convert unsigned to different bases
 * @n: unsigned int
 * @base: base
 * @upper: if convert in upper case
 *
 * Return: string
 */
char *base_tostring(unsigned int n, unsigned int base, int upper)
{
	char *digits, c, *s;
	unsigned int l = 1, num = n, m = 1, i = 0;
	
	while (num > 0)
	{
		l++;
		num /= base;
		m *= base;
	}
	m /= base;
	s = malloc(l + 1);
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
