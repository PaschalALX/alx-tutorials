/* Ensure this file is compiled with the _getenv.c and _strtok.c files */
/* contained in this repository */

#include <stdio.h>
#include <stdlib.h>
#include "shell.h"


/**
 * add_path_end - adds new PATH node to linked list
 * @dir: directory in the PATH
 * @head: head pointer to linked list
 * @tail: tail pointer to linked list
 *
 * Return: newly added node (PATH *)
 */
PATH *add_path_end(char *dir, PATH **head, PATH **tail)
{
	PATH *ptr;
	PATH *new_node;

	ptr = *tail;
	new_node = malloc(sizeof(PATH));

	if (!new_node)
		return (NULL);
	new_node->dir = dir;
	new_node->next = NULL;

	if (!*tail)
		*head = *tail = new_node;
	else
	{
		ptr->next = new_node;
		*tail = new_node;
	}

	return (new_node);
}
/**
 * load_env_path - loads up env path to linked list
 * @head: head pointer to PATH linked list
 * @tail: tail pointer to PATH linked list
 */
void load_env_path(PATH **head, PATH **tail)
{
	char *token;
	char *path;
	(void)head;
	path = _getenv("PATH");
	token = _strtok(path, ":");

	while (token)
	{
		add_path_end(token, head, tail);
		token = _strtok(NULL, ":");
	}

}

/**
 * print_PATH - prints path dirs from linked list
 * @head: head node of linked list
 */
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

/**
 * free_PATH - frees PATH
 * @head: head node of linked list
 */
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

/**
 * main - Entry point
 *
 * Return: Always success (0)
 */
int main(void)
{
	PATH *head, *tail;

	head = tail = NULL;

	load_env_path(&head, &tail);
	print_PATH(head);
	free_PATH(head);
	return (0);
}
