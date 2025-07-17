#include "main.h"
#include <stdio.h>

/**
 * main - main function
 * Return: 0 when success, 1 when error
 */
int main()
{
	int a, b;

	a = _printf("%x\n", 15);
	printf(" Return: %d\n", a);
	b = printf("%x\n", 15);
	printf(" Return: %d\n", b);

	return (0);
}
