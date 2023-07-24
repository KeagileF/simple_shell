#include "shell.h"

/**
 * get_environ - A function that returns the
 * string array of our environ
 * @info: Structure containing potential arguments
 * Return: Always 0
 */

char **get_environ(info_t *info)
{
    if (!info->environ || info->env_changed)
    {
        free_string_array(info->environ); // Free the previous environment array, if any
        info->environ = list_to_strings(info->env);
        info->env_changed = 0;
    }

    return info->environ;
}

/**
 * _unsetenv - A function used to remove
 * an environment variable
 * @info: Structure containing potential arguments
 *  Return: 1 on delete, 0 otherwise
 * @var: the string env var property
 */

int _unsetenv(info_t *info, char *var)
{
    list_t *current = info->env;
    list_t *previous = NULL;
    int env_changed = 0;

    if (!current || !var)
        return 0;

    while (current)
    {
        char *p = starts_with(current->str, var);
        if (p && *p == '=')
        {
            env_changed = 1;

            if (previous)
                previous->next = current->next;
            else
                info->env = current->next;

            list_t *temp = current;
            current = current->next;
            free(temp->str);
            free(temp);
        }
        else
        {
            previous = current;
            current = current->next;
        }
    }

    info->env_changed = env_changed;
    return env_changed;
}

/**
 * _setenv - A func used to set a new environment variable,
 *             or modify an existing one
 * @info: Structure containing potential arguments
 * @var: the string env var property
 * @value: the string env var value
 *  Return: 0
 */
int _setenv(info_t *info, char *var, char *value)
{
	char *buf = NULL;
	list_t *node;
	char *p;

	if (!var || !value)
		return (0);

	buf = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buf)
		return (1);
	_strcpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, value);
	node = info->env;
	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = buf;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(info->env), buf, 0);
	free(buf);
	info->env_changed = 1;
	return (0);
}

