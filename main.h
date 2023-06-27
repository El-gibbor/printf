#ifndef PRINT_F
#define PRINT_F

/* Header files.. */
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <limits.h>

/* function types */
int print_ch(char);
int print_int(va_list);
int print_unint(va_list);
int print_hex_l(va_list);
int print_hex_u(va_list);
int print_bin(va_list);
int print_oct(va_list);
int print_str(va_list);
int _printf(const char *format, ...);

/* struct */
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
