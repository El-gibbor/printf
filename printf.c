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

int format_spec(const char *str, int *len, int *str_pos, va_list arg_l)
{
	spec_conv fmt[] = {
		{'c', print_ch},
		{'d', print_int},
		{'i', print_int},
		{'s', print_str},
		{'u', print_unint},
		{'o', print_oct},
		{'b', print_bin},
		{'x', print_hex_l},
		{'X', print_hex_u},
		{'\0', NULL}};
	int pos = *str_pos, i = 0;

	while (fmt[i].c != '\0')
	{
		if (fmt[i].c == str[pos])
		{
			*len += fmt[i].f(arg_l);
			return (*len);
		}
		else
			i++;
	}
	return (*len);
}
