#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdbool.h>

/**
  * print_rot13 - encodes a string into rot13.
  * @a: string to convert
  * @b: string
  * Return: size the output text
  */

int print_rot13(va_list a, char b)
{
	int j, i, counter = 0;
	char *ap;
	char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz";
	char rot[] = "NOPQRSTUVWXYZABCDEFGHIJKLM nopqrstuvwxyzabcdefghijklm";

	ap = va_arg(a, char *);

	if (ap == NULL)
		ap = "(null)";

	for (j = 0; ap[j] != '\0'; j++)
	{
		for (i = 0; alpha[i] != '\0'; i++)
		{
			if (ap[j] == alpha[i])
			{
				_putchar(rot[i]);
				counter++;
				break;
			}
			else
			{
				_putchar(ap[j]);
				counter++;
				break;
			}
		}
	}
	if (b)
		return (counter);
	return (counter);
}
