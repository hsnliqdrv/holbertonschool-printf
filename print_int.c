#include "main.h"
#include <unistd.h>

/**
 * print_int - Prints an integer to stdout
 * @n: integer to print
 * Return: number of characters printed
 */
int print_int(int n)
{
	int count = 0;
	unsigned int num;

	if (n < 0)
	{
		count += write(1, "-", 1);
		num = -n;
	}
	else
		num = n;

	if (num / 10)
		count += print_int(num / 10);

	count += write(1, &"0123456789"[num % 10], 1);

	return (count);
}
