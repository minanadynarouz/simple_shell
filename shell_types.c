#include "main.h"

/**
 * execute_builtIn_args_in_shell - function to implement builtins
 * @builtIn: function pointer to call built in func.
 * @line: the line from input stream.
 * @args: arguments after split.
 */

void execute_builtIn_args_in_shell(int (*builtIn)(char **),
		char *line, char **args, char *argv_0)
{
	int status, exit_num = 0;

	status = builtIn(args);
	if (status == 10)
	{
		free(line);
		free_memory_array(args);
		exit(0);
	}
	else if (status == 20)
	{
		exit_num = _atoi(args[1]);
		if ((exit_num == 0 && strcmp(args[1], "0") != 0) || exit_num < 0)
		{
			write(STDERR_FILENO, argv_0, _strlen(argv_0));
                        write(STDERR_FILENO, ": 1: ", _strlen(": 1: "));
                        write(STDERR_FILENO, "exit: ", _strlen("exit: "));
                        write(STDERR_FILENO, "Illegal number: ", _strlen("Illegal number: "));
                        write(STDERR_FILENO, args[1], _strlen(args[1]));
			write(STDERR_FILENO, "\n", 1);
			free(line);
			free_memory_array(args);
			exit(2);
		}
		else
		{
			free(line);
                        free_memory_array(args);
                        exit(exit_num);
		}
	}
}

/**
 * interactive_shell - execute commands based on terminal.
 * @argv_0: program itself
 */

void interactive_shell(char *argv_0)
{
	char **args = NULL, *line = NULL, *cmd_file_path = NULL;
	int status;

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);
		line = readline();
		if (line == NULL || _strcmp(line, "\n") == 0)
		{
			free(line);
			continue;
		}
		args = split_string(line);
		if (args == NULL)
		{
			perror("Error splitting input\n");
			free(line);
			continue;
		}
		execute_builtIn_args_in_shell(execute_builtIn_args, line, args, argv_0);
		cmd_file_path = stat_file_in_path(args[0]);
		if (cmd_file_path != NULL)
		{
			status = execute_cmd(cmd_file_path, args);
			if (status != 0)
			{
				free_memory_all(3, cmd_file_path, 1, line, 1, args, 0);
				continue;
			}
			free(cmd_file_path);
		}
		else
		{
			print_error(argv_0, args[0]);
		}
		free_memory_all(2, line, 1, args, 0);
	}
}

/**
 * non_interactive_shell - execute commands based on scripts.
 * @argv_0: representing argv[0] which is
 * the program file itself
 */

void non_interactive_shell(char *argv_0)
{
	char **args;
	char *line;
	int status, commandCountNonInteractive = 0;
	char *cmd_file_path;

	while ((line = read_stream()) != 0)
	{
		commandCountNonInteractive += 1;
		args = split_string(line);
		if (args == NULL)
		{
			perror("Error splitting input\n");
			free(line);
			continue;
		}
		execute_builtIn_args_in_shell(execute_builtIn_args, line, args, argv_0);
		cmd_file_path = stat_file_in_path(args[0]);
		if (cmd_file_path != NULL)
		{
			status = execute_cmd(cmd_file_path, args);
			if (status != 0)
			{
				free_memory_all(3, cmd_file_path, 1, line, 1, args, 0);
				exit(2);
			}
			free(cmd_file_path);
		}
		else
		{
			print_error_non(argv_0, args[0], commandCountNonInteractive);
			exit(127);
		}
		free_memory_all(2, line, 1, args, 0);
	}
}
