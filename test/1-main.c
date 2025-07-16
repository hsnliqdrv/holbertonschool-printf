#include "main.h"

/**
 * main - Entry point for testing _printf
 *
 * Return: Always 0
 */
int main(void)
{
	_printf("Number: %d\n", 123);
	_printf("Negative: %i\n", -456);
	_printf("Zero: %d\n", 0);
	_printf("Mix: %d %i %d\n", 1, -2, 345);
	return (0);
}
