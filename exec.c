#include "main.h"

/**
 * execute - executes a given command
 * @command: array of commands from the command line
 * @av: list containing name of the program
 * @env: array of environment variables
 * @input: input from the user
 * @path_ret: return value of the get path function
 * @process_num: the process number
 *
 * Return: returns 0 on success or exit status on error
 */
int execute(char **command, char **av, char **env, char *input, int path_ret,
	    int process_num)
{
	pid_t child_process;
	int status, exit_status;

	child_process = fork();

	if (child_process == 0)
	{
		if (execve(command[0], command, env) == -1)
		{
			print_err(av[0], process_num, command[0]);
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

/**
 * print_err - prints an error message
 * @name: name of the program
 * @process_num: the process id of the process
 * @command: the command that was not found
 */
void print_err(char *name, int process_num, char *command)
{
	char proc[32];

	_itoa(process_num, proc, 10);

	_puts(name);
	_puts(": ");
	_puts(proc);
	_puts(": ");
	_puts(command);
	_puts(": not found\n");
}
