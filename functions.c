#include "main.h"

/**
 * casechar - 'Prints in case char.'
 * @ap: Variable in list.
 * Return: Count of printed characters.
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
 * Return: Count of printed characters.
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
 * casepercent - 'Prints in case percent.'
 * @ap: Variable in list.
 * Return: Count of printed characters.
 */
int casepercent(va_list ap __attribute__((unused)))
{
	char c = '%';

	write(1, &c, 1);
	return (1);
}
