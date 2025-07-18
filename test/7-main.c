#include "main.h"
#include <stdio.h>

/**
 * main - main function
 * Return: 0 when success, 1 when error
 */
int main()
{
	int a;
	a = _printf("%S\n", "Best\nSchool");
	printf("\nReturn: %d\n", a);

	return (0);
}
