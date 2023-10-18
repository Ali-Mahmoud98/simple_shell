#ifndef SHELL_H
#define SHELL_H
#define DELIM " \n\t"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>

extern char **environ;

char *read_line(void);
char **tokenizer(char *line);
char *_strdup(char *str);
int _execute(char **command, char **argv, int idx);
void free2DArray(char **array2d);
char *_getenv(char *var);
char *_getpath(char *command);
void reverse_string(char *str, int len);
void printerror(char *name, char *cmd, int idx);
char *_itoa(int num);

void wait_print(int *status, char *prompt);
void execute(ssize_t input_count, char **av, char *command);

#endif
