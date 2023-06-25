#include "main.h"

/**
 * _printf - produces a formatted output
 * @format: character string to be formatted & printed
 * Return: Length of the formatted output
*/
int _printf(const char *format, ...)
{
	va_list argList;
	int c, lenStr = 0;
	char ch;
	char *formatStr;
;
	va_start(argList, format);
	for (c = 0; format[c]; c++)
	{
		if (format[c] != '%')
			lenStr += printChar(format[c]);
		else if (format[c] == '%')
		{
			c++;
			if (format[c] == 'c')
			{
				ch = (va_arg(argList, int));
				lenStr += printChar(ch);
			}
			else if (format[c] == 's')
			{
				formatStr = va_arg(argList, char *);
				if (!formatStr)
					formatStr = "(null)";
				lenStr += printStrLiteral(formatStr);
			}
			else if (format[c] == '%')
				lenStr += printChar('%');

			else if (format[c] == '\0')
				return (-1);
		}
	}
	va_end(argList);
	return (lenStr);
}
