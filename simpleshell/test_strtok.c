#include "shell.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char text[] = "Monday-Wednesday-Friday-Sunday-Tuesday";
	char *token = _strtok(text, "-");

	while (token)
	{
		printf("%s\n", token);
		token = _strtok(NULL, "-");
	}
	return (0);
}
