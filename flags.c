#include "main.h"

/**
 * get_flags - calculates active flags...
 * @format: formatted string which to print arguments...
 * @i: take a parameter...
 * Return: flags:
 */

int get_flags(const char *format, int *i)

{

	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */

	int s, curr_i;
	int flags = 0;

	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_i = *i + 1; format[curr_i] != '\0'; curr_i++)

	{

		for (s = 0; FLAGS_CH[s] != '\0'; s++)
			if (format[curr_i] == FLAGS_CH[s])

			{
				flags |= FLAGS_ARR[s];
				break;
			}

		if (FLAGS_CH[s] == 0)

			break;

	}

	*i = curr_i - 1;
	return (flags);
}
