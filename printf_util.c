#include "printf.h"

/**
 * is_printable - Determine if a char is displayable
 *
 * @c: Charater
 *
 * Return: 0 if c is not printable, else 1
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);

	return (0);
}

/**
 * append_hexa_code - adds the ASCII in hex code to buffer
 * @buffer: List of chars.
 * @i: Index to start addiing from.
 * @ascii_code: ASCII code.
 * Return: Always 3
 */

int append_hexa_code(char ascii_code, char buffer[], int i)
{
	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = "0123456789ABCDEF"[ascii_code >> 4];
	buffer[i] = "0123456789ABCDEF"[ascii_code & 0xF];

	return (3);
}

/**
 * is_digit - Determine if the char is a digit
 * @c: Access character
 *
 * Return: 0 if c is not a digit, else 1
 */

int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - Add counter to specified size
 * @num: Values to be added.
 * @size: Number Showing type to add.
 *
 * Return: Value of count
 */

long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - Casts a number to the specified size
 * @num: Number to cast
 * @size: Number indicating the type to be casted
 *
 * Return: Casted value of num
 */

long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
