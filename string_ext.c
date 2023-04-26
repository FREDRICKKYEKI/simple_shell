#include "main.h"

/**
 * _atoi - converts string to integer
 * @s: the string to convert
 *
 * Return: returns the converted number
 */
int _atoi(char *s)
{
	int count, sign, result, check;
	unsigned int num;

	/* initialise sign as positive and number as zero */
	count = 0;
	sign = 1;
	num = 0;
	/* iterates through the string */
	while (s[count] != '\0')
	{
		/* change sign if negative is encountered */
		if (s[count] == '-')
		{
			sign = -sign;
		}
		/* if number counvert it to int */
		else if (s[count] >= '0' && s[count] <= '9')
		{
			num = num * 10 + (s[count] - '0');
			check = count + 1;
			/* break if next digit is not a number */
			if (s[check] < '0' || s[check] > '9')
				break;
		}
		count++;
	}
	result = num * sign;
	return (result);
}

/**
 * _itoa - converts an integer to a string
 * @n: the integer to be converted
 * @str: the buffer to store the string
 * @base: the base to use for the conversion
 *
 * Return: pointer to the string representation of num
 */
void _itoa(int n, char *str, int base)
{
	int i = 0, sign = n;

	if (sign < 0)
		n = -n;
	do {
		str[i++] = n % base + '0';
	} while ((n /= base) > 0);

	if (sign < 0)
		str[i++] = '-';

	str[i] = '\0';
	rev_string(str);
}

/**
 * rev_string - reverses a string
 * @str: the string to be reversed
 */
void rev_string(char *str)
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
 * _strdup - duplicates a string in the heap memory.
 * @str: the string to duplicate
 *
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
