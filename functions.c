#include "main.h"

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
	unsigned int i;
	char *s = va_arg(ap, char *);

	if (s == NULL)
		s = "(null)";

	for (i = 0; i < _strlen(s); i++)
		write(1, &s[i], 1);

	return (_strlen(s));
}

/**
 * casepersent - 'Prints in case persent.'
 * @ap: Variable in list.
 * Return: Count of prints.
 */
int casepercent(va_list ap __attribute__((unused)))
{
	char c = '%';

	write(1, &c, 1);
	return (1);
}
