#include "main.h"

/**
 * free_memory_array - function to free char arrays.
 * @item: is array to be freed.
 */

void free_memory_array(char **item)
{
	int i = 0;

	for (i = 0; item[i] != NULL; i++)
	{
		free(item[i]);
	}
	free(item);
}

/**
 * free_memory_all - function to free char * or char **.
 * @count: count of inputs.
 * @...: elipsis to get an many args as needed.
 */

void free_memory_all(int count, ...)
{
	void *str_or_str_array;
	char *str = NULL, **str_array = NULL;
	int i, j;
	va_list args;

	va_start(args, count);
	for (i = 0; i < count; i++)
	{
		str_or_str_array = va_arg(args, void *);
		if (str_or_str_array == NULL)
		{
			continue;
		}

		if (va_arg(args, int) == 1)
		{
			str = str_or_str_array;
			free(str);
		}
		else
		{
			str_array = str_or_str_array;
			for (j = 0; str_array[j] != NULL; j++)
			{
				free(str_array[j]);
			}
			free(str_array);
		}
	}
}
