#include "main.h"

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

unsigned int check_delim(char c, const char *delim)
{
	while (*delim != '\0')
	{
		if (c == *delim)
			return (1);
		delim++;
	}
	return (0);
}

char *_strtok(char *src, const char *delim)
{
	static char *next_search;
	char *value;

	if (!src)
		src = next_search;
	if (!src)
		return (NULL);
	while (1) /* handle begining of the string */
	{
		if (check_delim(*src, delim))
		{
			src++;
			continue;
		}
		if (*src == '\0') /* end of string */
			return (NULL);
		break;
	}

	value = src;
	while (1)
	{
		if (*src == '\0')
		{
			next_search = src; /* next exec will return NULL */
			return (value);
		}
		if (check_delim(*src, delim))
		{
			src = '\0';
			next_search = src + 1;
			return (value);
		}
		src++;
	}
}
