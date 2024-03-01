#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap.
 * @tree: A pointer to the root node of the binary tree.
 * Return: 1 if the binary tree is a valid Max Binary Heap, 0 otherwise.
 */

int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	/* Check if the current node has children */
	if (tree->left == NULL && tree->right == NULL)
		return (1);

	/* Check if the current node's value is greater than its children */
	if (tree->left != NULL && tree->n < tree->left->n)
		return (0);

	if (tree->right != NULL && tree->n < tree->right->n)
		return (0);

	/* Recursively check the left and right subtrees */
	if (!binary_tree_is_heap(tree->left) || !binary_tree_is_heap(tree->right))
		return (0);

	return (1);
}
