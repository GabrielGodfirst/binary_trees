#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: Pointer to the root node of the tree to measure the height.
 * Return: The height of the tree.
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t l = 0, r = 0;

	if (tree)
	{
		l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
		r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	}
	return ((l > r) ? l : r);
}

/**
 * bal_avl - Checks if a tree is AVL by comparing subtree heights.
 * @tree: Pointer to the root node of the tree to check.
 * @lower: Lower bound of node values.
 * @high: Upper bound of node values.
 * Return: 1 if tree is AVL, 0 if not.
 */
int bal_avl(const binary_tree_t *tree, int lower, int high)
{
	size_t height_l, height_r, balancer;

	if (!tree)
		return (1);

	if (tree->n > high || tree->n < lower)
		return (0);

	height_l = binary_tree_height(tree->left);
	height_r = binary_tree_height(tree->right);
	balancer = height_l > height_r ? height_l - height_r : height_r - height_l;

	if (balancer > 1)
		return (0);

	return (bal_avl(tree->left, lower, tree->n - 1) &&
			bal_avl(tree->right, tree->n + 1, high));
}

/**
 * binary_tree_is_avl - Checks if a binary tree is a valid AVL tree.
 * @tree: Pointer to the root node of the tree to check.
 * Return: 1 if tree is AVL, 0 if not.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (bal_avl(tree, INT_MIN, INT_MAX));
}
