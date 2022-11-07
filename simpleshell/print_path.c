






#include "shell.h"

int main(void)
{
	char *token;
	char *path;

	path = _getenv("PATH");
	token = _strtok(path, ":");

	while (token)
	{
		printf("%s\n", token);
		token = _strtok(NULL, ":");
	}
	return (0);
}

