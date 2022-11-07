#include "shell.h"

/**
 * main - Entry point
 * @ac: argument count
 * @av: argument vector
 * Return: Always Success (0)
 */
int main(int ac, char **av)
{
	char *env;

	if (ac < 2)
	{
		printf("Usage: %s path_to_file ...\n", av[0]);
		return (1);
	}
	av++;
	while (*av)
	{
		env = _getenv(*av);

		if (env)
			printf("%s\n", env);
		else
			printf("%s NOT SET\n", *av); 
		av++;
	}
	return (0);
}
