#include "main.h"

/**
 * print_rem - helper function
 * @s: a pointer to a string to be printed
 * @str_pos: a pointer to the position of the string
 * Return: length of the string
 */
int print_rem(const char *s, int *str_pos)
{
	int len = 0, i = *str_pos;

	if (s[i - 2] == '%')
		return (-1);
	len += print_ch(s[i - 1]);
	if (s[i] == ' ')
		len += print_ch(s[i++]);
	while (s[i] == ' ')
		i++;
	if (s[i] == 'h' || s[i] == 'l')
		i++;
	len += print_ch(s[i]);

	*str_pos = i;
	return (len);
}

/**
 * _printf - prints characters to stdout
 * @format: string
 * Return: length of its output or -1 if unsuccessful
 */
int _printf(const char *format, ...)
{
	int i, len = 0, c, temp_len;
	va_list ap;

	if (format == NULL)
		return (-1);
	va_start(ap, format);
	for (i = 0; format[i] != '\0';)
	{
		if (format[i] == '%')
		{
			switch (format[++i])
			{
				case 's':
					len += print_str(ap);
					break;
				case 'd':
					len += print_num(ap);
					break;
				case 'c':
					c = va_arg(ap, int);
					len += print_ch(c);
					break;
				case '%':
					len += print_ch(format[i]);
					break;
				case '\0':
					return (-1);
				default:
					temp_len = print_rem(format, &i);
					if (temp_len == -1)
						return (-1);
					len += temp_len;
			}
			i++;
		}
		else
			len += print_ch(format[i++]);
	}
	va_end(ap);
	return (len);
}
