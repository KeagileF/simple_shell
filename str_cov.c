#include "shell.h"

/**
 * is_interactive - A function that checks if the
 * shell is in an intaractive mode
 * @info: struct address
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int is_interactive(info_t *info)
{
	int is_stdin_tty = isatty(STDIN_FILENO);
	int is_readfd_standard = (info->readfd <= 2);

	return (is_stdin_tty && is_readfd_standard);
}


/**
 * is_delim - a function that checks if
 * character is a delimeter
 * @c: the character to check
 * @delim: the delimeter string
 * Return: 1 if true, 0 if false
 */
int is_delim(char c, char *delim)
{
	while (*delim)
		if (*delim++ == c)
			return (1);
	return (0);
}

/**
 * _isalpha - A func that checks if a given character is alphabetic
 * @c: The character to input
 * Return: 1 if c is alphabetic, 0 otherwise
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _atoi - A func that converts a string to an integer
 * @s: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */

int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
	if (s[i] == '-')
	sign *= -1;
	else if (s[i] >= '0' && s[i] <= '9')
	{
	flag = 1;
result *= 10;
	result += (s[i] - '0');
	}
	else if (flag == 1)
	{
	flag = 2;
	}
	}

	output = (sign == -1) ? -result : result;
	return (output);
}

