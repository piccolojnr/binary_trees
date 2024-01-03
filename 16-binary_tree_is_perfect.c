#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree
 *
 * Return: height of the tree, 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return ((left_height > right_height ? left_height : right_height) + 1);
}

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree
 *
 * Return: size of the tree, 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (binary_tree_size(tree->left) + 1 + binary_tree_size(tree->right));
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree
 *
 * Return: 1 if perfect, 0 otherwise. If tree is NULL, return (0).
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height, nodes, max_nodes;

	if (tree == NULL)
		return (0);

	height = binary_tree_height(tree);
	nodes = binary_tree_size(tree);
	max_nodes = (1 << height) - 1;

	return (nodes == max_nodes);
}
