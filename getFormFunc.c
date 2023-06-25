#include "main.h"

/**
 * getFormFunc - returns a ptr to func that corresponds with
 * the format specifier given as parameter
 * @fspec: format/conversion specifier
 * Return: pointer to a function
*/
int (*getFormatFunc(char spec))(va_list, int)
{
	convFunc convF[] = {
		{'c', putChar}
	};

    int i;

    for (i = 0; i < 1; i++)
    {
        if (spec == convF[i].formSpec)
            return (convF[i].formatFunc);
    }
    return (NULL);
}