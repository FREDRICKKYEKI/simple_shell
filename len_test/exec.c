#include "main.h"

int execute(char **command, char **av, char **env, char *input, int path_ret)
{
	pid_t child_process;
	int status, exit_status, i;

	(void)path_ret;
	child_process = fork();

	if (child_process == 0)
	{
		if (execve(command[0], command, env) == -1)
		{
			perror(av[0]);
			for (i = 0; command[i]; i++)
				free(command[i]);
			free(command);
			free(input);
			exit(errno);
		}
	}
	else if (child_process == -1)
	{
		perror(av[0]);
		for (i = 0; command[i]; i++)
			free(command[i]);
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
