#include "main.h"
/**
 * handlechdir - handle change directory
 * @input_toks: tokenized user input
 * @envp: environment path
 * Return: void
*/

void handlechdir(char **input_toks, char **envp)
{
	char cwd[1024];
	char *path = input_toks[1], *oldpath;
	int result;
	oldpath = getenvp("OLDPWD", envp);
	char *env_toks[4];

	getcwd(cwd, sizeof(cwd));
	
	env_toks[0] = "setenv";
	env_toks[1] = "OLDPWD";
	env_toks[2] = cwd;
	env_toks[3] = NULL;

	handle_setenv(env_toks, envp);
	

	if (input_toks[1] != NULL && path != NULL)
	{
		if (_strcmp(input_toks[1], "-") == 0)
		{
			if (oldpath != NULL)
			{
				result = chdir(oldpath);
				changedir(oldpath, result, envp);
			}
		}
		else 
		{
			result = chdir(path);
			changedir(path, result, envp);
		}
	}
	else
	{
		path = getenvp("HOME",envp);
		result = chdir(path);
		changedir(path, result, envp);
	}
}

/**
 * changedir - changes working directory
 * @path: the path to change to.
 * @cd_result: result of changing directory
 * Return: void
*/
void changedir(char *path, int cd_result, char **envp)
{
	char cwd[1024];
	char *env_toks[20];
	getcwd(cwd, sizeof(cwd));

	env_toks[0] = "setenv";
	env_toks[1] = "PWD";
	env_toks[2] = cwd;
	env_toks[3] = NULL;

	if (cd_result == 0)
	{
		_strcat(cwd, "\n");
		_puts(cwd);
	}
	else
		perror("Error");

	if (cd_result != 0)
		chdir(cwd);

	handle_setenv(env_toks, envp);
}