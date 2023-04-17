#include "main.h"

int execute(char **command, char **av, char **env, char *input, int process,
	    int path_ret)
{
	pid_t child_process;
	int status;

	(void)process;
	child_process = fork();

	if (child_process == 0)
	{
		if (execve(command[0], command, env) == -1)
		{
			perror(av[0]);
			if (path_ret == 0)
				free(command[0]);
			free(command);
			free(input);
			exit(errno);
		}
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
			return (WEXITSTATUS(status));
	}
	return (0);
}
