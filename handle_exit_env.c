#include "main.h"

/**
 * handle_exit - handles the exit command
 * @command: array of tokenized commands by the user
 * @input: the input from the user
 * @_exit: the exit status from the last executed function
 */
void handle_exit(char **command, char *input, int _exit)
{
	int exit_status = 0;

	if (!command[1])
	{
		free(input);
		free(command);
		exit(_exit);
	}
	exit_status = _atoi(command[1]); /* should write own function */
	free(input);
	free(command);
	exit(exit_status);
}

/**
 * handle_env - handles the builtin env command
 * @env: the environment variable passed from the program
 */
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
