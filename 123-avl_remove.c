#include <stdlib.h>
#include "binary_trees.h"

/**
 * balance_tree - Balances an AVL tree.
 * @tree: Pointer to a pointer to the root node of the AVL tree.
 */
void balance_tree(avl_t **tree)
{
	int balance_factor;

	if (tree == NULL || *tree == NULL)
		return;

	balance_tree(&(*tree)->left);
	balance_tree(&(*tree)->right);

	balance_factor = binary_tree_balance((const binary_tree_t *)*tree);

	if (balance_factor > 1)
		*tree = binary_tree_rotate_right((binary_tree_t *)*tree);
	else if (balance_factor < -1)
		*tree = binary_tree_rotate_left((binary_tree_t *)*tree);
}

/**
 * successor - Finds the next successor, i.e.,
 * the minimum node in the right subtree.
 * @node: Pointer to the node to start the search from.
 * Return: The minimum value of the tree rooted at the given node.
 */
int successor(bst_t *node)
{
	int left = 0;

	if (node == NULL)
		return (0);

	left = successor(node->left);
	if (left == 0)
		return (node->n);

	return (left);
}

/**
 * remove_type - Removes a node from a binary
 * search tree depending on its children.
 * @root: Pointer to the node to remove.
 * Return: 0 if it has no children, otherwise the value of its successor.
 */
int remove_type(bst_t *root)
{
	int new_value = 0;

	if (!root->left && !root->right)
	{
		if (root->parent->right == root)
			root->parent->right = NULL;
		else
			root->parent->left = NULL;
		free(root);
		return (0);
	}
	else if ((!root->left && root->right) || (!root->right && root->left))
	{
		if (!root->left)
		{
			if (root->parent->right == root)
				root->parent->right = root->right;
			else
				root->parent->left = root->right;
			root->right->parent = root->parent;
		}
		if (!root->right)
		{
			if (root->parent->right == root)
				root->parent->right = root->left;
			else
				root->parent->left = root->left;
			root->left->parent = root->parent;
		}
		free(root);
		return (0);
	}
	else
	{
		new_value = successor(root->right);
		root->n = new_value;
		return (new_value);
	}
}

/**
 * bst_remove - Removes a node from a binary search tree.
 * @root: Pointer to the root of the tree.
 * @value: Value of the node to remove.
 * Return: Pointer to the changed tree.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	int type = 0;

	if (root == NULL)
		return (NULL);
	if (value < root->n)
		bst_remove(root->left, value);
	else if (value > root->n)
		bst_remove(root->right, value);
	else if (value == root->n)
	{
		type = remove_type(root);
		if (type != 0)
			bst_remove(root->right, type);
	}
	else
		return (NULL);
	return (root);
}

/**
 * avl_remove - Removes a node from an AVL tree.
 * @root: Pointer to the root of the tree.
 * @value: Value of the node to remove.
 * Return: Pointer to the changed tree.
 */
avl_t *avl_remove(avl_t *root, int value)
{
	avl_t *root_avl = (avl_t *)bst_remove((bst_t *)root, value);

	if (root_avl == NULL)
		return (NULL);
	balance_tree(&root_avl);
	return (root_avl);
}
