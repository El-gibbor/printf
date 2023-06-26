#include "main.h"

/**
 * getFormatFunc - returns a pointer the corresponding format func
 * @c: character to return its corresponding fomat func
 * Return: func pointer to the corresponding format func
 */
int (*getFormatFunc(char c))(va_list)
{
	int i = 0;
	formatStruct format[] = {
		{'c', printChar},
		{'s', printStrLiteral},
		{'\0', NULL} /* sentinal value for termination*/
	};

	for (; format[i].c; i++)
	{
		if (format[i].c == c)
			return (format[i].formatFunc);
	}
	return (NULL);
}
