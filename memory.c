#include "shell.h"

/**
 * bfree: pointer is freed & voids the address
 * @ptr: address of the pointer to be freed
 *
 * Return: 1 if freed, otherwise 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
