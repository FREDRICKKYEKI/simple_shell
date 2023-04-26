#include "main.h"

/**
 * _strcmp - compares two strings are similar
 * @s1: first string
 * @s2: second string
 *
 * Return: 0 on success, difference on failure
 */
int _strcmp(char *s1, char *s2)
{
	int diff, i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		diff = s1[i] - s2[i];
		if (diff)
			return (diff);
		i++;
	}
	diff = s1[i] - s2[i];
	if (diff)
		return (diff);

	return (0);
}

/**
 * _strlen - gets the length of a string
 * @str: the string to get the length
 *
 * Return: the length of the string
 */
int _strlen(char *str)
{
	int count = 0;

	while (str[count])
		count++;

	return (count);
}

/**
 * _strncmp - compares the first n bytes of two strings
 * @s1: the first string
 * @s2: the second string
 * @n: the number of bytes to compare
 *
 * Return: 0 on success, diffrence on failure
 */
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

/**
 * _strcat - concatenates two strings
 * @dest: the string to append to
 * @src: the string to be appended
 *
 * Return: returns the concatenated string
 */
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

/**
 * _strcpy - copies a given string content
 * @dest: where to copy the string to
 * @src: the string to be copied
 *
 * Return: returns the copied string
 */
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
