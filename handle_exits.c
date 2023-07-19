#include "shell.h"

/**
 **_strncpy - A function that copies a string
 *@dest: string to be copied
 *@src: source string
 *@n: num of characters to be copied
 *Return: the concatenated string
 */

char *_strncpy(char *dest, const char *src, int n)
{
	char *s = dest;
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];
	for (; i < n; i++)
		dest[i] = '\0';

	return s;
}


/**
 **_strncat - a funtion that concatenates two strings
 *@dest: first string
 *@src: second string
 *@n: the amount of bytes to be used
 *Return: the concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}

/**
 **_strchr -  A func that locates a character in a string
 *@s: the string to be parsed
 *@c: the character to look for
 *Return: (s) a pointer to the memory
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}

