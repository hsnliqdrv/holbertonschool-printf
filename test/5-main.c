#include "main.h"
#include <stdio.h>

/**
 * main - main function
 * @argc: arg count
 * @argv: arg list
 *
 * Return: 0 when success, 1 when error
 */
int main(int argc, char **argv)
{
	int a, b;
	(void) argc;
	a = _printf(argv[1]);
	printf("\nReturn: %d\n", a);
	b = printf(argv[1]);
	printf("\nReturn: %d\n", b);

	return (0);
}
