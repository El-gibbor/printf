#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>

int putChar(char c);
int printStrLiteral(char *str);
int _printf(const char *format, ...);
int printChar(char c);

#endif