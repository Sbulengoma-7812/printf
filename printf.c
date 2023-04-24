#include "main.h"
#include "printf_functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdbool.h>

/**
 * print_char - putchar()
 * @a: Character to be printed
 * @base: base
(* Return: Return number of characters printed
 */

int print_char(va_list a, int base)
{
	char ap = va_arg(a, int);
	putchar(ap);
	return (1);
}

/**
 * print_string - printf() with string parameter
 * @a: string pointer to be printed
 * @base: base
 (* Return: Return characters printed
 */

int print_string(va_list a, int base)
{
	int counter = 0;
	char *ap = va_arg(a, char *);

	while (ap[counter] != '\0')
	{
		putchar(ap[counter]);
		counter++;
	}
	return (counter);
}

/**
 * _printf - Short description, single line
 * @format: Description of parameter x
(* Return: Description of the returned value
 */
int _printf(const char * const format, ...)
{
	int counter1 = 0, counter2, base = 10, len;
	va_list ap;
	type1 arr1[] = {{'c', print_char}, {'s', print_string}, {'i', my_itoa},
		{'d', my_itoa},{'b', my_utoa}, {'u', my_utoa}, {'o', my_utoa},
		{'x', my_utoa},{'X', my_utoa}, {'%', print_char}, {'\0', NULL}};
	va_start(ap, format);
	while (format != NULL && format[counter1] != '\0')
	{
		if (format[counter1] != '%')
			printf("%c", format[counter1]);
		else if (format[counter1] == '%' && format[counter1 + 1] == '\0')
			printf("%c", format[counter1]);
		else if (format[counter1] == '%' && format[counter1 + 1] != '\0')
		{
			counter2 = 0;
			while (arr1[counter2].a != '\0')
			{
				if (arr1[counter2].a == format[counter1 + 1])
				{
					if (format[counter1 + 1] == 'b')
						base = 2;
					else if (format[counter1 + 1] == 'u' || format[counter1 + 1] == 'i' || format[counter1 + 1] == 'd')
						base = 10;
					else if (format[counter1 + 1] == 'o')
						base = 8;
					else if (format[counter1 + 1] == 'x')
						base = 16;
					else if (format[counter1 + 1] == '%')
					{
						putchar('%');
						counter1++;
						break;
					}
					arr1[counter2].f(ap,base);
					counter1++;
					break;
				}
				counter2++;
			}
		}
		counter1++;
	}
	va_end(ap);
	return (counter1);
}
