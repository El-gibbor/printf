#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>

int putChar(char c);
int printStrLiteral(char *str);
int _printf(const char *format, ...);
int (*getFormatFunc(char c))(va_list);
int printChar(char c);

/**
 * struct format - struct template for format
 * @c: character to return its corresponding fomat func
 * @formatFunc: func pointer to the corresponding format func
*/
typedef struct format
{
    char c;
    int (*formatFunc)(va_list);
} formatStruct;

#endif