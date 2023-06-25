#include "main.h"

/**
 * _printf - produces a formatted output
 * @format: character string to be formatted & printed
 * Return: Length of the formatted output
*/
int _printf(const char *format, ...)
{
    va_list argList;
    int i, lenStr = 0;
    int (*formatFunc)(va_list, int);

    va_start(argList, format);
    for (; *format; format++)
    {
        if (*format != '%')
        {
            lenStr += printStrLiteral((char *)format);
            format += myStrlen((char *)format) - 1;
        }
        else
        {
            format++;
            if (*format == '%')
            {
                lenStr += printChar(argList, lenStr);
            }
            else
             formatFunc = getFormatFunc((char *)format);
             if (formatFunc)
                lenStr += formatFunc(argList, lenStr);
             else
             {
                putChar('%');
                putChar(*format);
                lenStr += 2;
             }
        }
    }
    va_end(argList);
    return(lenStr);
}
