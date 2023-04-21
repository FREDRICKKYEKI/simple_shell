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

char *_strtok(char *str, const char *delim)
{
	static int pos;
	static char *token;
	char *string = NULL;
	int check_delim = 0, size = 0, i, j;

	if (str) /* first time calling _strtok */
	{
		token = str;
		pos = 0;
	}
	if (!token || !delim)
		return (NULL);
	if (pos >= _strlen(token))
		return (NULL);
	for (i = pos; token[i]; i++) /* find delimiter */
	{
		for (j = 0; delim[j]; j++)
		{
			if (token[i] == delim[j])
			{
				check_delim = 1;
				break;
			}
		}
		if (check_delim == 1)
			break;
		size++;
	}
	string = malloc(sizeof(char) * (size + 1));
	if (!string)
		return (NULL);
	for (i = 0; i < size; i++) /* fill string with new token */
		string[i] = token[pos + i];
	string[i] = '\0';
	pos += size + 1;

	return (string);

}
