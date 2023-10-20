#ifndef MAIN_H
#define MAIN_H

/*--LIBRARIES--*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdarg.h>
#include <signal.h>

/*--Macros--*/
#define DELIM " \t\r\n\a\""
extern char **environ;
extern struct stat st;

/*--Global vars--*/
extern int commandCountNonInteractive;

/*--Functions PROTOTYPES--*/
void interactive_shell(char *argv_0);
void non_interactive_shell(char *argv_0);
char *readline(void);
char **split_string(char *string);
char *_getenv(char *path);
char *stat_file_in_path(char *args);
int execute_cmd(char *cmd, char **args);
char *read_stream(void);
int execute_builtIn_args(char **args);
int execute_builtIn_args_in_shell(int (*builtIn)(char **),
		char *line, char **args, char *argv_0);

/*--Helper Functions--*/
int _strlen(char *s);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
int _atoi(char *s);
int is_num(unsigned int n);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, const char *src);
int slash_count(char *args);
void print_error_non(char *argv_0, char *shell_arg, int count);
void print_error(char *argv_0, char *shell_arg);
int digits(int x);
char *int_to_str(int num);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);

/*--Freeing Memory function--*/
void free_memory_array(char **item);
void free_memory_all(int count, ...);

#endif
