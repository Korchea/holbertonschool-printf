#include "main.h"

/**
 * get_format - .
 * @format: .
 * @ap: .
 * @a: .
 * @count: .
 */
void get_format(const char *format, va_list ap, int a, int *count)
{
	int i = a, j = 0;
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
		other(format[i], format[i + 1]);
		other(format[i + 1], format[i + 2]);
		(*count)++;
	}
}

/**
 * _printf - 'Prints everything you pass.'
 * @format: Is the string that gonna be printed.
 * Return: The number of characters printed.
 */

int _printf(const char *format, ...)
{
	va_list ap;
	int i = 0, count = 0;

	va_start(ap, format);
	if (format == NULL)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (-1);
			get_format(format, ap, i, &count);
			i++;
		}
		else
		{
			other(format[i], format[i + 1]);
			count++;
		}
		i++;
	}
	va_end(ap);
	return (count);
}
