#include "shell.h"

/**
  * _strdup - creates a copy of a string given as a parameter
  * @str: pointer to a string given as a parameter
  * Return: pointer to a copied string
  */

char *_strdup(char *str)
{
	int i;
	int len;
	char *nstr;

	if (!str)
		return ('\0');

	for (len = 0; str[len] != '\0';)
		len++;

	nstr = malloc(sizeof(char) * len + 1);
	if (!nstr)
		return ('\0');

	for (i = 0; i < len; i++)
		nstr[i] = str[i];

	nstr[len] = str[len];

	return (nstr);
}

/**
  * concat - concatenates strings in a newly-allocated memory
  * @first: first string
  * @sep: separator between the strings
  * @second: the second string after sep
  * Return: pointer to the concatenated string
  */

char *concat(char *first, char *sep, char *second)
{
	char *concatstr;
	int len_f;
	int len_sep;
	int len_sec;
	int i;
	int j;

	len_f = _strlen(first);
	len_sep = _strlen(sep);
	len_sec = _strlen(second);

	concatstr = malloc(len_f + len_sep + len_sec + 1);
	if (!concatstr)
		return ('\0');

	for (i = 0; first[i]; i++)
		concatstr[i] = first[i];
	j = i;

	for (i = 0; sep[i]; i++)
		concatstr[j + i] = sep[i];
	j = j + i;

	for (i = 0; second[i]; i++)
		concatstr[j + i] = second[i];
	j = j + i;

	concatstr[j] = '\0';
	return (concatstr);
}

/**
  * _strlen - gets the length of a string
  * @str: points to the string
  * Return: the length of a string
  */

int _strlen(char *str)
{
	int i = 0;

	while (*(str + i) != '\0')
		i++;

	return (i);
}

/**
  * _putchar - writes a character c to stdout
  * @c: the character to output
  * Return: 1 on success, -1 on error
  */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
  * _puts - prints a string to the screen
  * @str: pointer to string
  */

void _puts(char *str)
{
	int i = 0;

	while (str[i])
	{
		_putchar(str[i]);
		i++;
	}
}
