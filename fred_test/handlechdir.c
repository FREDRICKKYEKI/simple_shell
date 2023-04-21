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
	

	getcwd(cwd, sizeof(cwd));
	char *env_toks[10] = {"setenv", "OLDPWD", cwd};

	handle_setenv(env_toks);
	

	if (input_toks[1] != NULL && path != NULL)
	{	
		if (strcmp(input_toks[1], "-") == 0)
		{
			if (oldpath != NULL)
			{
				result = chdir(oldpath);
				changedir(oldpath, result);
			}
		}
		else 
		{
			result = chdir(path);
			changedir(path, result);
		}
	}
	else
	{
		path = getenvp("HOME",envp);
		result = chdir(path);
		changedir(path, result);
	}
}

/**
 * changedir - changes working directory
 * @path: the path to change to.
 * @cd_result: result of changing directory
 * Return: void
*/
void changedir(char *path, int cd_result)
{
	char cwd[1024];

	getcwd(cwd, sizeof(cwd));

	char *set_env_toks[20] = {"setenv","PWD", cwd};

	if (cd_result == 0)
		printf("%s\n", cwd);
	else
		perror("Error");

	if (cd_result != 0)
		chdir(cwd);

	handle_setenv(set_env_toks);

}