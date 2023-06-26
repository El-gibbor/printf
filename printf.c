#include "main.h"

/**
 * _printf - prints characters
 * @format: string
 * Return: len of the string
 */
int _printf(const char *format, ...)
{
	int i, len = 0, c;
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
					if (format[i - 2] == '%')
						return (-1);
					len += print_ch(format[i - 1]);
					if (format[i] == ' ')
						len += print_ch(format[i++]);
					while (format[i] == ' ')
						i++;
					if (format[i] == 'h' || format[i] == 'l')
						i++;
					len += print_ch(format[i]);
			}
			i++;
		}
		else
			len += print_ch(format[i++]);
	}
	va_end(ap);
	return (len);
}
