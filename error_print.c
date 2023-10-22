#include "main.h"

/**
 * print_error_non - function to print error msg.
 * @argv_0: is shell program.
 * @shell_arg: is command inserted by user.
 * @count: is count of commands inerted per session.
 */

void print_error_non(char *argv_0, char *shell_arg, int count)
{
	char *number = int_to_str(count);

	write(STDERR_FILENO, argv_0, strlen(argv_0));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, number, strlen(number));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, shell_arg, strlen(shell_arg));
	write(STDERR_FILENO, ": not found\n", strlen(": not found\n"));
	free(number);
}

/**
 * print_error - function to print error msg.
 * @argv_0: is shell program.
 * @shell_arg: is command inserted by user.
 */

void print_error(char *argv_0, char *shell_arg)
{
	write(STDERR_FILENO, argv_0, _strlen(argv_0));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, shell_arg, _strlen(shell_arg));
	write(STDERR_FILENO, ": command not found\n",
			_strlen(": command not found\n"));
}
