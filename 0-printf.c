#include "main.h"
#include <stdio.h>
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
	int num;
	
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
	case 'd':
	num = va_arg(args, int);
	if (num < 0)
	{
		count = _putchar('-');
		 count += print_decimal(~num + 1);
	 	 return (count);
	}
	else
	{
		if (num > 0)
			count = print_decimal(num);
		else
			count = _putchar(num + '0');
		return (count);
	}
	case 'i':
	num = va_arg(args, int);
	if (num < 0)
	{
		count = _putchar('-');
		 count += print_int(num * (-1));
	 	 return (count);
	}
	else
	{
		if (num > 0)
			count = print_int(num);
		else
			count = _putchar(num + '0');
		return (count);
	}
	default:
	count = _putchar('%');
	count += _putchar(*format);
	return (count);
	}
}
/**
 * print_decimal - prints decimal
 * @num: number to print
 * Return: the number printed
 */
int print_decimal(int num)
{
	int count = 0;

	if (num == 0)
	{
		return (count);
	}
	count += print_decimal(num / 10);
	count += _putchar((num % 10) + '0');
	return (count);
}
/**
 * print_int - prints integers
 * @num: number to print
 * Return: the number printed
 */
int print_int(int num)
{
	int count = 0;

	if (num == 0)
	{
	return (count);
	}
	count += print_int(num / 10);
	count += _putchar((num % 10) + '0');
	return (count);
}

