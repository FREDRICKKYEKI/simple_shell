#include "main.h"
#include <string.h>

char **get_token(char *input)
{
	char *token = NULL, **command = NULL;
	size_t count;
	int num_elements = 0;

	if (!input)
		return (NULL);

	/* get number of elements */
	for (count = 0; input[count]; count++)
	{
		if (input[count] == ' ')
			num_elements++;
	}
	/* if it is only made up of a new line character */
	if ((num_elements + 1) == _strlen(input))
		return (NULL);
	num_elements += 2; /* spaces is always 1 less than words */
	command = malloc(sizeof(char *) * (num_elements));
	if (!command)
		return (NULL);

	token = strtok(input, " \n\t\r");
	for (count = 0; token != NULL; count++)
	{
		command[count] = token;
		token = strtok(NULL, " \n\t\r");
	}
	command[count] = NULL;
	return (command);
}
