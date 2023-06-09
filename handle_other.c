#include "main.h"

/**
 * handle_other - handles other commands that are not in PATH
 * @command: array of tokenized user commands
 * @user_input: raw input from the user
 * @exit_status: the exit status of the last command
 * @env: the environment variable passed by the program
 * @av:name of program
 *
 * Return: retuns 1 if command is found, 0 if not
 */
int handle_other(char **command, char *user_input, int exit_status,
		 char **env, char *av)
{
	if (!_strcmp(command[0], "exit")) /* exit command */
		handle_exit(command, user_input, exit_status);
	if (!_strcmp(command[0], "setenv")) /* setenv command */
	{
		handle_setenv(command);
		return (0);
	}
	if (!_strcmp(command[0], "unsetenv")) /* unsetenv command */
	{
		handle_unsetenv(command);
		return (0);
	}
	if (!_strcmp(command[0], "env")) /* default env command */
	{
		handle_env(env);
		return (0);
	}
	if (!_strcmp(command[0], "$$") || !_strcmp(command[0], "$?"))
		handle_replacement(&command[0], exit_status);
	/* echo command */
	if (!_strcmp(command[0], "echo"))
	{
		if (command[1] == NULL)
		{
			write(1, "\n", 1);
			return (0);
		}
		handle_echo(command, exit_status, env);
		return (0);
	}
	/* cd command - changing directory */
	if (!_strcmp(command[0], "cd"))
	{
		change_dir(command, av);
		return (0);
	}
	return (-1);
}

/**
 * handle_echo - handles the default echo command
 * @command: array of tokenized user input
 * @exit_status: the exit status of the last process
 * @env: the environment variable from the program
 */
void handle_echo(char **command, int exit_status, char **env)
{
	pid_t pid = getpid();
	char pid_str[32], exit_str[32];
	char *path;
	int i;

	_itoa(pid, pid_str, 10);
	_itoa(exit_status, exit_str, 10);
	for (i = 1; command[i] != NULL; i++)
	{
		if (i > 1)
			_puts(" ");
		if (!_strcmp(command[i], "$?"))
		{
			write(1, exit_str, _strlen(exit_str));
			continue;
		}
		if (!_strcmp(command[i], "$$"))
		{
			write(1, pid_str, _strlen(pid_str));
			continue;
		}
		if (!_strcmp(command[i], "$PATH"))
		{
			path = get_path(env);
			_puts(path);
			free(path);
			continue;
		}
		_puts(command[i]);
	}
	_puts("\n");
}

/**
 * handle_replacement - replaces the $? and $$ commands
 * @command: the address of the command to replace
 * @exit_status: exit status of the previous command
 */
void handle_replacement(char **command, int exit_status)
{
	pid_t pid = getpid();

	if (!_strcmp(*command, "$$"))
		_itoa(pid, *command, 10);

	if (!_strcmp(*command, "$?"))
		_itoa(exit_status, *command, 10);
}

/**
 * handle_setenv - sets environment variables
 * @input_toks: tokenized user input
 *
 * Return: void
 */
void handle_setenv(char **input_toks)
{
	int overwrite = 1, ret;

	if (input_toks[1] == NULL || input_toks[2] == NULL)
	{
		_puts("setenv: Too few arguments \n");
		return;
	}
	if (input_toks[3] != NULL)
	{
		_puts("setenv: Too many arguments \n");
		return;
	}

	ret = setenv(input_toks[1], input_toks[2], overwrite);

	if (ret != 0)
		perror("setenv");
}

/**
 * handle_unsetenv - unsets environment variables
 * @input_toks: tokenized user input
 *
 * Return: void
 */
void handle_unsetenv(char **input_toks)
{
	int ret;

	if (input_toks[1] == NULL)
	{
		_puts("unsetenv: Too few arguments \n");
		return;
	}
	if (input_toks[2] != NULL)
	{
		_puts("unsetenv: Too many arguments \n");
		return;
	}

	ret = unsetenv(input_toks[1]);

	if (ret != 0)
		perror("unsetenv");
}
