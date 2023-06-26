#ifndef PRINT_F
#define PRINT_F

/* Header files */
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

/* function types */
int print_ch(char);
int print_num(va_list);
int print_str(va_list);
int _printf(const char *format, ...);

#endif
