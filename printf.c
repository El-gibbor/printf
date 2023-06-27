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
			if (format[pos] == '%')
				len += put_char(format[pos++]);
			else
				format_spec(format, &len, &pos, arg_l);
		}
		else
			len += put_char(format[pos++]);
	}
	va_end(arg_l);
	return (len);
}

/**
 * format_spec - checks for a format specifier
 * @str: the argument string
 * @len: a pointer to the length of characters being printed
 * @str_pos: current position in a string
 * @arg_l: next argument to be printed
 * Return: the length of characters printed
 */
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
			(*str_pos)++;
			*len += fmt[i].f(arg_l);
			return (*len);
		}
		else
			i++;
	}
	return (*len);
}
