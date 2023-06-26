/* Header guard */
#ifndef PRINT_F
#define PRINT_F

/* Header files */
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

/* function types */
int print_ch(char);
int prnt_num(va_list);
int prnt_str(va_list);
int _printf(const char *format, ...);





#endif
