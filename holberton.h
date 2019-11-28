#ifndef HOLBERTON_H
#define HOLBERTON_H
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
extern char **environ;
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_getenv(char *name);
void ctrlc_handle(int sig);
#endif
