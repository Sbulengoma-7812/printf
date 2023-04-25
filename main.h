#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * struct format - structure for printing various types
 * @a: type to print
 * @f: function to print
 */

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * struct format - structure for printing various types
 * @a: type to print
 * @f: function to print
 */
typedef struct format
{
	char a;
	int (*f)(va_list, char);
} type1;
int print_char(va_list a, char b);
int print_string(va_list a, char b);
int print_strings(char *a);
void my_reverse(char str[], int len);
int my_itoa(va_list ap, char b);
int my_utoa(va_list ap, char b);
int _printf(const char * const format, ...);
int _fprintf(const char * const format, va_list ap);
#endif
