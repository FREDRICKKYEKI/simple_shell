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

	token = _strtok(input, " \n\t\r");
	for (count = 0; token != NULL; count++)
	{
		command[count] = token;
		token = _strtok(NULL, " \n\t\r");
	}
	command[count] = NULL;
	return (command);
}

unsigned int check_delim(char c, const char *str)
{
	unsigned int count;

	for (count = 0; str[count] != '\0'; count++)
	{
		if (c == str[count])
			return (1);
	}
	return (0);
}

char *_strtok(char *str, const char *delim)
{
	static char *token, *new_token;
	unsigned int i;

	if (str != NULL)
		new_token = str;
	token = new_token;
	if (token == NULL)
		return (NULL);
	for (i = 0; token[i] != '\0'; i++)
	{
		if (check_delim(token[i], delim) == 0)
			break;
	}
	if (new_token[i] == '\0' || new_token[i] == '#')
	{
		new_token = NULL;
		return (NULL);
	}
	token = new_token + i;
	new_token = token;
	for (i = 0; new_token[i] != '\0'; i++)
	{
		if (check_delim(new_token[i], delim) == 1)
			break;
	}
	if (new_token[i] == '\0')
		new_token = NULL;
	else
	{
		new_token[i] = '\0';
		new_token = new_token + i + 1;
		if (*new_token == '\0')
			new_token = NULL;
	}
	return (token);
}
