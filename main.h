#ifndef __main_h__
#define __main_h__

/* libraries  */
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/* prototypes  */
int _printf(const char *format, ...);
int casechar(va_list);
int casestring(va_list);
void print_int(long int, int *);
int caseint(va_list);
int casepercent(va_list);
unsigned int _strlen(char *);
void get_format(const char *format, va_list ap, int i, int *count);

/* structures  */
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
