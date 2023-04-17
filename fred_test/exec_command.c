#include "main.h"

/**
 * exec_command - executes linux commands
 * @input: string input
 * @argv: argument vector
 * 
 * Return: void
*/
void exec_command(char *input, char *argv[], char **envp)
{
	char *d = " ";
	char *token;
	int status; 
	int i = 0;
	int len = strlen(input);
	char *dirs = getenvp("PATH", envp);
	pid_t pid;
	char *args[1024];
	char *pathname;

	if (input[len - 1] == '\n')
		input[len - 1] = '\0';
	
	if (input[0] == '\n')
		return;

	token = strtok(input, d);
	
	while (token != NULL)
	{
	    args[i] = token;
		token = strtok(NULL, d);
		i++;
	}

	args[i] = NULL;
	pathname = getexecpath(args[0], dirs);


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
		else
		{
			// printf("cd pressed!!!\n");
			handleothercommands(args, envp);
		}
	}
	else
	{
		wait(&status);
	}

}

// if (pathname)
// 	printf("%s\n", pathname);
// else
// 	printf("args[0] NULL!\n");