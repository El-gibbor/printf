#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>

int putChar(char c);
int myStrlen(char *str);
int myStrcmp(char *s1, char *s2);
int printStrLiteral(char *str);
int _printf(const char *format, ...);
int (*getFormatFunc(char spec))(va_list, int);
int printChar(va_list argList, int lenStr);

/**
 * structs formats - holds conversion specifier and their functions
 * @specifier: conversion specifiers
 * 
*/
typedef struct printFormat
{
    char formSpec;
    int (*formatFunc)(va_list, int);
} convFunc;

#endif