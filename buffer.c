#include "main.h"

/**
 * _write - Controls the print buffer
 * @file: The file when the content is print it
 * @data: The data to print
 * @lenght: The lenght to print
 *
 * Return: Lenght printed
 */
int _write(int file, char *data, int lenght)
{
	static int	count;
	static char	buffer[1024] = "";
	int i, r = 0;

	if (file < 0)
	{
		r += write(1, buffer, count);
		count = 0;
		return (r);
	}

	for (i = 0; i < lenght; i++)
	{
		buffer[count++] = data[i];
		if (count >= 1024)
		{
			r += write(file, buffer, count);
			count = 0;
		}
	}
	return (r);
}
