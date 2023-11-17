#include "printf.h"

/**
 * get_size - Dtermine the argument's casting size.
 * @format: String for formatting and displaying the arguments
 * @i: Show arrays of arguments to print.
 *
 * Return: Size.
 */
int get_size(const char *format, int *i)
{
	int size = 0;

	switch (format[*i + 1])
	{
		case 'l':
			size = S_LONG;
			break;
		case 'h':
			size = S_SHORT;
			break;
		default:
			break;
	}
	*i = *i + 1;
	return (size);
}

