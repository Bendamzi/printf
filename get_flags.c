#include "printf.h"

/**
 * get_flags - Compute flags that are active
 * @format: Display formatted args
 * @i: Accept an arg
 * Return: Flags
 */
int get_flags(const char *format, int *i)
{
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (int curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)
	{
		const char *ptr = strchr(FLAGS_CH, format[curr_i]);

		if (ptr)
		{
			int index = ptr - FLAGS_CH;

			flags |= FLAGS_ARR[index];
		}
		else
		{
			break;
		}
	}

	*i = curr_i - 1;
	return (flags);
}

