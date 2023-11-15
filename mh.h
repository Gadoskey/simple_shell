#ifndef MH_H
#define MH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_ARGUMENTS 10

extern char **environ;
void mh_free_tokens(char **array);
/*print functions*/

void mh_prompt(void);
void mh_print(const char *text);
void mh_print2(char *text);

/* print environment variables*/
char *mh_getenv(char *input);
char *mh_findpath(char *input);

/*strings*/
char *mh_strdup(const char *string);
int mh_strlen(char *s);
int mh_strcmp(char *s1, char *s2);
char *mh_strcpy(char *dest, char *src);
char *mh_strcat(char *dest, char *src);

/*read and execute input*/
char *read_user_input(void);
char **mh_tokenize_user_input(char *input);
int mh_execute_command(char **command, char **argv, int index);

/* print error*/
void mh_print_error(char *input, char *command, int index);
char *mh_itoa(int num);
int mh_atoi(char *string);
void mh_reverse_string(char *string, int length);

/* handle builtins*/
void mh_exit(char **input, char **argv, int *status, int index);
void mh_print_env(char **input, int *status);
void mh_handle_builtin(char **input, char **argv, int *status, int index);
int mh_builtin(char *input);
int mh_is_positive(char *string);
void mh_handle_cd(char *command);

#endif
