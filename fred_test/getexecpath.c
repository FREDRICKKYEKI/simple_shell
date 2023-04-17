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

	if (name[0] == '/')
		return name;

	dir = strtok(dirs_cpy, ":");
	while (dir != NULL)
	{
		path = malloc(strlen(dir) + strlen(name) + 2);
		sprintf(path, "%s/%s", dir, name);

		if (access(path, X_OK) == 0)
		{
			sprintf(path, "%s/%s", bin, name);
			return path;
		}
			
		free(path);
		dir = strtok(NULL, ":");
	}

	free(dirs_cpy);
	return NULL;
}
