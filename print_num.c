#include "main.h"

/**
 * print_num - prints integers
 * @ap: an argument passed
 * Return: the length of ap
 */
int print_num(va_list ap)
{
	int n = va_arg(ap, int);
	int d = 1, num, len = 0;

	if (n < 0)
	{
		len += prnt_ch('-');
		n = -n;
	}

	num = n;
	while (n > 9)
	{
		d *= 10;
		n /= 10;
	}

	while (d)
	{
		len += prnt_ch((num / d) + '0');
		num %= 10;
		d /= 10;
	}
	return (len);
}
