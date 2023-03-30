#ifndef __main_h__
#define __main_h__

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int _printf(const char *format, ...);
void other(char, char);
int casechar(va_list);
int casestring(va_list);
void print_int(long int, int *);
int caseint(va_list);
int casepercent(va_list);
unsigned int _strlen(char *);

/**
 * struct format - struct format
 * @c: format
 * @f: pointer to a function
 */
typedef struct format
{
	char c;
	int (*f)(va_list ap);
} format_t;

#endif
