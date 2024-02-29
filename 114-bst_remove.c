#include <stdlib.h>
#include "binary_trees.h"

/**
 * bst_find_min - Finds the minimum node in a BST.
 * @node: Pointer to the root node of the BST.
 * Return: Pointer to the minimum node.
 */

bst_t *bst_find_min(bst_t *node)
{
	while (node->left != NULL)
		node = node->left;
	return (node);
}

/**
 * bst_remove - Removes a node from a Binary Search Tree (BST).
 * @root: Pointer to the root node of the BST.
 * @value: Value to remove from the BST.
 * Return: Pointer to the root node of the tree after removing the value.
 */

bst_t *bst_remove(bst_t *root, int value)
{
	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL)
		{
			bst_t *temp = root->right;

			free(root);
			return (temp);
		}
		else if (root->right == NULL)
		{
			bst_t *temp = root->left;

			free(root);
			return (temp);
		}

		bst_t *temp = bst_find_min(root->right);

		root->n = temp->n;
		root->right = bst_remove(root->right, temp->n);
	}

	return (root);
}
