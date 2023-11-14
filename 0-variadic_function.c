#include "main.h"

/**
 * _printf - Custom printf function
 * @format: Format string
 *
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (format && *format)
	{
		if (*format == '%' && *(format + 1) != '\0')
		{
			switch (*(format + 1))
			{
				case 'c':
				count += _putchar(va_arg(args, int));
				break;
				case 's':
				{
				const char *str = va_arg(args, const char*);
				count += write(1, str, strlen(str));
				}
				break;
			case '%':
				count += write(1, "%", 1);
				break;
			default:
				count += write(1, "%", 1);
				count += write(1, format + 1, 1);
			}
			format += 2; /* Move to the next character after the specifier */
		}
		else
		{
			count += write(1, format, 1);
			format++;
		}
	}
	va_end(args);

	return (count);
}
