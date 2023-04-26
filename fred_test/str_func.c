#include "main.h"
/**
 * itoa - converts an integer to a string
 * @num: the integer to be converted
 * @str: the buffer to store the string
 * @base: the base to use for the conversion
 *
 * Return: pointer to the string representation of num
 */
void _itoa(int n, char str[], int base)
{
    int i = 0, sign = n;

    if (sign < 0)
        n = -n;
    do
	{
        str[i++] = n % base + '0';
    }
	while ((n /= base) > 0);

    if (sign < 0)
        str[i++] = '-';

    str[i] = '\0';
    rev_string(str);
}

/**
 * rev_string - reverses a string
 * @str: the string to be reversed
 *
 * Return: void
 */
void rev_string(char str[])
{
    int i, j;
    char chr;

    for (i = 0, j = _strlen(str) - 1; i < j; i++, j--)
	{
        chr = str[i];
        str[i] = str[j];
        str[j] = chr;
    }
}


/**
 * _atoi - converts a string to an integer.
 * @str: input string.
 * Return: integer.
 */
int _atoi(char *str)
{
	unsigned int count = 0, size = 0;
	unsigned int output_int = 0, pos_neg = 1, m = 1, i;

	while (*(str + count) != '\0')
	{
		if (size > 0 && (*(str + count) < '0' || *(str + count) > '9'))
			break;

		if (*(str + count) == '-')
			pos_neg *= -1;

		if ((*(str + count) >= '0') && (*(str + count) <= '9'))
		{
			if (size > 0)
				m *= 10;
			size++;
		}
		count++;
	}

	for (i = count - size; i < count; i++)
	{
		output_int = output_int + ((*(str + i) - 48) * m);
		m /= 10;
	}
	return (output_int * pos_neg);
}

/**
 * _strcmp - Compares two strings and returns an integer value 
 * indicating the relationship between them.
 * @s1: The first string to compare.
 * @s2: The second string to compare.
 * Return: An integer value indicating the relationship between s1 and s2:
*/
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

/**
 * _strlen - Returns the length of the string.
 * @str: The string to get the length of.
 * Return: The length of the string, not including the null character at the end.
*/
int _strlen(char *str)
{
	int count = 0;

	while (str[count])
		count++;

	return (count);
}

/**
 * _strncmp - compares two strings up to a specified number of 
 * characters and returns an integer value indicating the relationship between them.
 * @s1: The first string to compare.
 * @s2: The second string to compare.
 * @n: The maximum number of characters to compare.
 * Return: An integer value indicating the relationship between s1 and s2 up to n characters.
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
 * _strcat - Appends a copy of the source string to the destination string.
 * @dest: The destination string to append to.
 * @src: The source string to append.
 * Return: A pointer to the destination string.
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
 * _strcpy - Copies the source string to the destination string.
 * @dest: The destination string to copy to.
 * @src: The source string to copy.
 * Return: A pointer to the destination string.
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

/**
 * _strchr - locates a character in a string,
 * @s: string.
 * @c: character.
 * Return: the pointer to the first occurrence of the character c.
 */
char *_strchr(char *s, char c)
{
	unsigned int i = 0;

	for (; *(s + i) != '\0'; i++)
		if (*(s + i) == c)
			return (s + i);
	if (*(s + i) == c)
		return (s + i);
	return ('\0');
}

/**
 * _strdup - replicates a string in the heap memory.
 * @s: Type char pointer str
 * Return: duplicated str
 */
char *_strdup(const char *str)
{
	char *strout;
	unsigned int i, j;

	if (str == NULL)
		return (NULL);

	for (i = 0; str[i] != '\0'; i++)
		;

	strout = (char *)malloc(sizeof(char) * (i + 1));

	if (strout == NULL)
		return (NULL);

	for (j = 0; j <= i; j++)
		strout[j] = str[j];

	return (strout);
}
