#ifndef MAIN_H
#define MAIN_H

#define EXITCMD "exit"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stddef.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <dirent.h>


void execu(char **argv, char **env);
char *get_path(char *command, char **env);
char *_strdup(const char *original);
char *_strcpy(char *copy, const char *original);
char *_strcat(char *base, const char *add);
size_t _strlen(const char *str);
int _strcmp(const char *s1, const char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_getenv(const char *name, char **envp);
void tokenizer(char *line, char ***token_arr, int *token_count);
void free_argv(char **argv, int argc);
char **tokenize(char *str);
#endif
