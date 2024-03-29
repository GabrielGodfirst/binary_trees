#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes with at least 1 child in a binary tree
 * @tree: Pointer to the root node of the tree to count nodes
 *
 * Return: Number of nodes with at least 1 child in the binary tree,
 *         or 0 if tree is NULL
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	/* If tree is NULL, return 0 */
	if (tree == NULL)
		return (0);

	/* If both left and right child pointers are not NULL*/
	/*it's a node with at least 1 child */
	if (tree->left != NULL || tree->right != NULL)
		return (1 + binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right));

	/* Recursively count the nodes with at least*/
	/*1 child in the left and right subtrees */
	return (binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right));
}
