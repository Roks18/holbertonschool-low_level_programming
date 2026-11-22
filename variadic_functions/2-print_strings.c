#include "variadic_functions.h"
#include <stdarg.h>
#include <stddef.h>

/**
 * print_strings - prints strings separated by a separator
 * @separator: string between strings
 * @n: number of arguments
 */
void print_strings(const char *separator, const unsigned int n, ...)
{
	va_list args;
	unsigned int i;
	char *str;

	va_start(args, n);

	for (i = 0; i < n; i++)
	{
		str = va_arg(args, char *);

		if (str == NULL)
			str = "(nil)";

		while (*str)
		{
			_putchar(*str);
			str++;
		}

		if (separator != NULL && i < n - 1)
		{
			while (*separator)
			{
				_putchar(*separator);
				separator++;
			}
			separator -= 2;
		}
	}

	va_end(args);
	_putchar('\n');
}

