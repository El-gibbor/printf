#include "main.h"

/**
 * getFormatFunc - returns a pointer the corresponding format func
 * @c: character to return its corresponding fomat func
 * Return: func pointer to the corresponding format func
 */
int (*getFormatFunc(char c))(va_list)
{
	int i = 0;
	formatStruct formSpec[] = {
		{'c', printChar},
		{'s', printStrLiteral},
		{'\0', NULL} /* sentinal value for termination*/
	};

	for (; formSpec[i].c; i++)
	{
		if (!(charcmp(formSpec[i].c, c)))
			return (formSpec[i].formatFunc);
	}
	return (NULL);
}
