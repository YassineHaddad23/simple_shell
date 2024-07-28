#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * _cd - Change directory.
 * @args: List of arguments.
 *
 * Return: 1 if the command was executed successfully, 0 otherwise.
 */
int _cd(char **args)
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "hsh: expected argument to \"cd\"\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("hsh");
		}
	}
	return (1);
}

/**
 * _help - Display help information.
 * @args: List of arguments.
 *
 * Return: Always returns 1.
 */
int _help(char **args)
{
	printf("Type program names and arguments, and hit enter.\n");
	printf("The following are built-in commands:\n");

	printf("cd: Change directory\n");
	printf("help: Display this help message\n");
	printf("exit: Exit the shell\n");

	return (1);
}

/**
 * _exit_shell - Exit the shell.
 * @args: List of arguments.
 *
 * Return: Always returns 0, to terminate execution.
 */
int _exit_shell(char **args)
{
	return (0);
}

