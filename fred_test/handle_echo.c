#include "main.h"
/**
 * handle_echo - handles special echo variable replacements ($$ and $?)
 * @args: tokenized input
 * 
 * Return: void
*/
void handle_echo(char **args, char **envp)
{
	pid_t pid;
	int status;
	char *varg = args[1];
	char pid_str[32], exit_status_str[32];
	char  *env_var = (varg + 1), *env_path = getenvp(env_var, envp);

	if (strcmp(args[0], "echo") != 0 && (varg[0] == '$') != 0)
		return;

	pid = getpid();

	if (env_path != NULL)
		strcpy(args[1], env_path);

	if (strcmp(args[1], "$$") == 0)
	{	
		itoa(pid, pid_str, 10);
		strcpy(args[1], pid_str);
	}
	else if (strcmp(args[1], "$?") == 0)
	{
		itoa(WEXITSTATUS(status), exit_status_str, 10);
		strcpy(args[1], exit_status_str);
	}

}
