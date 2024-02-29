#include <stdlib.h>
#include "binary_trees.h"

/**
 * check_bst - Helper function to recursively check if a binary tree is a BST.
 * @tree: Pointer to the root node of the tree.
 * @min: Minimum valid value for the current subtree.
 * @max: Maximum valid value for the current subtree.
 * Return: 1 if the tree is a valid BST, 0 otherwise.
 */

int check_bst(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
		return (1);

	if (tree->n <= min || tree->n >= max)
		return (0);

	return (check_bst(tree->left, min, tree->n) &&
		check_bst(tree->right, tree->n, max));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree.
 * @tree: Pointer to the root node of the tree.
 * Return: 1 if the tree is a valid BST, 0 otherwise.
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (check_bst(tree, INT_MIN, INT_MAX));
}
