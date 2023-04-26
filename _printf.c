#include "main.h"

/**
 * _printf - Prints output according to a format.
 * @format: Format string containing directives.
 * Return: The number of characters printed (excluding the null byte).
 */

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++; /* advance to the conversion specifier character */
			switch (*format)
			{
				case 'c':
					_putchar(va_arg(args, int));
					count++;
					break;
				case 's':
					{
						char *s = va_arg(args, char *);
						while (*s != '\0')
						{
							_putchar(*s);
							s++;
							count++;
						}
						break;
					}
				case '%':
					_putchar('%');
					count++;
					break;
				default:
					break;
			}
		}
		else
		{
			_putchar(*format);
			count++;
		}
		format++;
	}

	va_end(args);

	return (count);
}

/**
 * _putchar - Writes a character to stdout.
 * @c: The character to write.
 */
void _putchar(char c)
{
	putchar(c);
}
