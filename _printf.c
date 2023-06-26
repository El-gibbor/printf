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

	va_start(argList, format);
	for (c = 0; format[c]; c++)
	{
		if (format[c] != '%')
			lenStr += printChar(format[c]);
		else if (format[c] == '%')
		{
			c++;
			if (format[c] == '%')
				lenStr += printChar('%');
			else
			{
				int (*formatFunc)(va_list) = getFormatFunc(format[c]);

				if (formatFunc)
					lenStr += formatFunc(argList);
			}
		}
	}
	va_end(argList);
	return (lenStr);
}

/**
 * getFormatFunc - returns a pointer the corresponding format func
 * @c: character to return its corresponding format func
 * Return: func pointer to the corresponding format func
*/
int (*getFormatFunc(char c))(va_list)
{
	if (!charcmp(c, 'c'))
		return (printChar);
	else if (!charcmp(c, 's'))
		return (printStrLiteral);
	else
		return (NULL);
}
