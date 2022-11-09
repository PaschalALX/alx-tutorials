#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct Path PATH;

/**
 * struct Path - node structure to hold env paths
 * @dir: directories in the path
 * @next: reference to next node structure
 */
struct Path
{
	char *dir;
	PATH *next;
};

char *_strtok(char *, char *);
char *_getenv(const char *);

#endif /* SHELL_H */
