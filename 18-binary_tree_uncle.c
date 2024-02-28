#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a node in a binary tree
 * @node: Pointer to the node to find the sibling
 *
 * Return: Pointer to the sibling node, or NULL if node is NULL,
 *         the parent is NULL, or if node has no sibling
 */

binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	/* Check if node or parent is NULL */
	if (node == NULL || node->parent == NULL)
		return (NULL);

	/* If node is the left child, return the right child (sibling) */
	if (node->parent->left == node)
		return (node->parent->right);

	/* If node is the right child, return the left child (sibling) */
	if (node->parent->right == node)
		return (node->parent->left);

	/* If node is neither the left nor the right child, return NULL */
	return (NULL);
}

/**
 * binary_tree_uncle - Finds the uncle of a node in a binary tree
 * @node: Pointer to the node to find the uncle
 *
 * Return: Pointer to the uncle node, or NULL if node is NULL or has no uncle
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *parent;

	/* Check if node is NULL */
	if (node == NULL)
		return (NULL);

	/* Get the parent of the node */
	parent = node->parent;

	/* If node has no parent */
	/*or parent has no parent (grandparent is NULL), return NULL */
	if (parent == NULL || parent->parent == NULL)
		return (NULL);

	/* Return the sibling of the parent node (uncle of the current node) */
	return (binary_tree_sibling(parent));
}
