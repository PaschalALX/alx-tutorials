#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * shell - command line interpreter
 */
void shell(void)
{
	char *lineptr = NULL;
	size_t no = 10;
	pid_t id;
	char *av[2] = {NULL, NULL};

	if (feof(stdin))
		return;

	printf("#cisfun$ ");
	getline(&lineptr, &no, stdin);

	if (lineptr[0] == 10)
		shell();

	lineptr[strlen(lineptr) - 1] = 0;
	av[0] = lineptr;
	id = fork();

	if (id < 0)
	{
		perror("ERROR WITH FORK FUNCTION");
		exit(99);
	}
	if (id)
	{
		if (wait(NULL) == -1)
		{
			perror("Error with wait function");
			exit(98);
		}
		shell();
	}
	else
		execve(av[0], av, NULL);
}
/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	shell();
	return (0);
}
