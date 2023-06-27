#include "main.h"

/**
 * _printf - produces a formatted output
 * @format: character string to be formatted & printed
 * Return: Length of the formatted output
 */
int _printf(const char *format, ...)
{
	va_list arg_l;
	int pos = 0, len = 0;

	va_start(arg_l, format);
	while (format[pos])
	{
		if (format[pos] == '%')
		{
			pos++;
			format_spec(format, &len, &pos, arg_l);
		}
		else
			put_char(format[pos++]);
	}
	va_end(arg_l);
	return (len);
}
