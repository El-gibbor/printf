#include "main.h"

/**
 * printChar - prints just a charcter
 * @c: character to be printed
 * Return: length of character
*/
int printChar(char c)
{
    putChar(c);
    return (1);
}

/**
 * printStrLiteral - prints a string literal pointed in the parameter
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
 * putChar - prints one character to stdout
 * @c: character to print
 * Return: system call to fd, mem address & n byte
 */
int putChar(char c)
{
	return (write(1, &c, 1));
	
}
