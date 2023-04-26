#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdbool.h>

/**
 * print_char - putchar()
 * @a: Character to be printed
 * @b: base
(* Return: Return number of characters printed
 */

int print_char(va_list a, char b)
{
	char ap = va_arg(a, int);

	_putchar(ap);
	if (b)
		return (1);
	return (1);
}

/**
 *print_pct - prints character "%"
 *@ap : arguments
 *b: char b
 *Return: character "%"
 */
int print_pct(va_list ap, char b)
{
	(void)ap;

	if (b)
		return (write(1, "%", 1));
	return (write(1, "%", 1));
}


/**
 * print_string - printf() with string parameter
 * @a: string pointer to be printed
 * @b: base
 (* Return: Return characters printed
 */

int print_string(va_list a, char b)
{
	int counter = 0;
	char *ap = va_arg(a, char *);

	if (ap == NULL)
		ap = "(null)";

	while (ap[counter] != '\0')
	{
		_putchar(ap[counter]);
		counter++;
	}
	if (b)
		return (counter);
	return (counter);
}

/**
 * _fprintf - Short description, single line
 * @format: Description of parameter x
 * @ap: Description
(* Return: Description of the returned value
 */
int _fprintf(const char * const format, va_list ap)
{
	int counter1 = 0, counter2, counter3 = 0;
	type1 arr1[] = {{'c', print_char}, {'s', print_string}, {'i', my_itoa}
		, {'d', my_itoa}, {'b', my_utoa}, {'u', my_utoa}, {'o', my_utoa}
		, {'x', my_utoa}, {'X', my_utoa}, {'%', print_char}, {'\0', NULL}};

	if (format == NULL || !format[counter1 + 1])
		return (-1);

	while (format != NULL && format[counter1] != '\0')
	{
		if (format[counter1] != '%')
			_putchar(format[counter1]);
		else if (format[counter1] == '%' && format[counter1 + 1] == '\0')
			_putchar(format[counter1]);
		else if (format[counter1] == '%' && format[counter1 + 1] != '\0')
		{
			counter2 = 0;
			while (arr1[counter2].a != '\0')
			{
				if (arr1[counter2].a == format[counter1 + 1])
				{
					arr1[counter2].f(ap, format[counter1 + 1]);
					counter1++;
					break;
				}
				counter2++;
			}
			if (arr1[counter2].a == '\0')
				_putchar('%');
		}
		counter1++;
		counter3++;
	}
	return (counter3);
}

/**
 * _printf - Short description, single line
 * @format: Description of parameter x
(* Return: Description of the returned value
 */

int _printf(const char * const format, ...)
{
	int result;

	va_list ap;

	va_start(ap, format);

	result = _fprintf(format, ap);

	va_end(ap);

	return (result);
}
