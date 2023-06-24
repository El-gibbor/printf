#include "main.h"

/**
 * putChar - prints a character
 * @c: character to print
 * Return: system call to fd, mem address & n byte
 */
int putChar(char c)
{
	return (write(1, &c, 1));
	
}
