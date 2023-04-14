#include "main.h"
#include <string.h>

int child_exec(char *str, char *argv[])
{
        pid_t child;
        int status;

        child = fork();

        if (child == 0)
	{
                if (execve(argv[0], argv, NULL) == -1)
		{
			perror(str);
			return (1);
		}
        }
        else
                wait(&status);
	return (0);
}

int main(int __attribute__((unused)) ac, char *av[])
{
        char *line;
        char *argv[3];
	size_t max = 1024;
	char *temp;
	int count = 0;

	(void)av;
        argv[1] = NULL;
        while (1)
        {
                _puts("$ ");
                if (getline(&line, &max, stdin))
                {
	                while (line[count] != '\n')
                                count++;
                        temp = malloc(count + 1);
			if (!temp)
			{
				_puts("Error: memory allocation failed\n");
				return (1);
			}
			count = 0;
			while (line[count] != '\n')
			{
                         	temp[count] = line[count];
				count++;
			}
                        temp[count] = '\0';
			if (_strcmp(temp, "exit") == 0)
				break;
			argv[0] = temp;

			if (child_exec(av[0], argv) == 1)
			{
				exit(98);
			}
			free(temp);
		}
                else
		{
                 	perror("Error");
			exit(98);
		}
        }
	return (0);
}
