#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - Custom printf function implementation
 * @format: Format string
 *
 * Return: Number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	printed_chars = format_printer(format, args);
	va_end(args);

	return (printed_chars);
}

/**
 * format_printer - Iterates through the format string and prints formatted data
 * @format: Format string
 * @args: Variable arguments list
 *
 * Return: Number of characters printed (excluding the null byte)
 */
int format_printer(const char *format, va_list args)
{
	int i, count = 0;

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			count++;
			continue;
		}

		i++;

		if (format[i] == '\0')
			return (-1);

		if (format[i] == '%')
		{
			_putchar('%');
			count++;
		}
		else if (format[i] == 'c')
		{
			char c = (char)va_arg(args, int);
			_putchar(c);
			count++;
		}
		else if (format[i] == 's')
		{
			char *str = va_arg(args, char *);
			count += _puts(str);
		}
		else
		{
			_putchar('%');
			_putchar(format[i]);
			count += 2;
		}
	}

	return (count);
}

/**
 * _putchar - Writes a character to stdout
 * @c: Character to write
 *
 * Return: On success, returns the number of characters written.
 * On error, returns -1.
 */
int _putchar(char c)
{
	return putchar(c);
}

/**
 * _puts - Writes a string to stdout
 * @str: String to write
 *
 * Return: Number of characters written.
 */
int _puts(char *str)
{
	int count = 0;
	char *c = str;

	if (str == NULL)
		str = "(null)";

	while (*c)
	{
		_putchar(*c);
		count++;
		c++;
	}

	return count;
}
