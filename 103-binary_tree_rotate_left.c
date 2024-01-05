#include "binary_trees.h"

/**
 * binary_tree_rotate_left - rotate a binary tree to the left
 * @tree: the root node of the tree to rotate
 *
 * Return: pointer to the new root node of the tree after rotation,
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *pivot;

	if (!tree || !tree->right)
		return (NULL);

	pivot = tree->right;
	pivot->parent = tree->parent;
	tree->parent = pivot;
	tree->right = pivot->left;
	if (pivot->left)
		pivot->left->parent = tree;

	pivot->left = tree;

	return (pivot);
}
