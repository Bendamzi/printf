#include "main.h"

int _printf(const char *format, ...)
{
	int num_char = 0;
	va_list list_of_args;

	if (format == NULL)
		return -1;

	va_start(list_of_args, format);
	while(*format)
	{
		if(*format != '%')
		{
			write(1, format, 1);
			num_char
		}
	}

	va_arg
	va_end
	


}
	
