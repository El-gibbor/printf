#include "main.h"

int print_rem(const char *, int *, int *);
/**
 * _printf - produces a formatted output
 * @format: character string to be formatted & printed
 * Return: Length of the formatted output
 */
int _printf(const char *format, ...)
{
	va_list arg_l;
	int pos = 0, len = 0;

	if (!format)
		return (-1);

	va_start(arg_l, format);
	while (format[pos])
	{
		if (format[pos] == '%')
		{
			pos++;
			if (format[pos] == '\0')
				return (-1);
			if (format[pos] == '%')
				len += put_char(format[pos++]);
			else
				if (format_spec(format, &len, &pos, arg_l) == -1)
					return (-1);
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
	if (print_rem(str, str_pos, len) == -1)
		return (-1);
	return (*len);
}

/**
 * print_rem - helper function
 * @s: a pointer to a string to be printed
 * @str_pos: a pointer to the position of the string
 * @len: a pointer to the len of the string
 * Return: length of the string
 */
int print_rem(const char *s, int *str_pos, int *len)
{
	int i = *str_pos;

	if (s[i - 2] == '%')
		return (-1);
	*len += put_char(s[i - 1]);
	if (s[i] == ' ')
		*len += put_char(s[i++]);
	while (s[i] == ' ')
		i++;
	*len += put_char(s[i++]);

	*str_pos = i;
	return (*len);
}
