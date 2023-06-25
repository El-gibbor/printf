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
			putchar(*str);
			lenStr += 1;
		}
	}
	return (lenStr);
}
