#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <sys/wait.h>
void handle_arguments(char *line);
int _strcmp(char *s1, char *s2);
ssize_t my_getline(char **buffer, size_t *n, FILE *stream);
#endif
