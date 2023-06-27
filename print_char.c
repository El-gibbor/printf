#include "main.h"

/**
 * put_char - prints just a character
 * @c: character to be printed
 * Return: length of character
 */
int put_char(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_str - prints a string literal pointed in the parameter
 * @arg_l: string to be printed
 * Return: the length of the string
 */
int print_str(va_list arg_l)
{
	int i = 0;
	char *str = va_arg(arg_l, char *);

	if (str == NULL)
		str = "(null)";
	while (str[i] != '\0')
		put_char(str[i++]);

	return (i);
}

/**
 * print_ch - prints just a character
 * @arg_l: character to be printed
 * Return: length of character
 */
int print_ch(va_list arg_l)
{
	char c = va_arg(arg_l, int);

	return (put_char(c));
}
