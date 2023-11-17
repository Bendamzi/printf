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
	int curr_i = *i + 1;
	int size = 0;

	if (format[curr_i] == 'l')
		size = S_LONG;
	else if (format[curr_i] == 'h')
		size = S_SHORT;

	if (size == 0)
		*i = curr_i - 1;
	else
		*i = curr_i;

	return (size);
}
