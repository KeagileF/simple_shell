#include "shell.h"

/**
 * _myexit - A function responsible for handling
 * the exit command of the shell
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: exits with a given exit status
 * (0) if info.argv[0] != "exit"
 */

int _myexit(info_t *info)
{
    if (info->argv[1])
    {
        int exitcheck = _erratoi(info->argv[1]);
        switch (exitcheck)
        {
            case -1:
                info->status = 2;
                print_error(info, "Illegal number: ");
                _eputs(info->argv[1]);
                _eputchar('\n');
                return 1;
            default:
                info->err_num = exitcheck;
                return -2;
        }
    }
    info->err_num = -1;
    return -2;
}


/**
 * _mycd - A function to changesthe current directory
 * @info: info_t pointer to be taken as a parameter
 * Return: Always 0
 */

int _mycd(info_t *info)
{
	char *s, *dir, buffer[1024];
	int chdir_ret;

	s = getcwd(buffer, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg here<<\n");

	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME=");
		chdir_ret = chdir((!dir) ? (_getenv(info, "PWD=") ? _getenv(info, "PWD=") : "/") : dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		dir = _getenv(info, "OLDPWD=");
		_puts((!dir) ? s : dir);
		_putchar('\n');
		chdir_ret = chdir((!dir) ? "/" : dir);
	}
	else
	{
		chdir_ret = chdir(info->argv[1]);
	}

	if (chdir_ret == -1)
	{
		print_error(info, "can't cd to ");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}

	return 0;
}

/**
 * _myhelp - changes the current directory of the process
 * @info: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int _myhelp(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_array); /* temp att_unused workaround */
	return (0);
}


