#include "main.h"

#define BUFFER_SIZE 1024


int main(int argc, char *argv[], char **envp)
{
	char *input = NULL;
	size_t len = 0;
	int exit_status;

    while (1) 
	{
        printf("#flexsh$ ");
        fflush(stdout);

        if (getline(&input, &len, stdin) == -1)
		{
			perror("flexsh");
			exit(EXIT_FAILURE);
        }
		
		exit_status = exec_command(input, argv, envp);
    }

		return (exit_status);
}

