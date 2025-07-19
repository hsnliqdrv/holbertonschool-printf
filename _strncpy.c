/**
 * _strncpy - copies n characters
 * @dest: dest string
 * @src: source string
 * @n: number of characters
 *
 * Return: number of chars
 */
unsigned int _strncpy(char *dest, const char *src, unsigned int n)
{
	unsigned int i = 0;

	if (!dest || !src)
		return (0);
	for (i = 0; i < n; i++)
	{
		if (!src[i])
			break;
		dest[i] = src[i];
	}
	return (i);
}
