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
		handle_echo(command[1], exit_status);
		return (1);
	}
	return (0);
}

void handle_echo(char *command, int exit_status)
{

	pid_t pid = getpid();
	char pid_str[32], exit_str[32];

	_itoa(pid, pid_str, 10);
	_strcat(pid_str, "\n");
	_itoa(exit_status, exit_str, 10);
	_strcat(exit_str, "\n");

	if (!_strcmp(command, "$?"))
		write(1, exit_str, _strlen(exit_str));
	if (!_strcmp(command, "$$"))
                write(1, pid_str, _strlen(pid_str));
}
