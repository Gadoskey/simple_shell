#ifndef MH_H
#define MH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


extern char **environ;

void mh_free_tokens(char **array);

/*print functions*/
void mh_prompt(void);
void mh_print(const char *text);

/*strings*/
char *mh_strdup(const char *string);
int mh_strlen(char *s);
int mh_strcmp(char *s1, char *s2);
char *mh_strcpy(char *dest, char *src);

/*read and execute input*/
char *read_user_input(void);
char **mh_tokenize_user_input(char *input);
int mh_execute_command(char **command, char **argv);

#endif
