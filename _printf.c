#include "main.h"

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
		{'%', casepercent},
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
