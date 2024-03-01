
#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the binary tree.
 * Return: The height of the binary tree.
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0, right_height = 0;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (1 + (left_height > right_height ? left_height : right_height));
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree.
 * @tree: A pointer to the root node of the binary tree.
 * Return: The balance factor of the binary tree.
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_height(tree->left) - binary_tree_height(tree->right));
}

/**
 * tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: A pointer to the root node of the binary tree.
 * Return: The height of the binary tree if it's perfect, 0 otherwise.
 */

int tree_is_perfect(const binary_tree_t *tree)
{
	int left_height = 0, right_height = 0;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	left_height = tree_is_perfect(tree->left);
	right_height = tree_is_perfect(tree->right);

	if (left_height == right_height && left_height != 0)
		return (1 + left_height);

	return (0);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: A pointer to the root node of the binary tree.
 * Return: 1 if the binary tree is perfect, 0 otherwise.
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (tree_is_perfect(tree) != 0);
}

/**
 * binary_tree_is_heap - Checks if a binary tree is a valid Max Binary Heap.
 * @tree: A pointer to the root node of the binary tree.
 * Return: 1 if the binary tree is a valid Max Binary Heap, 0 otherwise.
 */

int binary_tree_is_heap(const binary_tree_t *tree)
{
	int bval = 0;

	if (tree == NULL)
		return (0);

	if (tree->left && tree->left->n > tree->n)
		return (0);
	if (tree->right && tree->right->n > tree->n)
		return (0);

	if (binary_tree_is_perfect(tree))
		return (1);

	bval = binary_tree_balance(tree);
	if (bval == 0)
		return (binary_tree_is_perfect(tree->left) &&
			binary_tree_is_heap(tree->right));
	if (bval == 1)
		return (binary_tree_is_heap(tree->left) &&
			binary_tree_is_perfect(tree->right));

	return (0);
}
