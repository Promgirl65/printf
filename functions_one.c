#include "main.h"

/*********************** PRINT UNSIGNED NUMBER ***********************/

/**
 * print_unsigned - prints the unsigned number.
 * @types: list of arguments
 * @buffer: buffer array to handle print
 * @flags:  calculates active flags
 * @width: width
 * @precision: precision specifier
 * @size: size specifier
 * Return: number of chars to be printed.
 */

int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int b = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[b--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[b--] = (num % 10) + '0';
		num /= 10;
	}

	b++;

	return (write_unsgnd(0, b, buffer, flags, width, precision, size));
}

/********************* PRINT UNSIGNED NUMBER IN OCTAL *********************/

/**
 * print_octal - Prints an unsigned number in octal notation
 * @types: list of arguments
 * @buffer: buffer array to handle print
 * @flags:  calculates active flags
 * @width: width
 * @precision: precision specifier
 * @size: size specifier
 * Return: number of prinmted chars
 */

int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int s = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[s--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[s--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[s--] = '0';

	s++;

	return (write_unsgnd(0, s, buffer, flags, width, precision, size));
}

/****************** PRINT UNSIGNED NUMBER IN HEXADECIMAL ******************/

/**
 * print_hexadecimal - prints unsigned hexadecimal notation number
 * @types: list of arguments
 * @buffer: buffer array to handle print
 * @flags:  calculates active flags
 * @width: width
 * @precision: precision specifier
 * @size: size specifier
 * Return: number of characters printed
 */

int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/

/**
 * print_hexa_upper - prints unsigned number in upper hexadecimal notation format
 * @types: lista of arguments
 * @buffer: buffer array to handle print
 * @flags:  calculates active flags
 * @width: width
 * @precision: precision specifier
 * @size: size specifier
 * Return: number of characters printed
 */

int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/************* PRINT HEXX NUM IN LOWER OR UPPER ***************/

/**
 * print_hexa - print hexadecimal number in lower or upper
 * @types: list of arguments
 * @map_to: array of values to map the number to
 * @buffer: buffer array to handle print
 * @flags:  calculates active flags
 * @flag_ch: calculates active flags
 * @width: width
 * @precision: precision specifier
 * @size: size specifier
 * @size: size specification
 * Return: number of chars to be printed
 */

int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int w = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[w--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[w--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[w--] = flag_ch;
		buffer[w--] = '0';
	}

	w++;

	return (write_unsgnd(0, w, buffer, flags, width, precision, size));
}
