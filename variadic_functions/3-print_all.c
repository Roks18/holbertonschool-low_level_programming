
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
	char *str;

	i = 0;
	printed = 0;

	va_start(args, format);

	while (format != NULL && format[i] != '\0')
	{
		switch (format[i])
		{
		case 'c':
			switch (printed)
			{
			case 1:
				printf(", ");
				break;
			}
			printf("%c", va_arg(args, int));
			printed = 1;
			break;
		case 'i':
			switch (printed)
			{
			case 1:
				printf(", ");
				break;
			}
			printf("%d", va_arg(args, int));
			printed = 1;
			break;
		case 'f':
			switch (printed)
			{
			case 1:
				printf(", ");
				break;
			}
			printf("%f", va_arg(args, double));
			printed = 1;
			break;
		case 's':
			switch (printed)
			{
			case 1:
				printf(", ");
				break;
			}
			str = va_arg(args, char *);
			if (str == NULL)
				printf("(nil)");
			if (str != NULL)
				printf("%s", str);
			printed = 1;
			break;
		}
		i++;
	}

	va_end(args);
	printf("\n");
}

