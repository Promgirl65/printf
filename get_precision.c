#include "main.h"

/**
 * get_precision - calculates the precision for printing...
 * @format: formatted string which is going to print arguments...
 * @i: list of arguments to be printed...
 * @list: list of arguments...
 * Return: precision...
 */

int get_precision(const char *format, int *i, va_list list)
{
	int pr_i = *i + 1;
	int precision = -1;

	if (format[pr_i] != '.')
		return (precision);

	precision = 0;

	for (pr_i += 1; format[pr_i] != '\0'; pr_i++)
	{
		if (is_digit(format[pr_i]))
		{
			precision *= 10;
			precision += format[pr_i] - '0';
		}
		else if (format[pr_i] == '*')
		{
			pr_i++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = pr_i - 1;

	return (precision);
}
