#include "main.h"
#include <string.h>

int main(int __attribute__((unused)) ac, char **av, char **env)
{
	char *user_input = NULL, command = NULL;
	int exit_status = 0, path_ret = 0;
	int nth_process = 0;

	while (1)
	{
		user_input = _getline();
		if (!user_input) /* if getline fails */
		{
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			exit(exit_status);
		}
		else
		{
			nth_process++;
			command = get_token(user_input);
		}
	}
}
