#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>

int putChar(char c);
int charcmp(char c1, char c2);
int printStrLiteral(va_list argList);
int _printf(const char *format, ...);
int (*selectFunc(char formSpec))(va_list argList);
int printChar(va_list argList);

#endif
