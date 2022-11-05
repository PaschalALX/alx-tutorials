#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

/**
 * main - Entry point
 *
 * Return: Always Success (0)
 */

int main(void)
{
	char *lineptr = NULL;
	char *av[2] = {NULL, NULL};
	size_t no = 10;
	int id;

	while (1)
	{
		printf("#cisfun$ ");
		getline(&lineptr, &no, stdin);

		/* checks for end-of-file */
		if (feof(stdin))
		{
			putchar(10);
			break;
		}
		else
		{
			id = fork();

			if (id < 0)
			{
				perror("FORK FAILED\n");
				exit(98);
			}
			if (!id)
			{
				if (lineptr[0] == 10)
					continue;

				lineptr[strlen(lineptr) - 1] = 0;
				av[0] = lineptr;

				/* checks if execve is success  */
				if (execve(av[0], av, NULL) < 0)
				{
					perror("EXEC FAILED\n");
					exit(99);
				}
			}
			else
				wait(NULL);
		}
	}

	free(lineptr);
	lineptr = NULL;
	return (0);
}
