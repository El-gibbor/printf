#include "main.h"

/**
 * printStrLiteral - prints the literal string pointed to by (format)
 * @str: string to be printed
 * Return: string length
 */
int printStrLiteral(char *str)
{
	int lenStr = 0;

	if (str && *str)
	{
		for (; *str; str++)
		{
			putChar(*str);
			lenStr += 1;
		}
	}
	return (lenStr);
}
/**
 * printChar - prints just a charcter
 * @c: character to be printed
 * Return: length of character
*/
int printChar(va_list argList, int lenChar)
{
    char theChar = va_arg(argList, int);

    putChar(theChar);
    lenChar++;
    return (lenChar);
}