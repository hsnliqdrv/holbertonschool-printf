#include "main.h"
#include <stdio.h>

/**
 * main - main function
 * Return: 0 when success, 1 when error
 */
int main()
{
	int a, b;

	a = _printf("%b\n", 98);
	printf(" Return: %d\n", a);
	b = printf("%b\n", 98);
	printf(" Return: %d\n", b);

	return (0);
}
