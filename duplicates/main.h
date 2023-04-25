#ifndef MAIN_H
#define MAIN_H

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
<<<<<<< HEAD
int _fprintf(const char * const format, va_list ap);
=======
int _printf(const char *format, ...);
int (*equal(const char *format))(va_list);
int st(va_list a);
int ch(va_list a);
int por(va_list a);
int inte(va_list a);
int _putc(char a);
int bina(va_list a);
int octa(va_list a);
int unsig(va_list a);
int hexal(va_list a);
int hexau(va_list a);
int _write(int file, char *data, int lenght);
int sst(va_list a);
int point(va_list a);
int rot13(va_list a);
int reve(va_list a);
>>>>>>> 820cefbaeea1aa2aec663bcdf3b445524d609764
#endif
