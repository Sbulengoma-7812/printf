#include "main.h"

/**
  * _printf - fills memory with a constant byte
  * @format: is the string given
  * Return: numbers of characters printed
  */

int _printf(const char *format, ...)
{
	int k = 0, cont = 0;
	va_list va;
	int (*pp)();

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(va, format);
	for (k = 0; format != NULL && format[k] != '\0'; k++)
	{
		if (format[k] == '%')
		{
			pp = equal(format + k);
			if (pp != NULL)
			{
				cont += pp(va);
				k++;
			}
			else
					cont += _putc(format[k]);
		}
		else
			cont += _putc(format[k]);
	}
	cont += _write(-1, "c", 1);
	va_end(va);
	return (cont);
}

/**
  * _putc - fills memory with a constant byte
  * @a: the value to print
  * Return: numbers of characters printed
  */
int _putc(char a)
{
	return (_write(1, &(a), 1));
}

/**
  * equal - fills memory with a constant byte
  * @format: the value to print
  * Return: numbers of characters printed
  */
int (*equal(const char *format))()
{
	int j;
	op_t o[] = {
		{"c", ch},
		{"s", st},
		{"i", inte},
		{"d", inte},
		{"%", por},
		{"b", bina},
		{"o", octa},
		{"u", unsig},
		{"x", hexal},
		{"X", hexau},
		{"S", sst},
		{"p", point},
		{"r", reve},
		{"R", rot13},
		{NULL, NULL},
	};

	for (j = 0; o[j].op != NULL; j++)
		if (format[1] == o[j].op[0])
			return (o[j].f);
	return (o[j].f);
}
