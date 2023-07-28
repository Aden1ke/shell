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
#include <errno.h>

#define END_OF_FILE -2
extern char *current_working_directory;

typedef struct list_s
{
	char *dir;
	struct list_s *next;
} list_t;
extern char **environ;
char *name;
int incr;
extern bool should_exit;

int handle_arguments(char *line);
int handle_non_interactive_mode(void);
int handle_interactive_mode(void);
bool is_number(const char *str);
int _strcmp(char *s1, char *s2);
ssize_t my_getline(char **buffer, size_t *n, FILE *stream);
ssize_t read_from_buffer(char **buffer, size_t *n, FILE *stream);
void initialize_buffer(char **buffer, size_t *n);
int handle_fork_process(char *command);
void free_list(list_t *head);
list_t *node_end(list_t **head, char *dir);
int _strlen(const char *str);
char *_strcat(char *dest, const char *str);
char *_strncat(char *dest, const char *str, size_t n);
int _strncmp(const char *str1, const char *str2, size_t n);
char *_strcpy(char *dest, const char *str);
char **get_env(const char *var);
char *fill_path(char *path);
list_t *get_path(char *path);
char *locate_path(char *com);
int execve_helper(char *command, char *args[]);
int token_len(char *str, char *delim);
int count_token(char *str, char *delim);
char **_strtok(char *str, char *delim);
void *_calloc(unsigned int nmemb, unsigned int size);
void handle_CD(char *command);
void update_pwd();
void free_buffer(char **buffer);
void free_array(char **array);
int _atoi(char *s);
int handle_piped_input(char *buf, size_t size);
int len_num(int num);
char *_itoa(int num);
char *error_126(char **args);
char *error_127(char **args);
int handle_error(char **args, int err);

#endif
