#include <stdlib.h>
#include "binary_trees.h"

/**
 * new_link - Creates a new linked list node with the given binary tree node
 * @node: Pointer to the binary tree node
 * Return: Pointer to the newly created linked list node, or NULL on failure
 */

link_t *new_link(binary_tree_t *node)
{
	link_t *new_node = malloc(sizeof(link_t));

	if (new_node == NULL)
		return (NULL);

	new_node->node = node;
	new_node->next = NULL;
	return (new_node);
}

/**
 * free_links - Frees the memory allocated for a linked list
 * @head: Pointer to the head of the linked list
 */

void free_links(link_t *head)
{
	while (head != NULL)
	{
		link_t *temp = head;

		head = head->next;
		free(temp);
	}
}

/**
 * push_link - Pushes a new node into the linked list
 * @node: Pointer to the binary tree node to be pushed
 * @head: Pointer to the head of the linked list
 * @tail: Pointer to the tail of the linked list
 * Return: 1 on success, 0 on failure
 */

int push_link(binary_tree_t *node, link_t **head, link_t **tail)
{
	link_t *new_node = new_link(node);

	if (new_node == NULL)
	{
		free_links(*head);
		return (0);
	}
	if (*head == NULL)
		*head = new_node;
	else
		(*tail)->next = new_node;
	*tail = new_node;
	return (1);
}

/**
 * pop_link - Pops a node from the linked list
 * @head: Pointer to the head of the linked list
 */

void pop_link(link_t **head)
{
	if (*head == NULL)
		return;
	link_t *temp = *head;
	*head = (*head)->next;
	free(temp);
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree
 * Return: 1 if the tree is complete, 0 otherwise
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	link_t *head = new_link((binary_tree_t *)tree);

	if (head == NULL)
		return (0);

	link_t *tail = head;
	int flag = 0;

	while (head != NULL)
	{
		if (head->node->left != NULL)
		{
			if (flag == 1)
			{
				free_links(head);
				return (0);
			}
			if (!push_link(head->node->left, &head, &tail))
				return (0);
		}
		else
			flag = 1;

		if (head->node->right != NULL)
		{
			if (flag == 1)
			{
				free_links(head);
				return (0);
			}
			if (!push_link(head->node->right, &head, &tail))
				return (0);
		}
		else
			flag = 1;

		pop_link(&head);
	}

	free_links(head);
	return (1);
}
