#include "main.h"

/**
 * _strcpy - Copy a string to another
 * @dest: Destination var to receive
 * @src: Source to copy from
 * Return: value of dest
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	if (dest == NULL || src == NULL)
	{
		return (NULL);
	}

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strcat - Concatenates two strings
 * @dest: String to receive
 * @src: Source string
 * Return: A string concatenated
 */

char *_strcat(char *dest, const char *src)
{
	int i, j;

	if (dest == NULL || src == NULL)
	{
		return (NULL);
	}

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}

	j = 0;
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

/**
 * is_num - Check if n is a digit
 * @n: Number
 * Return: If n is a number, return 1 else return 0
 */

int is_num(unsigned int n)
{
	return (n >= '0' && n <= '9');
}

/**
 * _atoi - convert a string to an integer
 * @s: String to be converted to int
 * Return: integer
 */

int _atoi(char *s)
{
	unsigned int number, i;
	int sign;

	sign = 1;
	number = 0;
	for (i = 0; s[i] != '\0'; i++)
	{
		if (is_num(s[i]))
		{
			number = (s[i] - 48) + number * 10;

			if (s[i + 1] == ' ')
				break;
		}
		else if (s[i] == '-')
		{
			sign *= -1;
		}
	}
	return (number * sign);
}

/**
 * slash_count - func to count num of slash occurance.
 * @args: var to check slashes in it.
 * Return: Count of slashes.
 */

int slash_count(char *args)
{
	int i, slash;

	i = 0;
	slash = 0;
	while (args[i])
	{
		if (args[i] == '/')
		{
			slash += 1;
			break;
		}
		i++;
	}
	return (slash);
}
