#include "main.h"
#include <stdarg.h>

/**
 * _printf - Custom printf function
 * @format: Format string with conversion specifiers
 *
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%' && (*(format + 1) == 'c' || *(format + 1) == 's' ||
			*(format + 1) == '%' || *(format + 1) == 'd' ||
			*(format + 1) == 'i'))
		{
			count += print_arg(args, *(format + 1));
			format += 2; /* Move to the next format specifier */
		}
		else
		{
		_putchar(*format);
		count++;
		format++;
		}
	}

	va_end(args);

	return (count);
}

/**
 * print_arg - Print argument based on format specifier
 * @args: Variable argument list
 * @specifier: Format specifier ('c', 's', '%', 'd', 'i')
 *
 * Return: Number of characters printed for the argument
 */
int print_arg(va_list args, char specifier)
{
	switch (specifier)
	{
		case 'c':
		return (print_char(args));
		case 's':
		return (print_string(args));
		case '%':
		return (print_percent(args));
		case 'd':
		case 'i':
		return (print_int(args));
		default:
		_putchar(specifier);
		return (1);
	}
}

/**
 * print_char - Print a character
 * @args: Variable argument list
 *
 * Return: Number of characters printed for the character
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	_putchar(c);
	return (1);
}

/**
 * print_string - Print a string
 * @args: Variable argument list
 *
 * Return: Number of characters printed for the string
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char *);

	if (str == NULL)
	str = "(null)";
	write(1, str, _strlen(str));
	return (_strlen(str));
}

/**
 * print_percent - Print a percent sign
 * @args: Variable argument list
 *
 * Return: Number of characters printed for the percent sign
 */
int print_percent(__attribute__((unused)) va_list args)
{
	_putchar('%');
	return (1);
}


