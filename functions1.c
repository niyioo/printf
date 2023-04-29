#include "main.h"

/************************* PRINT UNSIGNED NUMBER *************************/
/**
 * print_unsigned - function that print unsigned number
 * @types: arguments
 * @buffer: buffer
 * @flags: flags
 * @width: the width
 * @precision: precision
 * @size: size
 * Return: printed unsigned
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

/************* PRINT UNSIGNED NUMBER IN OCTAL ****************/
/**
 * print_octal - function that print unsigned number in octal
 * @types: arguments
 * @buffer: buffer
 * @flags: flags
 * @width: the width
 * @precision: precision
 * @size: size
 * Return: printed octal values
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

/************** PRINT UNSIGNED NUMBER IN HEXADECIMAL **************/
/**
 * print_hexadecimal - function that print unsigned number in hex
 * @types: arguments
 * @buffer: buffer
 * @flags: flags
 * @width: the width
 * @precision: precision
 * @size: size
 * Return: printed hex values
 */

int print_hexadecimal(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
				flags, 'x', width, precision, size));
}

/************* PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL **************/
/**
 * print_hexa_upper - function that print unsigned number in upper hex
 * @types: arguments
 * @buffer: buffer
 * @flags: flags
 * @width: the width
 * @precision: precision
 * @size: size
 * Return: printed
 */

int print_hexa_upper(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
				flags, 'X', width, precision, size));
}

/************** PRINT HEX NUM IN LOWER OR UPPER **************/
/**
 * print_hexa - function that print hex num in lower or upper
 * @types: arguments
 * @map_to: values to map the number
 * @buffer: buffer
 * @flags: flags
 * @flag_ch: flags
 * @width: the width
 * @precision: precision
 * @size: size
 * Return: printed values
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
