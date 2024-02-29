#include <stdlib.h>
#include "binary_trees.h"

/**
 * array_to_bst - Constructs a Binary Search Tree (BST) from an array.
 * @array: Pointer to the array.
 * @size: Size of the array.
 * Return: Pointer to the root node of the created BST, or NULL on failure.
 */

bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root = NULL;

	if (size == 0 || array == NULL)
		return (NULL);

	for (size_t i = 0; i < size; i++)
		bst_insert(&root, array[i]);

	return (root);
}
