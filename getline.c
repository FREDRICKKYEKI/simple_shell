#include "main.h"

/**
 * _getline - gets input from user
 *
 * Return: returns the line read, NULL if it fails
 */
char *_getline(void)
{
	char *line = NULL;
	size_t line_size = 0;

	if (isatty(STDIN_FILENO)) /* checks fileds if pointing to terminal */
		write(STDOUT_FILENO, "$ ", 2);
	/* read input from terminal and store in line variable*/
	if (getline(&line, &line_size, stdin) == -1)
	{
		free(line);
		return (NULL);
	}

	/* return the line read */
	return (line);
}
