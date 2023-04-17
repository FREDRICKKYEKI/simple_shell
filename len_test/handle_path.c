#include "main.h"
#include <string.h>

char *get_path(char **env)
{
	size_t count, head, ele = 0; /* ele is element */
	char *path = NULL;

	for (head = 0; _strncmp(env[head], "PATH=", 5); head++)
		;
	if (!env[head])
		return (NULL);
	/* get space needed for allocation */
	for (count = 5; env[head][ele]; ele++, count++)
		;
	path = malloc(sizeof(char) * (count + 1));
	if (!path)
		return (NULL);

	/* store the path values in the allocated memory space */
	for (ele = 5, count = 0; env[head][ele]; ele++, count++)
		path[count] = env[head][ele];
	path[count] = '\0';

	return (path);
}

int handle_path(char **command, char **env)
{
	char *path_value = NULL, *new_path = NULL, *token = NULL;
	size_t path_len, command_len;
	struct stat check;

	if (stat(*command, &check) == 0) /* need to confirm stat return value */
		return (-1); /* command matches, no need to check from path */
	path_value = get_path(env);
	if (!path_value) /* failed to get path value */
		return (-1);
	token = strtok(path_value, ":");
	command_len = _strlen(*command);
	while (token)
	{
		path_len = _strlen(token);
		new_path = malloc(sizeof(char) * (path_len + command_len + 2));
		if(!new_path)
		{
			free(path_value);
			return (-1);
		}
		/* generate path value */
		new_path = _strcpy(new_path, token);
		_strcat(new_path, "/");
		_strcat(new_path, *command);
		/* check if path is valid */
		if (stat(new_path, &check) == 0)
		{
			*command = new_path;
			free(path_value);
			return (0);
		}
		/* prepare for next iteration */
		free(new_path);
		token = strtok(NULL, ":");
	}
	free(path_value);
	return (-1);
}
