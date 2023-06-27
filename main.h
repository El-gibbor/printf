#ifndef PRINT_F
#define PRINT_F

/* Header files.. */
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <limits.h>

/* function types */
int format_spec(const char *, int *, int *, va_list);
int print_ch(va_list);
int print_int(va_list);
int print_unint(va_list);
int print_hex_l(va_list);
int print_hex_u(va_list);
int print_bin(va_list);
int print_oct(va_list);
int print_str(va_list);
int _printf(const char *format, ...);
int put_char(char);
size_t cal_val(size_t n, int base);

/**
 * struct conv - template for format conversion
 * @c: the format specifiers
 * @f: ptr to the corresponding func for @c
 */
typedef struct conv spec_conv;
struct conv
{
	char c;
	int (*f)(va_list);
};

#define HEX 16
#define BIN 2
#define OCT 8

#endif
