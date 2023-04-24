#include "main.h"
/**
 * handleothercommands - executes commands not accessible using access()
 * @input: tokenized user input
 * Return: void 
*/
int handleothercommands(char **input_toks, char **envp)
{
	if (_strcmp(input_toks[0],"cd") == 0)
	{
		handlechdir(input_toks, envp);
		return (0);
	}
	else if (_strcmp(input_toks[0],"setenv") == 0 || _strcmp(input_toks[0],"unsetenv ") == 0)
	{
		handle_env(input_toks);
		return (0);
	}
	else
		return (1);
}
