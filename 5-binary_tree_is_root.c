#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_is_root - Checks if a given node is a root
 * @node: Pointer to the node to check
 *
 * Return: 1 if node is a root, 0 otherwise
 */

int binary_tree_is_root(const binary_tree_t *node)
{
	/* If node is NULL, it cannot be a root */
	if (node == NULL)
		return (0);

	/* If node has no parent, it is a root */
	if (node->parent == NULL)
		return (1);

	/* Otherwise, it is not a root */
	return (0);
}
