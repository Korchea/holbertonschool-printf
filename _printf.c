#include "main.h"

/**
 * _printf - 'Prints everything you pass.'
 * @format: Is the string that gonna be printed.
 * Return: The number of characters printed.
 */

int _printf(const char *format, ...)
{
	va_list ap;
	unsigned int i = 0, count = 0;

	va_start(ap, format);
	if (format == NULL)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (-1);
			count += get_format(format, ap, &i);
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
