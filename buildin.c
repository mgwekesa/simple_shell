#include "shell.h"

/**
  * exitt - the exit function of the simple shell
  * @arv: array of arguments passed on the command line
  */

void exitt(char **arv)
{
	int i;
	int n;

	if (arv[1])
	{
		n = _atoi(arv[1]);
		if (n <= -1)
			n = 2;
		freearv(arv);
		exit(n);
	}
	
	i = 0;
	while (arv[i])
	{
		free(arv[i]);
		i++;
	}
	free(arv);
	exit(0);
}

/**
  * _atoi - converts a string which is a number to an integer
  * @str: pointer to the given string
  * Return: a converted integer
  */

int _atoi(char *str)
{
	int i;
	int intt;
	int sign;

	i = 0;
	intt = 0;
	sign = 1;

	while (!((str[i] >= '0') && (str[i] <= '9')) && (str[i] != '\0'))
	{
		if (str[i] == '-')
			sign = sign * (-1);
		i++;
	}

	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		intt = (intt * 10) + (sign * (str[i] - '0'));
		i++;
	}

	return (intt);
}

/**
  * envn - prints current environment
  * @arv: array of arguments passed on the command line
  */

void envn(char **arv __attribute__((unused)))
{
	int i;
	
	i = 0;
	while (environ[i])
	{
		_puts(environ[i]);
		_putchar('\n');
		i++;
	}
}

/**
  * setenvn - initialize new or modify an existing environment variable
  * @arv: array of arguments passed on the command line
  */

void setenvn(char **arv)
{
	int i;
	int j;
	int k;

	if (!arv[1] || !arv[2])
	{
		perror(getenvn("_"));
		return;
	}

	for (i = 0; environ[i]; i++)
	{
		j = 0;
		if (arv[1][j] == environ[i][j])
		{
			while (arv[1][j])
			{
				if (arv[1][j] != environ[i][j])
					break;
				j++;
			}
			if (arv[1][j] == '\0')
			{
				k = 0;
				while (arv[2][k])
				{
					environ[i][j + 1 + k] = arv[2][k];
					k++;
				}
				environ[i][j + 1 + k] = '\0';
				return;
			}
		}
	}
	if (!environ[i])
	{
		environ[i] = concat(arv[1], "=", arv[2]);
		environ[i + 1] = '\0';
	}
}

/**
  * unsetenvn - remove an environment variable from the environment
  * @arv: array of arguments passed on the command line
  */

void unsetenvn(char **arv)
{
	int i;
	int j;

	if (!arv[1])
	{
		perror(getenvn("_"));
		return;
	}

	for (i = 0; environ[i]; i++)
	{
		j = 0;
		if (arv[1][j] == environ[i][j])
		{
			while (arv[1][j])
			{
				if (arv[1][j] != environ[i][j])
					break;
				j++;
			}
			if (arv[1][j] == '\0')
			{
				free(environ[i]);
				environ[i] = environ[i + 1];
				while (environ[i])
				{
					environ[i] = environ[i + 1];
					i++;
				}
				return;
			}
		}
	}
}
