#include "printf.h"

/*PRINT THE UNSIGNED NUMBER */
/**
 * print_unsigned - To show unsigned number
 * @types: list of arguments
 * @buffer: Buffer array to manage print
 * @flags:  represents the  active flags
 * @width: valuefor width
 * @precision: The Precision specification
 * @size: the size specifier
 * Return: Num of char to print.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/* PRINT UNSIGNED NUMBER IN OCTAL */
/**
 * print_octal - Show output an unsigned numb in octal form
 * @types: arguments array
 * @buffer: Buffer array to handle print
 * @flags: Indicates its active status
 * @width: gets width
 * @precision: Precision specification
 * @size: specifiecation of data size
 * Return: Amount of characaters printed
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/* SHOW UNSIGNED NUMBER IN HEX */
/**
 * print_hexadecimal - Show unsigned number in hex form
 * @types: List of arguments
 * @buffer: Buffer array to manage the print
 * @flags:  denotes the active flags
 * @width: Value of width
 * @precision: Precision specification
 * @size: The size specifier
 * Return: Num of characters to print
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/* DISPLAY UNSIGNED NUMBER IN UPPER HEXADECIMAL */
/**
 * print_hexa_upper - Display unsigned number in upper hex form
 * @types: Arguments list
 * @buffer: Buffer array to manage the print
 * @flags:  represents the  active flags
 * @width: gets width
 * @precision: precision specification.
 * @size: the size specifier.
 * Return:  Quantity of printed characters.
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/* Prints hexadecimal number either in upper or lower*/
/**
 * print_hexa - Display hexa count in upper or lower
 * @types: Array of arguments
 * @map_to: Array of values used to map the numbers
 * @buffer: Buffer array to manage the print
 * @flags: Denotes the active flags
 * @flag_ch: Denotes the active flags
 * @width: width
 * @precision: Precision specification
 * @size: size specifier
 * @size: size specification
 * Return: Number of printed characters
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
