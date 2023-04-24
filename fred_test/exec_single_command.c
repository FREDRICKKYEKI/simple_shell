#include "main.h"
/**
 * exec_single_command - executes a single linux command
 * @args: array of command-line arguments
 * @envp: array of environment variables
 * 
 * Return: void
 */
void exec_single_command(char *args[], char **argv,char **envp, int *exit_status)
{
	char *dirs = getenvp("PATH", envp);
	char *pathname = getexecpath(args[0], dirs);
	pid_t pid;
	int status;
    char print_message[50], colon[] = ":", message[] = " command not found";

	if (pathname != NULL && _strcmp(pathname, "/bin/echo") == 0)
		handle_echo(args, envp);

	pid = fork();

	if (pid == -1)
	{
		perror("fork error");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (pathname != NULL)
		{	
			if (execve(pathname, args, envp) == -1)
			{
				perror(argv[0]);
				exit(EXIT_FAILURE);
			}
		}
		else if (handleothercommands(args, envp) != 0)
		{
			_strcpy(print_message, argv[0]);
			_strcat(print_message, colon);
			_strcat(print_message, args[0]);
			_strcat(print_message, message);
			_strcat(print_message, "\n");
			_puts(print_message);
		}
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
			*exit_status = WEXITSTATUS(status);
	}

}
