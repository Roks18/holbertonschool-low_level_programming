#include <stdio.h>
#include <stdarg.h>
#include "variadic_functions.h"

/**
 * print_all - prints anything
 * @format: list of types of arguments
 */
void print_all(const char * const format, ...)
{
	va_list args;
	unsigned int i;
	int printed;

	i = 0;
	printed = 0;

	va_start(args, format);

	while (format != NULL && format[i] != '\0')
	{
		if (format[i] == 'c' || format[i] == 'i'
		    || format[i] == 'f' || format[i] == 's')
		{
			if (printed)
				printf(", ");

			switch (format[i])
			{
			case 'c':
				printf("%c", va_arg(args, int));
				break;
			case 'i':
				printf("%d", va_arg(args, int));
				break;
			case 'f':
				printf("%f", va_arg(args, double));
				break;
			case 's':
				{
					char *str = va_arg(args, char *);

					if (str == NULL)
						printf("(nil)");
					else
						printf("%s", str);
				}
				break;
			}
			printed = 1;
		}
		i++;
	}

	va_end(args);
	printf("\n");
}

