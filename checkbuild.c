#include "shell.h"

/**
  * checkbuild - is the command buildin?
  * @arv: array of arguments passed on the command line
  * Return: 0
  */

void(*checkbuild(char **arv))(char **arv)
{
	int i;
	int j;

	mybuild Terminal[] = {
		{"exit", exitt},
		{"env", envn},
		{"setenv", setenvn},
		{"unsetenv", unsetenvn},
		{NULL, NULL}
	};

	for (i = 0; Terminal[i].name; i++)
	{
		j = 0;
		if (Terminal[i].name[j] == arv[0][j])
		{
			for (j = 0; arv[0][j]; j++)
			{
				if (Terminal[i].name[j] != arv[0][j])
					break;
			}
			if (!arv[0][j])
				return (Terminal[i].func);
		}
	}
	return (0);
}
