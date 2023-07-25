#include <stdio.h>
#include <stdarg.h>

int _printf(const char *format, ...)
{
	int all_set = 0;
	char c;
	char *str;
	
	va_list args;
	va_start(args, format);
	
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					c = (char) va_arg(args, int);
					putchar(c);
					all_set++;
					break;

				case 's':
					str = va_arg(args, char*);
					while (*str)
					{
						putchar(*str);
						str++;
						all_set++;
					}
					break;

				case '%':
					putchar('%');
					all_set++;
					break;
			}
		}
		else
		{
			putchar(*format);
			all_set++;
		}

		format++;
	}

	va_end(args);
	return all_set;
}
