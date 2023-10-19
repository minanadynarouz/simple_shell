#include "main.h"

/**
 * _strncmp - compare strings till nth char
 * @s1: first string to be checked
 * @s2: second string to be checked
 * @n: limit to check to.
 * Return: 0 true if strings match, 1 if false
 */

int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	if (!s1 && !s2)
	{
		return (0);
	}
	if (!s1 || !s2)
	{
		return (-1);
	}

	for (i = 0; i < n && s1[i] != '\0' && s2[i] != '\0'; i++)
	{
		if (s1[i] != s2[i])
		{
			return ((int)(unsigned char)s1[i] - (int)(unsigned char)s2[i]);
		}
	}
	return (0);
}

/**
 * _strcmp - compare strings
 * @s1: first string to be checked
 * @s2: second string to be checked
 * Return: 0 true if strings match, 1 if false
 */

int _strcmp(char *s1, char *s2)
{
	int i, counter1, counter2, diff_success;

	if (!s1 || !s2)
	{
		return (0);
	}

	counter1 = 0;
	for (i = 0; s1[i] != '\0'; i++)
	{
		counter1++;
	}

	counter2 = 0;
	for (i = 0; s2[i] != '\0'; i++)
	{
		counter2++;
	}

	diff_success = 0;
	for (i = 0; i < counter1 || i < counter2; i++)
	{
		if (s1[i] == s2[i])
		{
			diff_success = 0;
		}
		else
		{
			diff_success++;
			return (s1[i] - s2[i]);
		}
	}
	return (diff_success);
}

/**
 * _strlen - calculate length of a string
 * @s: variable to be checked
 * Return: length of the string
 */

int _strlen(char *s)
{
	int i, counter;

	counter = 0;
	for (i = 0; *(s + i) != '\0'; i++)
	{
		counter++;
	}
	return (counter);
}

/**
 * _strdup - function to create array to store a string copy
 * @str: size var to copied
 * Return: Pointer to first element of array
 */

char *_strdup(char *str)
{
	char *arr = NULL;
	int i, len;

	if (str == NULL)
	{
		return (NULL);
	}

	for (i = 0, len = 0; str[i]; i++)
	{
		len++;
	}

	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (arr == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < len; i++)
	{
		arr[i] = str[i];
	}
	arr[i] = '\0';
	return (arr);
}
