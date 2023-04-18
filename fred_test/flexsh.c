#include "main.h"

#define BUFFER_SIZE 1024


int main(int argc, char *argv[], char **envp)
{
	char *input = NULL;
	size_t len = 0;

    while (1)
	{
        printf("#flexsh$ ");
        fflush(stdout);

        if (getline(&input, &len, stdin) == -1)
		{
			perror(argv[0]);
			exit(EXIT_FAILURE);
        }

		exec_command(input, argv, envp);
    }

		return (0);
}

