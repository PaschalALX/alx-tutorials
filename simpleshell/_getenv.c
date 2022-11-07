#include <stdio.h>
#include <stdlib.h>

extern char **environ;

/**
 * check_var - checks if name match with env variable
 * @env: env variable and value
 * @name: variable name
 *
 * Return: 1 if match, 0 if not
 */
int check_var(char *env, const char *name)
{
	int i = 0;

	for (; env[i]; i++)
	{
		if (env[i] == '=')
			break;

		if (env[i] != name[i])
			return (0);
	}
	return (1);
}

/**
 * getvalue - retrieves value of env variable
 * @line: env line
 *
 * Return: parsed string
 */
char *getvalue(char *line)
{
	while (*line)
	{
		if (*line == '=')
			return (line + 1);
		line++;
	}

	return (NULL);
}

/**
 * _getenv - function  searches  the  environment list
 * @name: variable to search
 *
 * Return: environment variable value
 */
char *_getenv(const char *name)
{
	char *match_line;

	while (*environ)
	{
		if (check_var(*environ, name))
		{
			match_line = *environ;
			return (getvalue(match_line));
		}
		environ++;
	}
	return (NULL);
}
