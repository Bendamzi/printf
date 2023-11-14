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
	va_list args_list;

	va_start(args_list, format);

	while (*format != '\0')
	{
	if (*format == '%')
	{
		format++;
		switch (*format)
		{
		case 'c':
		count += _putchar(va_arg(args_list, int));
		break;
		case 's':
		{
		const char *str = va_arg(args_list, const char*);
			count += write(1, str, strlen(str));
		}
		break;
		case '%':
		count += putchar('%');
		break;
		default:
		count += putchar(*format);
		break;
		}
	}
	else
	{
		count += putchar(*format);
	}
	format++;
	}
	va_end(args_list);
	return (count);
}
