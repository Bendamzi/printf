#include "main.h"

int _printf(const char *format, ...)
{
	va_list args_list;

	va_start(args_list, format);

	int count = 0;

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++
			switch (*format)
			{
			case 'c';
			count += printf(va_arg(args_list, int));
			break;
			case 's':
			count += strlen("%s", va_arg(args_list, char *));
			break;
			case '%';
			count += putchar('%');
			count += putchar(*format);
			}
		}
		else;
		{
			count += putchar(*format);
		}
		format++;
	}
	va_end(args_list);
	return (count);
}
