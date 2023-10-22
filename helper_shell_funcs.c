#include "main.h"

/**
 * readline - read commands from stdin.
 * Return: char pointer to the chars red.
 */

char *readline(void)
{
	char *line = NULL;
	size_t n = 0;

	if (_getline(&line, &n, stdin) == -1)
	{
		if (feof(stdin))
		{
			free(line);
			write(STDOUT_FILENO, "\n", 1);
			exit(EXIT_SUCCESS);
		}
		free(line);
		perror("Error reading from stdin");
		exit(EXIT_FAILURE);
	}
	return (line);
}

/**
 * split_string - split string for cmd
 * @string: command to be split.
 * Return: Array of strings.
 */

char **split_string(char *string)
{
	int buffer = 64, i = 0;
	char *token = NULL, **arr_of_strings = NULL, **temp = NULL;

	if (string == NULL)
		return (NULL);
	arr_of_strings = malloc(buffer * sizeof(char *));
	if (arr_of_strings == NULL)
		perror("Memory allocation failed\n"), exit(EXIT_FAILURE);

	token = strtok(string, DELIM);
	while (token != NULL)
	{
		if (i >= buffer)
		{
			buffer += 64;
			temp = realloc(arr_of_strings, buffer * sizeof(char *));
			if (temp == NULL)
			{
				free_memory_array(arr_of_strings);
				perror("Memory reallocation failed\n"), exit(EXIT_FAILURE);
			}
			arr_of_strings = temp;
		}

		arr_of_strings[i] = _strdup(token);
		if (arr_of_strings[i] == NULL)
		{
			free_memory_array(arr_of_strings);
			perror("Memory allocation for token failed\n"), exit(EXIT_FAILURE);
		}
		i++;
		token = strtok(NULL, DELIM);
	}
	arr_of_strings[i] = NULL;
	return (arr_of_strings);
}

/**
 * print_env - func to print environment variable.
 */

void print_env(void)
{
	char **envp;

	for (envp = environ; *envp; envp++)
	{
		write(STDOUT_FILENO, *envp, _strlen(*envp));
		write(STDOUT_FILENO, "\n", 1);
	}
}

/**
 * stat_file_in_path - split path, check cmd workability
 * create new path cmd based on user input.
 * @args: user input from shell.
 * Return: char pointer with cmd to be executed.
 */

char *stat_file_in_path(char *args)
{
	struct stat st;
	char *token = NULL, *file_path, *file_path_dup = NULL;
	int slash, token_len = 0, args_len = 0;
	char *path = _getenv("PATH"), *path_copy = _strdup(path);

	if (args == NULL)
		return (NULL);
	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		token_len = _strlen(token);
		args_len = _strlen(args);
		file_path = malloc(token_len + args_len + 2);
		if (file_path == NULL)
		{
			free(file_path);
			perror("Error in memory allocation for Path\n"), exit(EXIT_FAILURE);
		}
		slash = slash_count(args);
		if (slash == 0)
		{
			_strcpy(file_path, token);
			_strcat(file_path, "/");
			_strcat(file_path, args);
		}
		else
			_strcpy(file_path, args);
		if (stat(file_path, &st) == 0)
		{
			if (file_path_dup != NULL)
				free(file_path_dup);
			file_path_dup = _strdup(file_path);
		}
		free(file_path);
		token = strtok(NULL, ":");
	}
	free(path_copy);
	return (file_path_dup);
}
