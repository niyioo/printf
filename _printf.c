#include "main.h"

/**
 * _printf - Printf function
 * @format: format.
 * Return: Printed chars.
 */
int _printf(const char *format, ...)
{
	va_list list;
	char buffer[BUFF_SIZE];
	int printed_chars = 0, buffer_index = 0;

	if (format == NULL)
		return (-1);

	va_start(list, format);

	while (*format)
	{
		if (*format != '%')
		{
			buffer[buffer_index++] = *format++;
			if (buffer_index == BUFF_SIZE)
				printed_chars += flush_buffer(buffer, &buffer_index);
		}
		else
		{
			format++;
			buffer_index += handle_specifier(format, &list, buffer, &buffer_index);
			format += get_specifier_length(format);
		}
	}

	printed_chars += flush_buffer(buffer, &buffer_index);
	va_end(list);
	return (printed_chars);
}
