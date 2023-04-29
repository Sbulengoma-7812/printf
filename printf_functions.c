#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdbool.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_strings - printf() with string parameter
 * @a: string pointer to be printed
(* Return: Return characters printed
 */
int print_strings(char *a)
{
	int counter = 0;

	while (a[counter] != '\0')
	{
		_putchar(a[counter]);
		counter++;
	}
	return (counter);
}

/**
 * my_reverse - Reverse string
 * @str: String to reverse
 * @len: strlen(str)
 * Return: Reversed string
 */
void my_reverse(char str[], int len)
{
	int start, end;
	char temp;

	for (start = 0, end = len - 1; start < end; start++, end--)
	{
		temp = *(str + start);
		*(str + start) = *(str + end);
		*(str + end) = temp;
	}
}


/**
 * my_itoa - itoa(int num, char* str, int base). itoa with int
 * @ap: Number to be converted to string
 * @b: strlen(str)
 * a blank line
 * Description: Longer description of the function)
(* Return: Print string
 */
int my_itoa(va_list ap, char b)
{
	int base, rem, c = 0, i = 0, num = va_arg(ap, int);
	char charArray[128];
	char *str = charArray;
	bool isNegative = false;

	if (b == 'b')
		base = 2;
	else if (b == 'u' || b == 'i' || b == 'd')
		base = 10;
	else if (b == 'o')
		base = 8;
	else if (b == 'x')
		base = 16;
	if (num == 0)
	{
		str[i] = '0';
		str[i + 1] = '\0';
		_putchar('0');
		return (1);
	}
	if (num < 0 && base == 10)
	{
		isNegative = true;
		num = -num;
	}
	while (num != 0)
	{
		rem = num % base;
		str[i++] = (rem > 9) ? (rem - 10) + 'A' : rem + '0';
		num = num / base;
	}
	if (isNegative)
		str[i++] = '-';
	str[i] = '\0';
	my_reverse(str, i);
	for (c = 0; str[c] != '\0'; c++)
	{
		_putchar(str[c]);
	}
	return (c);
}

 /**
 * my_utoa - Reverse string
 * @ap: String to reverse
 * @b: strlen(str)
 * Return: Reversed string
 */

int my_utoa(va_list ap, char b)
{
	int base, c = 0, i = 0;
	char charArray[128];
	char *str = charArray;
	unsigned int num = va_arg(ap, unsigned int);
	bool isNegative = false;

	if (b == 'b')
		base = 2;
	else if (b == 'u' || b == 'i' || b == 'd')
		base = 10;
	else if (b == 'o')
		base = 8;
	else if (b == 'x')
		base = 16;
	if (num == 0)
	{
		str[i] = '0';
		str[i + 1] = '\0';
		_putchar('0');
		return (1);
	}
	while (num != 0)
	{
		int rem = num % base;

		str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
		num = num / base;
	}

	if (isNegative)
		str[i++] = '-';
	str[i] = '\0';
	my_reverse(str, i);
	while (str[c] != '\0')
	{
		_putchar(str[c]);
		c++;
	}
	return (c);
}

