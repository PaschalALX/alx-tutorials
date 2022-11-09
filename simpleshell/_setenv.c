#include <stdio.h>
#include <stdlib.h>

extern char **environ;

/**
 * _strlen - gets string length
 * @str: string
 * Return: int
 */
int _strlen(const char *str)
{
	int i = 0;

	if (!str)
		return (0);

	for (; str[i]; i++)
	{}

	return (i);
}

/**
 * check_var - checks if name match with env variable
 * @env: env variable and value
 * @name: variable name
 *
 * Return: 1 if match, 0 if no match
 */
int check_var(const char *env, const char *name)
{
	int i = 0;

	if (!env || !name)
		return (0);

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
 * _setenv - set enviroment variable
 * @name: variable name
 * @value: variable value
 * @overwrite: non-zero (on) or 0 (off)
 *
 * Return: 0 on success, -1 on error
 */
int _setenv(const char *name, const char *value, int overwrite)
{
	char *buffer;
	int i = 0, j = 0;

	if (!name && !value)
		return (-1);

	buffer = malloc(sizeof(char) * (_strlen(name) + _strlen(value) + 2));
	if (!buffer)
		return (-1);

	/* fill buffer with name and value */
	while (name[i])
	{
		buffer[i] = name[i];
		i++;
	}
	buffer[i++] = '=';

	while (value[j])
	{
		buffer[i] = value[j];
		j++;
		i++;
	}
	buffer[i] = 0;

	/* add buffer (new env var & value) to env vector */
	i = 0;
	while (1)
	{
		/* checks if overwrite is not 0 and name has a match */
		if (overwrite && check_var(environ[i], name))
		{
			environ[i] = buffer;
			break;
		}

		/* checks if overwrite is 0 and name has a match */
		if (!overwrite && check_var(environ[0], name))
			break;

		/* checks for the end of the env vector */
		if (!environ[i])
		{
			environ[i] = buffer;
			environ[++i] = NULL;
			break;
		}
		i++;
	}
	return (0);
}

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	_setenv("OLDPWD", "PASCHAL_MARK_OKAFOR", 1);
	_setenv("PARTNER_NAME", "TASLIM_EZE", 0);

	while (*environ)
	{
		printf("%s\n", *environ);
		environ++;
	}
	return (0);
}
