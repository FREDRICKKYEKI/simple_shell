#include "main.h"

/**
 * change_dir - changes current working directory
 * @command: array of command line arguments
 * @av: name of the program
 */
void change_dir(char **command, char *av)
{
	int value = -1;
	char cwd[PATH_MAX];

	if (command[1] == NULL)
		value = chdir(getenv("HOME"));
	else if (_strcmp(command[1], "-") == 0)
		value = chdir(getenv("OLDPWD"));
	else
		value = chdir(command[1]);

	if (value == -1)
	{
		perror(av);
		return;
	}
	else if (value != -1)
	{
		getcwd(cwd, sizeof(cwd));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", cwd, 1);
	}
}
