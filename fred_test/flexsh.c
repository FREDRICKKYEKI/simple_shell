#include "main.h"

#define BUFFER_SIZE 1024


int main(int argc, char *argv[], char **envp)
{
	char *input = NULL;
	size_t len = 0;

<<<<<<< HEAD
    while (1)
=======
	(void)argc;

    while (1) 
>>>>>>> 5ebf70d8f0a4d129c15b7985d83d86a2401c2696
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

