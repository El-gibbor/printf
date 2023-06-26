#include "main.h"

/**
 * print_str - prints a string
 * @ap: the string argument
 * Return: the length of the string printed
 */
int print_str(va_list ap)
{
	char *s = va_arg(ap, char *);
	int i;

	if (s == NULL)
		s = "(null)";

	for (i = 0; s[i] != '\0'; i++)
		print_ch(s[i]);
	return (i);
}
