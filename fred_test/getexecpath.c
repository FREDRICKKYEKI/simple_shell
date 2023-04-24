#include "main.h"

/**
 * getexecpath - checks for executable/command in files or directories
 * @name: symbolic link
 * return: path
*/
char *getexecpath(char *name, char *dirs)
{
	char *path;
	char *dirs_cpy = _strdup(dirs);
	char *dir, *bin = "/bin";
	char *slash = "/";
	char *tmp = malloc(_strlen(bin) + _strlen(slash) + _strlen(name) + 1);

	if (name[0] == '/')
		return name;

	dir = strtok(dirs_cpy, ":");
	while (dir != NULL)
	{
		path = malloc(_strlen(dir) + _strlen(name) + 2);
		_strcpy(path, dir);
		_strcat(path, slash);
		_strcat(path, name);

		if (access(path, X_OK) == 0)
		{
			_strcpy(tmp, bin);
			_strcat(tmp, slash);
			_strcat(tmp, name);
			_strcpy(path, tmp);
			free(tmp);
			return path;
		}

		free(path);
		dir = strtok(NULL, ":");
	}

	free(dirs_cpy);
	return NULL;
}
