#include "main.h"
/**
 * handle_env - sets/unsets environment variables
 * @input_tok: tokenized user input
 * 
 * Return: void
*/
void handle_env(char **input_toks, char **envp)
{
	if (_strcmp(input_toks[0], "setenv") == 0)
		handle_setenv(input_toks, envp);
	else
		handle_unsetenv(input_toks, envp);
}


/**
 * handle_setenv - sets environment variables
 * @input_tok: tokenized user input
 * 
 * Return: void
*/
void handle_setenv(char **input_toks, char **envp)
{
	int overwrite = 1, ret;
	if (input_toks[1] == NULL)
	{
		_puts("setenv: Too few arguments \n");
		return;
	}
	if (input_toks[3] != NULL)
	{
		_puts("setenv: Too many arguments \n");
		return;
	}

	ret = _setenv(input_toks[1], input_toks[2], overwrite, envp);

	if (ret != 0)
		perror("setenv");

}


/**
 * handle_unsetenv - unsets environment variables
 * @input_tok: tokenized user input
 * 
 * Return: void
*/
void handle_unsetenv(char **input_toks, char **envp)
{	
	int ret;
	if (input_toks[1] == NULL)
	{
		_puts("unsetenv: Too few arguments \n");
		return;
	}
	if (input_toks[2] != NULL)
	{
		_puts("unsetenv: Too many arguments \n");
		return;
	}

	ret = _unsetenv(input_toks[1], envp);

	if (ret != 0) {
		perror("unsetenv");
	}
}
/**
 * _setenv - sets environment variable to given value
 * @name: name of variable
 * @value: value to be changed to
 * @envp: environment variables
 * Return: void
*/
int _setenv(char *name, char *value, int overwrite, char **envp)
{
	char *key = name, *new_val = value;
	int var_index = getenvp_index(name, envp), arr_size = 0;
	char *key_value = malloc(strlen(key) + strlen(new_val) + 2);
	
	/*find length of environment path array*/
	while (envp[arr_size])
		arr_size++;
	

	/*create new environment variable*/
	_strcpy(key_value, key);
	_strcat(key_value, "=");
	_strcat(key_value, new_val);

	if (overwrite == 0)
	{
		/*allocate space for new array*/
		char **new_envp = realloc(envp, (arr_size + 2) * sizeof(char*));

		if (new_envp == NULL)
		{
			perror("realloc");
			return (-1);
		}

		new_envp[arr_size] = key_value;
		return (0);
	}
	else if (overwrite == 1)
	{
		envp[var_index] = key_value;
		return (0);
	}
	return (-1);
}

/**
 * _unsetenv - sets environment variable to given value
 * @name: name of variable
 * @envp: environment variables
 * 
 * Return: void
*/
int _unsetenv(char *name, char **envp)
{
	int var_index = getenvp_index(name, envp);
	char *key_val = malloc(strlen(name) + 2);

	_strcpy(key_val, name);
	_strcat(key_val, "=");

	envp[var_index] = key_val;

	free(key_val);

	return (0);
}
