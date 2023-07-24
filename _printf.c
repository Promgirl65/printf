#include <stdio.h>
#include <stdarg.h>

/*
 * main - _printf.c
 * Description: A simplified implementation of the printf function in C.
 * Author: [Siyabonga Msomi & Balikis Gbemi Olayinka]
 */

int _printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);

    int count = 0;
    const char *ptr = format;

    while (*ptr != '\0')
    {
        if (*ptr == '%')
        {
            ptr++;
            if (*ptr == 'c')
            {
                int c = va_arg(args, int);
                putchar(c);
                count++;
            }
            else if (*ptr == 's')
            {
                char *s = va_arg(args, char *);
                while (*s != '\0')
                {
                    putchar(*s);
                    s++;
                    count++;
                }
            }
            else if (*ptr == '%')
            {
                putchar('%');
                count++;
            }
        }
        else
        {
            putchar(*ptr);
            count++;
        }
        ptr++;
    }

    va_end(args);
    return count;
}

int main()
{
    _printf("Hello, %s! The answer is %d%c\n", "world", 42, '%');
    return 0;
}
