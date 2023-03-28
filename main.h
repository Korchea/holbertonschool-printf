#ifndef __main_h__
#define __main_h__

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int _printf(const char *format, ...);

typedef struct format
{
	char c;
	int (*f)(va_list ap);
} format_t;

#endif
