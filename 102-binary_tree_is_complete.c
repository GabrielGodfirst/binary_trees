#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if the tree is complete, 0 otherwise
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	int level = 0;
	int node_count = 0;
	int expected_count = 1;

	const binary_tree_t **queue = malloc(sizeof(binary_tree_t *) * 1024);

	if (queue == NULL)
		return (0);

	queue[0] = tree;

	while (node_count < expected_count)
	{
		if (tree->left)
		{
			queue[++node_count] = tree->left;
			if (tree->right)
				queue[++node_count] = tree->right;
		}
		else if (tree->right)
		{
			free(queue);
			return (0);
		}
		tree = queue[++level];
	}

	free(queue);
	return (1);
}
