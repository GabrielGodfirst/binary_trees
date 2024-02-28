#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_insert_right - Inserts a node as the right-child of another node
 * @parent: Pointer to the node to insert the right-child in
 * @value: Value to store in the new node
 *
 * Return: Pointer to the created node, or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	/* Check if parent is NULL */

	if (parent == NULL)
		return (NULL);

	/* Allocate memory for the new node */

	binary_tree_t *new_node = malloc(sizeof(binary_tree_t));

	if (new_node == NULL)
		return (NULL);

	/* Set value and pointers for the new node */
	new_node->n = value;
	new_node->parent = parent;
	new_node->right = parent->right;
	new_node->left = NULL;

	/* If parent already has a right-child, update its parent pointer */
	if (parent->right != NULL)
		parent->right->parent = new_node;

	/* Update parent's right-child pointer to the new node */
	parent->right = new_node;

	/* Return pointer to the new node */
	return (new_node);
}
