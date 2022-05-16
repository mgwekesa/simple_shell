#include "shell.h"

/**
 * _strcat - a function
 * @dest: dest
 * @src: string
 *
 * Return: 1 or 0
 */

char	*_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (dest[i] && dest[i] != '\0')
		i++;
	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
