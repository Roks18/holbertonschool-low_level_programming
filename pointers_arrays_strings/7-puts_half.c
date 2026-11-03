
#include "main.h"

/**
 * puts_half - prints the second half of a string
 * @str: string to print
 *
 * Return: Nothing
 */
void puts_half(char *str)
{
	int length;
	int i;
	int start;

	length = 0;
	while (str[length] != '\0')
	{
		length++;
	}

	start = length / 2;
	if (length % 2 != 0)
	{
		start = (length + 1) / 2;
	}

	i = start;
	while (str[i] != '\0')
	{
		_putchar(str[i]);
		i++;
	}
	_putchar('\n');
}

