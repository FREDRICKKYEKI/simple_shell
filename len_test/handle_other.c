#include "main.h"

int handle_other(char **command, char *user_input, int exit_status,
		 char **env)
{
	if (!_strcmp(command[0], "exit"))
		handle_exit(command, user_input, exit_status);
	if (!_strcmp(command[0], "env"))
	{
		handle_env(env);
		return (1);
	}
	if (!_strcmp(command[0], "echo"))
	{
		if (command[1] == NULL)
		{
			write(1, "\n", 1);
			return(1);
		}
		handle_echo(command, exit_status, env);
		return (1);
	}
	/* if (!_strcmp(command[0], "cd"))
	 * {
	 *	change_dir(command, env);
	 *	return (1);
	 *} */
	return (0);
}

void handle_echo(char **command, int exit_status, char **env)
{

	pid_t pid = getpid();
	char pid_str[32], exit_str[32];
	char *path;
	int i;

	_itoa(pid, pid_str, 10);
	_itoa(exit_status, exit_str, 10);

	if (!_strcmp(command[1], "$?"))
		write(1, exit_str, _strlen(exit_str));
	if (!_strcmp(command[1], "$$"))
                write(1, pid_str, _strlen(pid_str));
	if (!_strcmp(command[1], "$PATH"))
	{
		path = get_path(env);
		_puts(path);
		free(path);
	}
	if ((!_strcmp(command[1], "$?")) || (!_strcmp(command[1], "$$"))
	    || (!_strcmp(command[1], "$PATH")))
		i = 2;

	else
		i = 1;

	for (; command[i] != NULL; i++)
	{
		if (i > 1)
			_puts(" ");
		_puts(command[i]);
	}
	_puts("\n");
}
