#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * _strtok - breaks a string into a sequence of
 * zero or more nonempty tokens
 * @str: string to be broken down
 * $delm: delimeter
 *
 * Return: token (char *)
 */
char *_strtok(char *str, char *delm)
{
	static char *backup;
	char *rtn = NULL;

	/* checks delimeter */
	if (!delm)
		return (NULL);

	/* checks if both backup and str have values */
	if (backup && str)
		return (NULL);

	/* checks if both backup and str are NULL */
	if (!backup && !str)
		return (NULL);
	
	/* checks if backup is NULL && str has value */
	/* Function's first call */
	if (!backup && str)
		backup = str;

	/* checks if str is NULL && backup has value */
	/* Function's subsequent calls */
	if (!str && backup)
		str = backup;
	while (*str)
	{
		/* checks if the next char is \0 */
		if (*(str + 1) == '\0')
		{
			rtn = backup;
			backup = NULL;
			return (rtn);
		}
		/* checks if the next char is the delimeter */
		if (*(str + 1) == *delm)
			*(str + 1) = '\0';
		str++;
	}
	str++;

	/* moves pointer over successive occurence of delimiter */
	while (*str == *delm)
		str++;
	rtn = backup;
	backup = str;
	return (rtn);
}
