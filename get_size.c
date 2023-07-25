#include "main.h"

/**
 * get_size - calculates the size to cast the argument in...
 * @format: formatted string which is to print the arguments...
 * @j: list of arguments to be printed
 * Return: size
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
