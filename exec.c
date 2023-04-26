#include "main.h"

/**
 * execute - executes a given command
 * @command: array of commands from the command line
 * @av: list containing name of the program
 * @env: array of environment variables
 * @input: input from the user
 * @path_ret: return value of the get path function
 *
 * Return: returns 0 on success or exit status on error
 */
int execute(char **command, char **av, char **env, char *input, int path_ret)
{
	pid_t child_process;
	int status, exit_status;

	(void)path_ret;
	child_process = fork();

	if (child_process == 0)
	{
		if (execve(command[0], command, env) == -1)
		{
			perror(av[0]);
			if (!path_ret)
				free(command[0]);
			free(command);
			free(input);
			exit(errno);
		}
	}
	else if (child_process == -1)
	{
		perror(av[0]);
		if (!path_ret)
			free(command[0]);
		free(command);
		free(input);
		exit(errno);
	}
	else
	{
		wait(&status);
		if (EXIT(status))
		{
			exit_status = STATUS(status);
			return (exit_status);
		}
	}
	return (0);
}
