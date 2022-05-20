#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>
#include <stddef.h>
#include <sys/stat.h>
#include <signal.h>

extern char **environ;

/**
  * struct list_path - linked-list with PATH directories
  * @dirp: path of the directory
  * @ptr: pointer to the next node
  */

typedef struct list_path
{
	char *dirp;
	struct list_path *ptr;
} list_path;

char *getenvn(const char *name);
list_path *add_node_end(list_path **head, char *str);
list_path *linkpath(char *path);
char *filepath(char *filename, list_path *head);

/**
  * struct mybuild - pointer to a function corresponding to buildin command
  * @name: name of the buildin command
  * @func: the buildin function
  */

typedef struct mybuild
{
	char *name;
	void (*func)(char **);
} mybuild;

void(*checkbuild(char **arv))(char **arv);
int _atoi(char *s);
void exitt(char **arv);
void envn(char **arv);
void setenvn(char **arv);
void unsetenvn(char **arv);
void freearv(char **arv);
void free_list(list_path *head);
int _putchar(char c);
void _puts(char *str);
int _strlen(char *str);
char *_strdup(char *str);
char *concat(char *first, char *sep, char *second);
char **splitstr(char *str, const char *delim);
void execute(char **argv);
void *_realloc(void *ptr, unsigned int o_size, unsigned int n_size);
#endif
