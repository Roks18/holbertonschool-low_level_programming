
#include "main.h"

/**
 * _strspn - gets the length of a prefix substring
 * @s: string to check
 * @accept: characters to accept
 *
 * Return: number of accepted characters
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int i;
	unsigned int j;
	unsigned int count;

	i = 0;
	count = 0;

	while (s[i] != '\0')
	{
		j = 0;

		while (accept[j] != '\0')
		{
			if (s[i] == accept[j])
				break;
			j++;
		}

		if (accept[j] == '\0')
			return (count);

		count++;
		i++;
	}

	return (count);
}

