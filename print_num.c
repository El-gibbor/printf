#include "main.h"

/**
 * print_int - prints integers
 * @arg_l: arguments to be printed
 * Return: lenght of arguments
 */
int print_int(va_list arg_l)
{
	int n = va_arg(arg_l, int);
	int val_d, len = 0;

	if (n < 0)
	{
		len += put_char('-');
		if (n == INT_MIN)
			n = INT_MAX;
		else
			n *= -1;
	}

	val_d = (int) cal_val(n, 10);

	while (val_d)
	{
		len += put_char(n / val_d + '0');
		n %= val_d;
		val_d /= 10;
	}
	return (len);
}

/**
 * cal_val - calculates place of the first digit
 * @n: the number givien
 * @base: base of the number
 * Return: place value
 */
size_t cal_val(size_t n, int base)
{
	int place_val = 1;

	while (n > (size_t)base)
	{
		place_val *= base;
		n /= base;
	}
	return (place_val);
}
