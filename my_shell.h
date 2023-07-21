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
#define BUFFER_SIZE 1024
void handle_arguments(char *line);
int _strcmp(char *s1, char *s2);
ssize_t my_getline(char **buffer, size_t *n, FILE *stream);
ssize_t read_from_buffer(char **buffer, size_t *n, FILE *stream);
void initialize_buffer(char **buffer, size_t *n);
int handle_fork_process(char *command);
#endif
