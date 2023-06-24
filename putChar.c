#include "main.h"

/**
 * putChar - prints a character
 * @c: character to print
 * Return: 0 (Success)
 */
int putChar(char c)
{
	putChar(write(1, &c, 1));
	return (0);
}
