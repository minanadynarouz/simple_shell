#include "main.h"

/**
 * digits - to count digits in num
 * @x: the num to be checked.
 * Return: The count.
 */

int digits(int x)
{
	int i;

	for (i = 0; x != 0; i++, x /= 10)
		;
	return (i);
}

/**
 * int_to_str - convert num to string.
 * @num: Number to be converted.
 * Return: Char * holding the number.
 */

char *int_to_str(int num)
{
	int n_digits, i;
	char *number;

	n_digits = digits(num);
	number = malloc(n_digits * sizeof(char) + 2);
	if (num == 0)
	{
		number[0] = '0';
		number[1] = '\0';
		return (number);
	}

	number[n_digits] = '\0';
	for (i = n_digits - 1; num != 0; num /= 10, i--)
		number[i] = (num % 10) + '0';

	return (number);
}
