#include "main.h"
#include <stdlib.h>

/**
 * other - 'Print the new lines and commond chars.'
 * @b: Is a char.
 * @c: Is the next char.
 */

void other(char b, char c)
{
	char nl = '\n';

	if (b == 92 && c == 110)
	{
		write(1, &nl, 1);
	}
	else
	{
		write(1, &b, 1);
	}
}

/**
 * casechar - 'Prints in case char.'
 * @ap: Variable in list.
 * Return: Count of prints.
 */

int casechar(va_list ap)
{
	char c = va_arg(ap, int);

	write(1, &c, 1);
	return (1);
}

/**
 * casestring - 'Prints in case string.'
 * @ap: Variable in list.
 * Return: Count of prints.
 */

int casestring(va_list ap)
{
	unsigned int m;
	char *s = va_arg(ap, char *);

	if (s == NULL)
		s = "(null)";

	for (m = 0; m < strlen(s); m++)
		write(1, &s[m], 1);

	return (strlen(s));
}

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

int caseint(va_list ap)
{
	int i = va_arg(ap, int);
	int count = 0;

	print_int(i, &count);
	return (count);
}

/**
 * casepersent - 'Prints in case persent.'
 * @ap: Variable in list.
 * Return: Coun
 */
int casepersent(va_list ap __attribute__((unused)))
{
	char c = '%';

	write(1, &c, 1);
	return (1);
}

/**
 * _printf - 'Prints everything you pass.'
 * @format: Is the string that gonna be printed.
 * Return: The number of characters printed.
 */

int _printf(const char *format, ...)
{
	va_list ap;
	unsigned int i = 0, j, k = 0;
	format_t form[] = {
		{'c', casechar},
		{'s', casestring},
		{'%', casepersent},
		{'d', caseint},
		{'i', caseint},
		{0, NULL}
	};

	va_start(ap, format);
	if (format == NULL)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (-1);
			j = 0;
			while (form[j].c != 0)
			{
				if (format[i + 1] == form[j].c)
				{
					i++;
					k += form[j].f(ap);
					break;
				}
				j++;
			}
			if (form[j].c == 0)
			{
				other(format[i], format[i + 1]);
				k++;
			}
		}
		else
		{
			other(format[i], format[i + 1]);
			k++;
		}
		i++;
	}
	va_end(ap);
	return (k);
}
