#include "main.h"
/**
 * handle_exit - exit child process
 * @args: tokenized user input;
 * 
 * Return: exit status
*/
int get_exit_status(char **args)
{
	_puts("Goodbye! \n");
	if (args[1] == NULL)
		return (0);
	else
		return (_atoi(args[1]));
}
