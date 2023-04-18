#include "main.h"

#define BUFFER_SIZE 1024


int main(int argc, char *argv[], char **envp)
{
	char *input = NULL;
	size_t len = 0;

	(void)argc;

    while (1) 
	{
        printf("#flexsh$ ");
        fflush(stdout);

        if (getline(&input, &len, stdin) == -1)
		{
			perror("flexsh");
			exit(EXIT_FAILURE);
        }
		
		exec_command(input, argv, envp);
    }

    return (0);
}

