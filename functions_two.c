#include "main.h"

/************* PRINT POINTER ***************/
/**
 * print_pointer - prints value of pointer variable...
 * @types: lis of arguments...
 * @buffer: buffer array to handle print...
 * @flags:  calculates active flags...
 * @width: width...
 * @precision: precision specifier...
 * @size: size specifier...
 * Return: number of chars to be printed...
 */

int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, length = 2, padd_start = 1; /* length=2, for '0x' */
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buffer[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';
	if (flags & F_PLUS)
		extra_c = '+', length++;
	else if (flags & F_SPACE)
		extra_c = ' ', length++;

	ind++;

	/*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/
	return (write_pointer(buffer, ind, length,
		width, flags, padd, extra_c, padd_start));
}

/*********** PRINT NON PRINTABLE *************/

/**
 * print_non_printable - prints ascii code in an hexa of non printable chars...
 * @types: list of arguments...
 * @buffer: buffer array to handle print...
 * @flags:  calculates active flags...
 * @width: width...
 * @precision: precision specifier...
 * @size: size specifier...
 * Return: number of chars to be printed...
 */

int print_non_printable(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int w = 0, offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[w] != '\0')
	{
		if (is_printable(str[w]))
			buffer[w + offset] = str[w];
		else
			offset += append_hexa_code(str[w], buffer, w + offset);

		w++;
	}

	buffer[w + offset] = '\0';

	return (write(1, buffer, w + offset));
}

/*********** PRINT REVERSE ***********/

/**
 * print_reverse - prints the reverse string...
 * @types: list of arguments...
 * @buffer: buffer array to handle the print...
 * @flags:  calculates active flags...
 * @width: width...
 * @precision: precision specifier...
 * @size: size specifier...
 * Return: numbers of characters to print...
 */

int print_reverse(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int w, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (w = 0; str[w]; w++)
		;

	for (w = w - 1; w >= 0; w--)
	{
		char z = str[w];

		write(1, &z, 1);
		count++;
	}
	return (count);
}
/*********** PRINT A STRING IN ROT13 ************/

/**
 * print_rot13string - print string in rot13...
 * @types: list of arguments...
 * @buffer: buffer array to handle print...
 * @flags:  calculates active flags...
 * @width: width...
 * @precision: precision specifier...
 * @size: size specifier...
 * Return: numbers of characters to be printed
 */

int print_rot13string(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char x;
	char *str;
	unsigned int w, s;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (w = 0; str[w]; w++)
	{
		for (s = 0; in[s]; s++)
		{
			if (in[s] == str[w])
			{
				x = out[s];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[s])
		{
			x = str[w];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
