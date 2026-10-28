#include <stdio.h>

/**
 * main - Prints single digit numbers in base 10
 *
 * Return: Always 0
 */
int main(void)
{
	int number;

	number = 0;
	while (number <= 9)
	{
		printf("%d", number);
		number++;
	}
	printf("\n");
	return (0);
}
