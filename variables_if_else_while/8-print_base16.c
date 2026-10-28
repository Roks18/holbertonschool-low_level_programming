
#include <stdio.h>

/**
 * main - Prints numbers in base 16 in lowercase
 *
 * Return: Always 0
 */
int main(void)
{
	int number;

	number = 0;
	while (number < 16)
	{
		if (number < 10)
			putchar(number + '0');
		else
			putchar(number - 10 + 'a');
		number++;
	}
	putchar('\n');
	return (0);
}

