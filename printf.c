#include "main.h"

/**
 * _printf - prints characters
 * @format: string
 * Return: len of the string
 */
int _printf(const char *format, ...)
{
	int i, len = 0, c, l;
	va_list ap;

	va_start(ap, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			switch (format[i + 1])
			{
				case 's':
					l = prnt_str(ap);
					if (l < 0)
						return -1;
					len += l;
					break;
				case 'd':
					len += prnt_num(ap);
					break;
				case 'c':
					c = va_arg(ap, int);
					len += prnt_ch(c);
					break;
				case '%':
					len += prnt_ch('%');
					break;
			}
			i++;
		}
		else
			len += prnt_ch(format[i]);
	}
	va_end(ap);
	return (len);
}
