#include "main.h"
/**
 * handle_exit - exit child process
 * @args: tokenized user input;
 * 
 * Return: exit status
*/

int get_exit_status(char **args)
{
	printf("Goodbye!\n");
	if (args[1] == NULL)
		return (0);
	else
	{
		printf("%d\n", _atoi(args[1]));
		return (_atoi(args[1]));
	}
}
