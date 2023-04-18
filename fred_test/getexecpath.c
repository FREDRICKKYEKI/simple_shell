#include "main.h"

/**
 * getexecpath - checks for executable/command in files or directories
 * @name: symbolic link
 * return: path
*/
char *getexecpath(char *name, char *dirs)
{
	char *path;
	char *dirs_cpy = strdup(dirs);
	char *dir, *bin = "/bin";
	char *slash = "/";
	char *tmp = malloc(strlen(bin) + strlen(slash) + strlen(name) + 1);

	if (name[0] == '/')
		return name;

	dir = strtok(dirs_cpy, ":");
	while (dir != NULL)
	{
		path = malloc(strlen(dir) + strlen(name) + 2);
		strcpy(path, dir);
		strcat(path, slash);
		strcat(path, name);

		if (access(path, X_OK) == 0)
		{
			strcpy(tmp, bin);
			strcat(tmp, slash);
			strcat(tmp, name);
			strcpy(path, tmp);
			free(tmp);
			return path;
		}

		free(path);
		dir = strtok(NULL, ":");
	}

	free(dirs_cpy);
	return NULL;
}
