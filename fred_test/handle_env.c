#include "main.h"
/**
 * handle_env - sets/unsets environment variables
 * @input_tok: tokenized user input
 * 
 * Return: void
*/
void handle_env(char **input_toks)
{
	if (_strcmp(input_toks[0], "setenv") == 0)
		handle_setenv(input_toks);
	else
		handle_unsetenv(input_toks);
}


/**
 * handle_setenv - sets environment variables
 * @input_tok: tokenized user input
 * 
 * Return: void
*/
void handle_setenv(char **input_toks)
{
    int overwrite = 1, ret;
	if (input_toks[1] == NULL)
	{
        printf("setenv: Too few arguments\n");
        return;
    }
    if (input_toks[3] != NULL)
	{
        printf("setenv: Too many arguments\n");
        return;
    }
	
    ret = setenv(input_toks[1], input_toks[2], overwrite);

    if (ret != 0)
		perror("setenv");

}


/**
 * handle_unsetenv - unsets environment variables
 * @input_tok: tokenized user input
 * 
 * Return: void
*/
void handle_unsetenv(char **input_toks)
{	
	int ret;
	if (input_toks[1] == NULL)
	{
		printf("unsetenv: Too few arguments\n");
		return;
	}
	if (input_toks[2] != NULL)
	{
		printf("unsetenv: Too many arguments\n");
		return;
	}

	ret = unsetenv(input_toks[1]);

	if (ret != 0) {
		perror("unsetenv");
	}
}
