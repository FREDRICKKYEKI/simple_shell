#include "main.h"
/**
 * is_command - checks if command is executable
 * @command: command to check
 * 
 * Return: 0 or 1 (true or false)
*/
int is_command(char *command, char **envp)
{
	char *dirs = getenvp("PATH", envp);
	char *pathname = getexecpath(command, dirs);
	
	if (pathname != NULL || is_other_command(command))
		return (1);
	else
		return (0);
}

/**
 * is_other_command - checks commands in a list of arrays
 * @command: command to check
 * 
 * Return: 0 or 1 (true or false)
*/
int is_other_command(char *command)
{
	int i = 0;
	const char *command_arr[] = {"cd", "setenv", "unsetenv", "alias", NULL};

	while (command != NULL && command_arr[i])
	{
		if (strcmp(command_arr[i], command) == 0)
			return (1);
		else
			return (0);
		i++;
	}
}

