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
char *get_path(char *command);
char *_strdup(const char *original);
char *_strcpy(char *copy, const char *original);
char *_strcat(char *base, const char *add);
size_t _strlen(const char *str);
int _strcmp(const char *s1, const char *s2);
char *_getenv(const char *name);
int _strncmp(const char *s1, const char *s2, size_t n);

#endif
