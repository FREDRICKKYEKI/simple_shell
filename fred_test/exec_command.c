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
	char *d = "||;";
	char *token;
	int i = 0;
	int len = _strlen(input);
	char *args[1024];
	int j;

	if (input[0] == '\n')
		return;

	if (input[len - 1] == '\n')
		input[len - 1] = '\0';

	token = strtok(input, d);
	while (token != NULL)
	{
		if (_strchr(token, ';') != NULL)
		{
			char *subtoken;
			subtoken = strtok(token, ";");
			while (subtoken != NULL)
			{
				args[i] = subtoken;
				subtoken = strtok(NULL, ";");
				i++;
			}
		}
		else
		{
			args[i] = token;
			i++;
		}
		token = strtok(NULL, d);
	}

	for (j = 0; j < i; j++)
	{
		char *command = handle_comments(args[j]);
		char *arglist[1024];
		int k = 0;
		char *arg = strtok(command, " ");

		while (arg != NULL)
		{
			arglist[k++] = arg;
			arg = strtok(NULL, " ");
		}
		arglist[k] = NULL;
		if (_strcmp(arglist[0], "exit") == 0)
		{
			exit(get_exit_status(arglist));
			break;
		}

		exec_single_command(arglist, argv, envp);
	}
}
