#include "main.h"

/**
 * print_oct - prints decimal digits in octal form
 * @arg_l: arguments passed
 * Return: octal digits
 */
int print_oct(va_list arg_l)
{
	unsigned int n = va_arg(arg_l, unsigned int);
	unsigned int val_d;
	int len = 0;

	val_d = cal_val(n, OCT);

	while (val_d)
	{
		len += put_char(n / val_d + '0');
		n %= val_d;
		val_d /= OCT;
	}
	return (len);
}

/**
 * print_hex_l - prints a number in hexadecimal lowercase
 * @arg_l: the number to be printed in hexadecimal
 * Return: the length of number printed
 */
int print_hex_l(va_list arg_l)
{
	const char *hex_l = "123456789abcdef";
	unsigned int n = va_arg(arg_l, unsigned int);
	unsigned int val_d;
	int len = 0;

	val_d = (unsigned int) cal_val(n, HEX);

	while (val_d)
	{
		char c = hex_l[n / val_d];

		len += put_char(c);
		n %= val_d;
		val_d /= HEX;
	}
	return (len);
}

/**
 * print_hex_u - prints a number in hexadecimal uppercase
 * @arg_l: the number to be printed in hexadecimal
 * Return: the length of the number printed
 */
int print_hex_u(va_list arg_l)
{
	const char *hex_u = "123456789ABCDEF";
	unsigned int n = va_arg(arg_l, unsigned int);
	unsigned int val_d;
	int len = 0;

	val_d = (unsigned int) cal_val(n, HEX);

	while (val_d)
	{
		char c = hex_u[n / val_d];

		len += put_char(c);
		n %= val_d;
		val_d /= HEX;
	}
	return (len);
}
