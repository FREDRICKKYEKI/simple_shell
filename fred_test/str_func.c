#include "main.h"
/**
 * itoa - converts an integer to a string
 * @num: the integer to be converted
 * @str: the buffer to store the string
 * @base: the base to use for the conversion
 *
 * Return: pointer to the string representation of num
 */
void itoa(int n, char str[], int base)
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

    for (i = 0, j = strlen(str) - 1; i < j; i++, j--)
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
