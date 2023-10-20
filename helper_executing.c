#include "main.h"

/**
 * execute_builtIn_args - func to execute built ins like
 * env, exit with args or without, cd.
 * @args: arg to check matching funcs or not.
 * Return: 10 if exit, 20 if exit with args
 * 0 if other cmd.
 */

int execute_builtIn_args(char **args)
{
	if (args[0] == NULL || args == NULL)
		return (100);
	if (_strcmp(args[0], "exit") == 0 && args[1] == NULL)
		return (10);
	if (_strcmp(args[0], "exit") == 0 && args[1] != NULL)
		return (20);
	if (_strcmp(args[0], "cd") == 0)
		return (30);
	return (0);
}

/**
 * execute_cmd - func to execute the cmds with
 * creating a child process to handle.
 * @cmd: first cmd of the shell.
 * @args: rest of arguments.
 * Return: 0 if success, -1 otherwise.
 */

int execute_cmd(char *cmd, char **args)
{
	pid_t child_pid;
	int status;
	char **envp = {environ};

	if (cmd)
	{
		child_pid = fork();

		if (child_pid == -1)
		{
			perror("Fork");
			return (-1);
		}
		if (child_pid == 0)
		{
			if (execve(cmd, args, envp) == -1)
			{
				perror("Error\n");
				exit(0);
			}
		}
		else
		{
			wait(&status);
			if (WIFEXITED(status))
			{
				return (WEXITSTATUS(status));
			}
		}
	}
	return (-1);
}

/**
 * read_stream - func to execute cmd in
 * non-interactive shell
 * Return: steam inserted to be exeucted.
 */

char *read_stream(void)
{
	int bufSize = 1024, i = 0, character;
	char *line = malloc(bufSize);

	if (line == NULL)
	{
		perror("allocation error in read_stream\n"), exit(EXIT_FAILURE);
	}
	while (1)
	{
		character = getchar();
		if (character == EOF || character == '\n')
		{
			if (i == 0)
			{
				free(line);
				return (NULL);
			}
			else
			{
				line[i] = '\0';
				return (line);
			}
		}
		else
		{
			line[i] = character;
			i++;
		}
		if (i >= bufSize)
		{
			bufSize += 1024;
			line = realloc(line, bufSize);
			if (line == NULL)
				perror("reallocation error in read_stream\n"), exit(EXIT_FAILURE);
		}
	}
	free(line);
	return (line);
}
