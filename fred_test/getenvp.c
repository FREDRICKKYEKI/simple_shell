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
		if (_strncmp(var_name, envp[i], _strlen(var_name)) == 0 && envp[i][_strlen(var_name)] == '=')
		{
			var_value = &envp[i][_strlen(var_name)+1];
			break;
		}
	}
	return var_value;
}

/**
 * getenvp_index - returns environment path
 * @var_name: variable name to be searched in envp
 * @envp: pointer to environment variables
 * Return:  environment paths
*/
int getenvp_index(char *var_name, char **envp)
{
	int i;

	for (i = 0; envp[i] != NULL; i++)
	{
		if (_strncmp(var_name, envp[i], _strlen(var_name)) == 0 && envp[i][_strlen(var_name)] == '=')
		{
			break;
		}
	}
	return i;
}