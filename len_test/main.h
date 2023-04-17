#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/stat.h>

/* function prototypes */
char *_getline(void);
void handle_exit(char **command, char *input, int _exit);
void handle_env(char **env);
char **get_token(char *input);
char *get_path(char **env);
int handle_path(char **command, char **env);

/* string functions */
int _strcmp(char *s1, char *s2);
char *_strtok(char *str, const char *delim);
int _strlen(char *str);
size_t _strncmp(char *s1, char *s2, size_t n);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);

/* print functions */
int _putchar(char c);
int _puts(char *str);

#endif
