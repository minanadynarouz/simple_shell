#include "main.h"

/**
 * _getline - function to read stream from stdin.
 * @lineptr: to store the string from stdin.
 * @n: size to read.
 * @stream: stream of input to read.
 * Return: count of chars read.
 */

ssize_t _getline(char **lineptr, size_t *n, FILE *stream)
{
	int ch;
	size_t i = 0, new_size;
	char *line = NULL, *new_line = NULL;

	if (lineptr == NULL || n == NULL)
		return (-1);
	*n = 128;
	if (*lineptr == NULL)
	{
		*lineptr = (char *)malloc(*n);
		if (*lineptr == NULL)
			return (-1);
	}
	line = *lineptr;
	while ((ch = fgetc(stream)) != EOF)
	{
		if (i + 1 >= *n)
		{
			new_size = *n * 2;
			new_line = (char *)realloc(line, new_size);
			if (new_line == NULL)
			{
				free(line);
				return (-1);
			}
			*lineptr = line = new_line;
			*n = new_size;
		}
		line[i++] = (char)ch;
		if (ch == '\n')
		{
			line[i] = '\0';
			return (i);
		}
	}
	if (i == 0)
		return (-1);
	line[i] = '\0';
	return (i);
}
