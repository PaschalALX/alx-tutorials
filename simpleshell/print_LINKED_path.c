#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

typedef struct Path PATH;

struct Path
{
	char *dir;
	PATH *next;
};

PATH *add_path_end(char *dir, PATH **head)
{
	PATH *ptr;
	PATH *new_node;

	ptr = *head;
	new_node = malloc(sizeof(PATH));

	if (!new_node)
		return (NULL);
	new_node->dir = dir;
	new_node->next = NULL;
	if (!*head)
		*head = new_node;
	else
	{
		while (ptr)
		{
			if (!ptr->next)
			{
				ptr->next = new_node;
				break;
			}
			ptr = ptr->next;
		}
	}
	return (new_node);
}
void print_PATH(PATH *head)
{
	PATH *ptr;

	ptr = head;

	while (ptr)
	{
		printf("%s\n", ptr->dir);
		ptr = ptr->next;
	}
}
void free_PATH(PATH *head)
{
	PATH *ptr, *node_f;

	ptr = head;
	while (ptr)
	{
		node_f = ptr;
		ptr = ptr->next;
		free(node_f);
	}
}

int main(void)
{
	PATH *head;
	char *token;
	char *path;

	path = _getenv("PATH");
	token = _strtok(path, ":");

	while (token)
	{
		add_path_end(token, &head);
		token = _strtok(NULL, ":");
	}

	print_PATH(head);

	free_PATH(head);
	return (0);
}
