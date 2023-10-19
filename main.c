#include "main.h"

/**
 * main - main program that execute either interactive
 * or non-interactive shells.
 * @argc: arguments count, but not used in our program.
 * @argv: argument vector for inputs.
 * Return: 0 by default.
 */

int main(int __attribute__((__unused__)) argc, char **argv)
{
	if (isatty(STDIN_FILENO) == 1)
	{
		interactive_shell(argv[0]);
	}
	else
	{
		non_interactive_shell(argv[0]);
	}
	return (0);
}
