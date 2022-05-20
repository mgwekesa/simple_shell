#include "shell.h"

/**
  * sg_handler - checks if Ctrl C is pressed
  * @sg_n: and integer parameter
  */
void sg_handler(int sg_n)
{
	if (sg_n == SIGINT)
	{
		_puts("\n#cisfun$ ");
	}
}

/**
  * _EOF - handles the End of File
  * @len: the number of characters returned by getline function
  * @buff: the buffer
  */

void _EOF(int len, char *buff)
{
	(void)buff;

	if (len == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			_putchar('\n');
			free(buff);
		}
		exitt(0);
	}
}

/**
  * _isatty - verify if the input is in the terminal
  */

void _isatty(void)
{
	if (isatty(STDIN_FILENO))
		_puts("#cisfun$ ");
}

/**
  * main - main function
  * Return: 0
  */

int main(void)
{
	ssize_t len = 0;
	char *buff = NULL, *val,  *pathname, **arv;
	size_t size = 0;
	list_path *head = '\0';
	void (*f)(char **);

	signal(SIGINT, sg_handler);
	while (len != EOF)
	{
		_isatty();
		len = getline(&buff, &size, stdin);
		_EOF(len, buff);
		arv = splitstr(buff, " \n");
		if (!arv || !arv[0])
			execute(arv);
		else
		{
			val = getenvn("PATH");
			head = linkpath(val);
			pathname = filepath(arv[0], head);
			f = checkbuild(arv);
			if (f)
			{
				free(buff);
				f(arv);
			}
			else if (!pathname)
				execute(arv);
			else if (pathname)
			{
				free(arv[0]);
				arv[0] = pathname;
				execute(arv);
			}
		}
	}
	free_list(head);
	freearv(arv);
	free(buff);
	return (0);
}
