#include "main.h"

/**
 * charcmp - compares two characters
 * @c1: first character
 * @c2: second character
 * Return: 0 if equal, -1 if c1 < c2, 1 if c1 > c2
 */
int charcmp(char c1, char c2)
{
	return (c1 == c2 ? 0 : (c1 < c2 ? -1 : 1));
}

/**
 * printStrLiteral - prints a string literal pointed in the parameter
 * @str: string to be printed
 * Return: string length
 */
int printStrLiteral(va_list argList)
{
	char *str = va_arg(argList, char *);
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
int printChar(va_list argList)
{
	char c = va_arg(argList, int);

	putChar(c);
	return (1);
}

/**
 * putChar - prints one character to stdout
 * @c: character to print
 * Return: system call to fd, mem address & n byte
 */
int putChar(char c)
{
	return (write(1, &c, 1));

}
