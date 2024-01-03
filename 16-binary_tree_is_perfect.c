#include "binary_trees.h"

/**
 * depth - measures the depth of a node in a binary tree
 * @tree: pointer to the node to measure the depth
 *
 * Return: depth of a node in a binary tree. If tree is NULL, return 0.
 */
size_t depth(const binary_tree_t *tree)
{
	size_t d = 0;
	while (tree != NULL)
	{
		d++;
		tree = tree->left;
	}
	return d;
}

/**
 * is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * @d: depth
 * @level: level
 *
 * Return: 1 if perfect, 0 otherwise. If tree is NULL, return 0.
 */
int is_perfect(const binary_tree_t *tree, int d, int level)
{
	// Check if the tree is empty
	if (tree == NULL)
		return 1;

	// Check the presence of children
	if (tree->left == NULL && tree->right == NULL)
		return (d == level + 1);

	if (tree->left == NULL || tree->right == NULL)
		return 0;

	return is_perfect(tree->left, d, level + 1) &&
		   is_perfect(tree->right, d, level + 1);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if perfect, 0 otherwise. If tree is NULL, return 0.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int d = depth(tree);
	return is_perfect(tree, d, 0);
}
