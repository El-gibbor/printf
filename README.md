![prin](https://github.com/ehoneahobed/alx-low_level_programming/assets/121310192/886374db-445c-4236-97fd-41d87432d349)  
# _printf()  
This repo contains a custom reimplementation of C's `printf()` function. It is a team effort of [Bernard](github.com/teflon40) and [Elgibbor](https://www.linkedin.com/in/elgibbor/), aimed  to demonstrate our understanding of the concepts learned thus far in the [Alx](alxafrica.com) low-level programming track in C language and apply them to create a practical utility.  
This custom `_printf()` function will handle various conversion specifiers and provide additional functionalities as required.  
__Prototype:__ `int _printf(const char *format, ...);`  
__Returns:__ The number of characters printed (excluding the null byte used to end output to strings), write output to stdout, the standard output stream format is a character string. The format string is composed of zero or more directives.
## Functionalities
The `_printf()` function is designed to handle the following conversion specifiers:  
* `%c`: Print a single character.  
* `%s`: Print a null-terminated string.  
* `%%`: Print a literal `%` character.  
* `%d` or `%i`: Print a signed decimal integer.  
* `%u`: Print an unsigned decimal integer.  
* `%o`: Print an unsigned octal integer.  
* `%x` or `%X`: Print an unsigned hexadecimal integer 
* `%p`: Print a pointer (an address).
* `r`: prints the reversed string.
* `R`: prints the rot13'ed string.
* Handle the field width for non-custom conversion specifiers.
* Handle the precision for non-custom conversion specifiers.
* Handle the 0 flag character for non-custom conversion specifiers.
* `S`: prints the string. Non-printable characters (0 < ASCII value < 32 or >= 127) are printed this way: `\x`, followed by the ASCII code value in hexadecimal (upper case - always 2 characters).⤵️
```
int main(void)
{
    _printf("%S\n", "Best\nSchool");
    return (0);
}
elgibbor@ubuntu:~/alx_c/printf$ gcc -Wall -Wextra -Werror -pedantic -std=gnu89 main.c
elgibbor@ubuntu:~/alx_c/printf$ ./a.out
Best\x0ASchool
```
Handle the following length modifiers for non-custom conversion specifiers:`l`, `h`. Conversion specifiers to handle: `d`, `i`, `u`, `o`, `x`, `X`.  
In addition to the above conversion specifiers, the custom implementation will also handle the following custom conversion specifier:  
* `%b`: Print an unsigned integer in binary format.  
Our `_printf()` function will also support the following flag characters for non-custom conversion specifiers: `+`, `space`, `#`
## Buffer Optimization  
To minimize the number of calls to the underlying `write` function, our custom `_printf()` function will use a local buffer of 1024 characters. The data will be written to the output in chunks, ensuring efficient utilization of system resources.  
## Authors/Contributors  
Benard Frimpong - [Github](github.com/teflon40/)  
Chiagoziem Elgibbor - [Linkedin](https://www.linkedin.com/in/elgibbor/) | [Blog](https://elgibbor.hashnode.dev/) | [Twitter](https://twitter.com/Mr_Elgibbor)
