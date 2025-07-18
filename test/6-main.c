#include "main.h"
#include <stdio.h>

/**
 * main - main function
 * Return: 0 when success, 1 when error
 */
int main()
{
	int a, b;
	a = _printf("%p\n", &a);
	printf("\nReturn: %d\n", a);
	b = printf("%p\n", &a);
	printf("\nReturn: %d\n", b);
	return (0);
}
