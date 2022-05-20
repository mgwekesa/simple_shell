#include "shell.h"

/**
  * getenvn - gets the value of an environment variable
  * @name: name of the environment variable
  * Return: string of value
  */

char *getenvn(const char *name)
{
	int i;
	int j;
	char *val;

	if (!name)
		return ('\0');
	
	i = 0;
	while (environ[i])
	{
		j = 0;
		if (name[j] == environ[i][j])
		{
			while (name[j])
			{
				if (name[j] != environ[i][j])
					break;
				j++;
			}
			if (name[j] == '\0')
			{
				val = (environ[i] + j + 1);
				return (val);
			}
		}
		i++;
	}
	return (0);
}

/**
  * add_node_end - adds a new node at the end of a list_t list
  * @head: pointer to pointer to head of a linked list
  * @str: pointer to string in previous node
  * Return: address of the new node
  */
list_path *add_node_end(list_path **head, char *str)
{
	list_path *tmp;
	list_path *n_node;

	n_node = malloc(sizeof(list_path));

	if (!n_node || !str)
		return ('\0');
	n_node->dirp = str;
	n_node->ptr = '\0';

	if (!*head)
		*head = n_node;

	else
	{
		tmp = *head;
		while (tmp->ptr)
			tmp = tmp->ptr;
		tmp->ptr = n_node;
	}

	return (*head);
}

/**
  * linkpath - linked list for path directories
  * @path: dtring of path val
  * Return: pointer to created linked list
  */

list_path *linkpath(char *path)
{
	list_path *head = '\0';
	char *tkn;
	char *cpath = _strdup(path);

	tkn = strtok(cpath, ":");
	
	while (tkn)
	{
		head = add_node_end(&head, tkn);
		tkn = strtok(NULL, ":");
	}

	return (head);
}

/**
  * filepath - finds the pathname of a given filename
  * @filename: name of a file
  * @head: head of a linked list of path directories
  * Return: pathname of filename or NULL if not available
  */

char *filepath(char *filename, list_path *head)
{
	struct stat st;
	char *str;
	list_path *tmp = head;

	while (tmp)
	{
		str = concat(tmp->dirp, "/", filename);
		if (stat(str, &st) == 0)
			return (str);
		free(str);
		tmp = tmp->ptr;
	}

	return ('\0');
}

/**
  * free_list - frees a list_t
  * @head: pointer to linked list
  */

void free_list(list_path *head)
{
	list_path *stored;

	while (head)
	{
		stored = head->ptr;
		free(head->dirp);
		free(head);
		head = stored;
	}
}
