#include "main.h"

/**
 * print_ch - prints characters using write()
 * @c: the character to be printed
 * Return: the number of bytes printed
 */
int print_ch(char c)
{
	return (write(1, &c, 1));
}
