#include <unistd.h>
/**
 * print_binary - prints unsigned as binary
 * @n: unsigned int
 *
 * Return: number of characters
 */
int print_binary(unsigned int n)
{
        int count = 0;

        if (n / 2)
                count += print_binary(n / 2);

        count += write(1, &"01"[n % 2], 1);

        return (count);
}
