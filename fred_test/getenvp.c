#include "main.h"

/**
 * getenvp - returns environment path
 * @var_name: variable name to be searched in envp
 * @envp: pointer to environment variables
 * Return:  environment paths
*/
char *getenvp(char *var_name, char **envp)
{
	char *var_value = NULL;
	int i;

	for (i = 0; envp[i] != NULL; i++)
	{
		if (strncmp(var_name, envp[i], strlen(var_name)) == 0 && envp[i][strlen(var_name)] == '=')
		{
			var_value = &envp[i][strlen(var_name)+1];
			break;
		}
	}
	return var_value;
}