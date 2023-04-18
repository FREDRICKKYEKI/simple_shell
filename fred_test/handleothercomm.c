#include "main.h"
/**
 * handleothercommands - executes commands not accessible using access()
 * @input: tokenized user input
 * Return: void 
*/
void handleothercommands(char **input_toks, char **envp)
{
	if (strcmp(input_toks[0],"cd") == 0)
		handlechdir(input_toks, envp);
}
