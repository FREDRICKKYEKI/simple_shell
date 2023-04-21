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

	// char* hash_ptr = strchr(command, '#'); // Find the first occurrence of '#' character
	// if (hash_ptr != NULL) { // If found, terminate the string at '#' and return the string before it
	// 	*hash_ptr = '\0';
	// 	return str;
	// } else { // If '#' character not found, return the whole string
	// 	return str;
	// }