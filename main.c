#include "main.h"

/**
 * main - where execution begins
 * @ac: argument count from commandline
 * @av: array of argument strings
 * @env: environment variable from the program
 *
 * Return: returns 0 on successful execution
 */
int main(int __attribute__((unused)) ac, char **av, char **env)
{
	char *user_input = NULL, **command = NULL;
	int exit_status = 0, path_ret = 0;
	int nth_process = 0;

	while (1)
	{
		user_input = _getline();
		if (!user_input) /* if getline fails */
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			exit(exit_status);
		}
		else
		{
			nth_process++;
			command = get_token(user_input); /* split command */
			if (!command)
			{
				free(command);
				continue;
			}
			exit_status = handle_other(command, user_input, exit_status,
						   env, av[0]);
			if (exit_status == -1)
			{
				path_ret = handle_path(&command[0], env);
				exit_status = execute(command, av, env,
						      user_input, path_ret,
						      nth_process);
				if (path_ret == 0)
					free(command[0]);
			}
			free(command);
		}
		free(user_input);
	}
	return (exit_status);
}
