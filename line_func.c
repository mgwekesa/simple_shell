#include "shell.h"

/**
  * splitstr - splits a string into an array of pointers
  * @str: string to be split
  * @delim: the delimiter determining the split
  * Return: array of pointers to words from string
  */

char **splitstr(char *str, const char *delim)
{
	int i;
	int n;
	char **arr;
	char *tkn;
	char *cpy;

	cpy = malloc(_strlen(str) + 1);
	if (cpy == NULL)
	{
		perror(getenvn("_"));
		return ('\0');
	}
	i = 0;
	while (str[i])
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = '\0';

	tkn = strtok(cpy, delim);
	arr = malloc((sizeof(char *) * 2));
	arr[0] = _strdup(tkn);

	i = 1;
	n = 3;
	while (tkn)
	{
		tkn = strtok(NULL, delim);
		arr = _realloc(arr, (sizeof(char *) * (n - 1)), (sizeof(char *) * n));
		arr[i] = _strdup(tkn);
		i++;
		n++;
	}
	free(cpy);
	return (arr);
}

/**
  * execute - executes the command given
  * @arv: array of arguments passed on the command line
  */

void execute(char **arv)
{
	int frk;
	int status;

	if (!arv || !arv[0])
		return;

	frk = fork();

	if (frk == -1)
		perror(getenvn("-"));

	if (frk == 0)
	{
		execve(arv[0], arv, environ);
			perror(arv[0]);

		exit(EXIT_FAILURE);
	}
	wait(&status);
}

/**
  * _realloc - reallocates memory
  * @ptr: points to a previous value
  * @o_size: old size of ptr
  * @n_size: new size of ptr
  * Return: new resized ptr
  */

void *_realloc(void *ptr, unsigned int o_size, unsigned int n_size)
{
	char *n;
	char *o;
	unsigned int i;

	if (ptr == NULL)
		return (malloc(n_size));
	if (n_size == o_size)
		return (ptr);
	if (n_size == 0 && ptr != NULL)
	{
		free(ptr);
		return ('\0');
	}
	n = malloc(n_size);
	o = ptr;

	if (n == NULL)
		return ('\0');
	if (n_size > o_size)
	{
		for (i = 0; i < o_size; i++)
			n[i] = o[i];
		free(ptr);

		for (i = o_size; i < n_size; i++)
			n[i] = '\0';
	}
	if (n_size < o_size)
	{
		for (i = 0; i < n_size; i++)
			n[i] = o[i];
		free(ptr);
	}
	return (n);
}

/**
  * freearv - frees the array of pointers arv
  * @arv: array of arguments passed on the command line
  */

void freearv(char **arv)
{
	int i;
	
	i = 0;
	while (arv[i])
	{
		free(arv[i]);
		i++;
	}
	free(arv);
}
