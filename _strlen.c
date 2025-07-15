/**
 * _strlen - str length
 * @s: string
 *
 * Return: length of s
 */
int _strlen(const char *s)
{
	int l = 0;

	while (s[l])
		l++;
	return (l);
}
