#include "main.h"
/**
 * handle_comments - handles comments in commands
 * @command: full command
 * 
 * Return: void
*/
char *handle_comments(char *command)
{
	char *hash_ptr = strchr(command, '#');
    if (hash_ptr != NULL)
	{
        *hash_ptr = '\0';
		return command;
	} 
	else
		return command;
}
