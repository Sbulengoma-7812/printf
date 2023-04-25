#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>

typedef struct format
{
	char a;
	int (*f)(va_list, int);
} type1;

int print_char(va_list a, int base);
int print_string(va_list a, int base);
int print_strings(char *a);
void my_reverse(char str[], int len);
int my_itoa(va_list ap, int base);
int my_utoa(va_list ap, int base);
int _printf(const char * const format, ...);
#endif
