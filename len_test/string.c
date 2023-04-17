#include "main.h"

int _strcmp(char *s1, char *s2)
{
	int diff, i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		diff = s1[i] - s2[i];
		if (diff)
		{
			return (diff);
		}
		i++;
	}

	return (0);
}

int _strlen(char *str)
{
	int count = 0;

	while (str[count])
		count++;

	return (count);
}

size_t _strncmp(char *s1, char *s2, size_t n)
{
	size_t i, diff;

	for (i = 0; s1[i] != '\0' && i < n; i++)
	{
		diff = s1[i] - s2[i];

		if (diff != 0)
			return (diff);
	}
	return (0);
}

char *_strcat(char *dest, char *src)
{
	int i = 0, j = 0;

	while (dest[i])
		i++;

	while (src[j])
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];

	return (dest);
}
