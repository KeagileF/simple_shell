#include "shell.h"

/**
 * _eputs - A funcion that prints an input string
 * @str: the printed string
 *
 * Return: Nothing
 */

void _eputs(const char *str)
{
	if (!str)
		return;

	for (; *str != '\0'; str++)
		_eputchar(*str);
}

/**
 * _eputchar - A function that writes
 * the character c to stderr
 * @c: printer character
 *
 * Return: On success 1.
 * On error, -1 is returned
 */
int _eputchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putfd - A function tht writes
 * the character c to given fd
 * @c: printed character
 * @fd: The file descriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned
 */
int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _putsfd -A function that prints an input string
 * @str: printed string
 * @fd: File descriptor to write to
 *
 * Return: the number of chars put
 */
int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}
