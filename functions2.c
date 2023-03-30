#include "main.h"

/**
 * print_int - 'Print the integer.'
 * @n: Is the int pased on the list.
 * @count: Is the number of printed characters.
 */
void print_int(long int n, int *count)
{
	char neg = '-', num;

	if (n < 0)
	{
		write(1, &neg, 1);
		n = -n;
		(*count)++;
	}
	if (n / 10)
		print_int(n / 10, count);
	num = n % 10 + 48;
	write(1, &num, 1);
	(*count)++;
}

/**
 * caseint - 'Recives the int from the list.'
 * @ap: Is the list.
 * Return: The number of printed characters.
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

/**
 * get_format - 'Search the format of the variable passed by the list.'
 * @format: Is the format of the variables.
 * @ap: Is the list.
 * @i: is the int passed by the list.
 * @count: Is the number of printed character.
 */
void get_format(const char *format, va_list ap, int i, int *count)
{
	int j = 0;
	format_t form[] = {
		{'c', casechar},
		{'s', casestring},
		{'%', casepercent},
		{'d', caseint},
		{'i', caseint},
		{0, NULL}
	};

	while (form[j].c != 0)
	{
		if (format[i + 1] == form[j].c)
		{
			(*count) += form[j].f(ap);
			break;
		}
		j++;
	}
	if (form[j].c == 0)
	{
		write(1, &format[i], 1);
		write(1, &format[i + 1], 1);
		(*count) += 2;
	}
}
