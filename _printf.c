#include "main.h"

/**
 * _printf - produces a formatted output.
 * @format: character string to be formatted & printed
 * Return: Length of the formatted output.
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
			lenStr += putChar(format[c]);
		else if (format[c] == '%')
		{
			c++;
			if (format[c] == 'c')
				lenStr += printChar(argList);
			else if (format[c] == 's')
				lenStr += printStrLiteral(argList);
			else if (format[c] == '%')
				lenStr += putChar('%');
			/* else if (format[c] == '\0') return (-1); */
		}
	}
	va_end(argList);
	return (lenStr);
}

/**
 * selectFunc - selects the correct func to perform the operation
 * @c: character to be compared (format specifier)
 * Return: ptr to the func that corresponds with the format specifier
*/
int (*selectFunc(char formSpec))(va_list argList)
{
	if (!charcmp(formSpec, 'c'))
		return (printChar);
	else if (!charcmp(formSpec, 's'))
		return (printStrLiteral);
	else
		return (NULL);
}