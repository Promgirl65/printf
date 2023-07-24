#include "main.h"

/*********************** PRINT CHARACTER ***********************/

/**
 * print_char - prints  char.
 * @types: List of arguments
 * @buffer: buffer array to handle print
 * @flags:  calculates active flags
 * @width: width
 * @precision: precision specifier
 * @size: size specifier
 * Return: number of chars to be print.
 */

int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char a = va_arg(types, int);

	return (handle_write_char(a, buffer, flags, width, precision, size));
}

/*********************** PRINT A SRING***********************/

/**
 * print_string - prints string
 * @types: list of arguments
 * @buffer: buffer array to handle print
 * @flags:  calculates active flags
 * @width: get width.
 * @precision: precision specifier
 * @size: size specifier
 * Return: number of chars to print
 */

int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, s;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (s = width - length; s > 0; s--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (s = width - length; s > 0; s--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}

/*********************** PRINT PERCRNTAGE SIGN ***********************/

/**
 * print_percent - prints percentage sign
 * @types: list arguments
 * @buffer: buffer array to handle prints
 * @flags:  calculates active flags
 * @width: get width.
 * @precision: precision specifier
 * @size: size specifier
 * Return: number of chars to be printed
 */

int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/*********************** PRINT INTEGER ***********************/

/**
 * print_int - prints integer
 * @types: Lists of arguments
 * @buffer: buffer array to handle print
 * @flags:  calculates active flags
 * @width: get width.
 * @precision: precision specifier
 * @size: size specifier
 * Return: number of printed chars
 */

int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int w = BUFF_SIZE - 2;
	int is_negative = 0;
	long int s = va_arg(types, long int);
	unsigned long int num;

	s = convert_size_number(s, size);

	if (s == 0)
		buffer[w--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)s;

	if (s < 0)
	{
		num = (unsigned long int)((-1) * s);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[w--] = (num % 10) + '0';
		num /= 10;
	}

	w++;

	return (write_number(is_negative, w, buffer, flags, width, precision, size));
}

/*********************** PRINT BINARY ***********************/

/**
 * print_binary - prints the unsigned number
 * @types: list of arguments
 * @buffer: buffer array to handle print
 * @flags:  calculates active flags
 * @width: get width
 * @precision: Precision specifier
 * @size: size specifier
 * Return: number of printed chars
 */

int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int n, m, w, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	n = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (w = 1; w < 32; w++)
	{
		m /= 2;
		a[w] = (n / m) % 2;
	}
	for (w = 0, sum = 0, count = 0; w < 32; w++)
	{
		sum += a[w];
		if (sum || w == 31)
		{
			char z = '0' + a[w];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
