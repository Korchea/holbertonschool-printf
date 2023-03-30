#include "main.h"

/**
 * print_int - .
 * @n: .
 * @count: .
 */
void print_int(int n, int *count)
{
	char neg = '-', num;

	if (n < 0)
	{
		write(1, &neg, 1);
		n = -n;
	}
	if (n / 10)
		print_int(n / 10, count);
	num = n % 10 + 48;
	write(1, &num, 1);
	(*count)++;
}

/**
 * caseint - .
 * @ap: .
 * Return: .
 */
int caseint(va_list ap)
{
	int i = va_arg(ap, int);
	int count = 0;

	print_int(i, &count);
	return (count);
}

/**
 * _strlen - Check the code.
 * Description: 'Returns the length of a string.'
 * @s: Is a string.
 * Return: Number of characters.
 */

unsigned int _strlen(char *s)
{
	if (*s != '\0')
	{
		return (1 + _strlen(s + 1));
	}
	return (0);
}
