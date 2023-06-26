#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int len, len2;

    len = _printf("Let's try %c%c %% to printf %c %% a simple %s.\n",'A', 'A', 'B', "string");
    printf("%d\n", len);
    len2 = printf("Let's try %c%c %% to printf %c %% a simple %s.\n", 'A', 'A', 'B', "string");
    printf("%d\n", len2);
    return (0);
}
