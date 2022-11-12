#include "shell.h"

/**
 * _testpath - generates absolute paths to commands to be tested
 * @path: path from enviroment
 * @command: command to be tested
 *
 * Return: absolute path to command that need testing
 */
char *_testpath(const char *path, const char *command)
{
	char *ptr;
	int i = 0, j = 0;

	if (!path && !command)
		return (NULL);

	ptr = malloc(sizeof(char) * (_strlen(path) + _strlen(command) + 2));
	if (!ptr)
		return (NULL);
	while (i < _strlen(path))
	{
		ptr[i] = path[i];
		i++;
	}
	ptr[i++] = '/';
	while (j < _strlen(command))
	{
		ptr[i] = command[j];
		i++;
		j++;
	}
	ptr[i] = 0;
	return (ptr);
}

/**
 * _which - returns fullpath to a file or link
 * @command: command to be tested
 *
 * Return: valid absolute path to command or NULL
 */
char *_which(const char *command)
{
	char *token, *path, *testpath;

	/* check if command has fullpath */
	if (!(command[0] >= 'a' && command[0] <= 'z'))
	{
		if (!access(command, F_OK))
			return (command);
		return (NULL);
	}

	path = _getenv("PATH");
	token = _strtok(path, ":");

	while (token)
	{
		testpath = _testpath(token, command);
		token = _strtok(NULL, ":");
		if (!access(testpath, F_OK))
			return (testpath);
	}
	return (NULL);
}
