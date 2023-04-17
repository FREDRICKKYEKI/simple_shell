#include "main.h"

void handle_exit(char **command, char *input, int _exit)
{
	int exit_status = 0;

	if (!command[1])
	{
		free(input);
		free(command);
		exit(_exit);
	}
	exit_status = atoi(command[1]); /* should write own function */
	free(input);
	free(command);
	exit(exit_status);
}

void handle_env(char **env)
{
	size_t element = 0;

	while (env[element])
	{
		write(STDOUT_FILENO, env[element], _strlen(env[element]));
		write(STDOUT_FILENO, "\n", 1);
		element++;
	}
}
