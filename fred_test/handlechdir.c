#include "main.h"

/**
 * handlechdir - handle change directory
 * @input_toks: tokenized user input
 * 
 * Return: void
*/

void handlechdir(char **input_toks, char **envp)
{
	char cwd[1024];
	char *path = input_toks[1];

	if (input_toks[1] != NULL && path != NULL)
	{
		path = getenvp("HOME", envp);
	
		getcwd(cwd, sizeof(cwd));

		int result = chdir(path);

		if (result == 0)
			printf("%s\n", path);
		else
			perror("Error");

		if (result != 0)
			chdir(cwd);
	}
		// printf("%s\n", cwd);
}
	// Get the current working directory
	// Change the current working directory
	// If an error occurred, go back to the original directory
