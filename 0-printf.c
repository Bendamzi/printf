/*
 * Author: Okusanya Benjamin & Okusanya Idowu
 * A program on variadic function
 * 14/11/2023
 */

#include "main.h"
/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	va_start(args, format);
	if (format == NULL)
		return (-1);

	while (*format != '\0')
	{
	if (*format == '%' && *(format + 1) == '\0')
	{
		return (-1);
	}
	if (*format == '%')
	{
		format++;
		count += check_specifier(format, args);
	}
	else
	{
		count += _putchar(*format);
	}
	format++;
	}
	va_end(args);
	return (count);
}
/**
 * check_specifier - checking the specifiers
 * @format: the specifier to check
 * @args: argument container
 * Return: number of character printed
 */
int check_specifier(const char *format, va_list args)
{
	int count = 0;

	switch (*format)
	{
	case 'c':
	count = _putchar(va_arg(args, int));
	return (count);
	case 's':
	{
	const char *str = va_arg(args, const char*);

	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}

	count = write(1, str, strlen(str));
	}
	return (count);
	case '%':
	count = _putchar('%');
	return (count);
	case ' ':
	return (-1);
	default:
	count = _putchar('%');
	count += _putchar(*format);
	return (count);
	}
}
