#include <unistd.h>

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
 * print_base - prints unsigned as different bases
 * @n: unsigned int
 * @base: base
 * @upper: if print in upper case
 *
 * Return: number of characters
 */
int print_base(unsigned int n, unsigned int base, int upper)
{
        int count = 0;
	char *digits, c;

	switch(base)
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
        if (n / base)
                count += print_base(n / base, base, upper);
	c = digits[n % base];
	c = upper ? to_upper(c) : c;
        count += write(1, &c, 1);
        return (count);
}
