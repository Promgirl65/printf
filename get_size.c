#include "main.h"

/**
 * get_size - Calculates the size to cast the argument
 * @format: Formatted string in which to print the arguments
 * @j: List of arguments to be printed.
 *
 * Return: Precision.
 */
int get_size(const char *format, int *j)
{
	int curr_i = *j + 1;
	int size = 0;

	if (format[curr_i] == 'l')
		size = S_LONG;
	else if (format[curr_i] == 's')
		size = S_SHORT;

	if (size == 0)
		*j = curr_i - 1;
	else
		*j = curr_i;

	return (size);
}



