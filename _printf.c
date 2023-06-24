#include "main.h"

/**
 * _printf - produces a formatted output
 * @format: character string to be formatted & printed
 * Return: Length of the formatted output
*/
int _printf(const char *format, ...)
{
    int lenStr = 0;

    for (; *format; format++)
    {
        putChar(*format);
        lenStr++;
    }
    return(lenStr);
}
