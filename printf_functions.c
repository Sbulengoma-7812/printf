#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdbool.h>

/**
 * print_strings - printf() with string parameter
 * @a: string pointer to be printed
 * @base: base
(* Return: Return characters printed
 */
int print_strings(char *a, int base)
{
	int counter = 0;

	while (a[counter] != '\0')
	{
		putchar(a[counter]);
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
		temp = *(str+start);
		*(str + start) = *(str + end);
		*(str + end) = temp;
	}
}


/**
 * my_itoa - itoa(int num, char* str, int base). itoa with int
 * @num: Number to be converted to string
 * @str: Resulting string
 * @base: strlen(str)
(* Return: Print string
 */
int my_itoa(va_list ap, int base)
{
char charArray[128];
char * str = charArray;
int num = va_arg(ap, int);
int i = 0;
bool isNegative = false;


if (num == 0) {
str[i] = '0';
str[i + 1] = '\0';
return 0;
}

if (num < 0 && base == 10) {
isNegative = true;
num = -num;
}

while (num != 0) {
int rem = num % base;
str[i++] = (rem > 9)? (rem-10) + 'A' : rem + '0';
num = num/base;
}

if (isNegative){
str[i++] = '-';
}

str[i] = '\0';
my_reverse(str, i);
print_strings(str,base);
return 0;
}

 /**
 * my_utoa - itoa(unsigned int num, char* str, int base). itoa with unsigned int
 * @num: unsigned int to be converted to string
 * @str: Resulting string
 * @base: strlen(str)
(* Return: string
 */
int my_utoa(va_list ap, int base)
{
char charArray[128];
char * str = charArray;
unsigned int num = va_arg(ap, unsigned int);

int i = 0;
bool isNegative = false;

if (num == 0) {
str[i] = '0';
str[i + 1] = '\0';
return 0;

}

if (num < 0 && base == 10) {
isNegative = true;
num = -num;
}

while (num != 0) {
int rem = num % base;
str[i++] = (rem > 9)? (rem-10) + 'A' : rem + '0';
num = num/base;
}
if (isNegative){
str[i++] = '-';
}

str[i] = '\0';
my_reverse(str, i);
print_strings(str,base);
return 0;

}

