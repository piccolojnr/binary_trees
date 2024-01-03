#include "binary_trees.h"

size_t subtree_height(const binary_tree_t *tree);
/**
 * subtree_height - measures the height of a binary subtree
 * @tree: pointer to the root node of the subtree to measure the height
 *
 * Return: height of the tree or 0 if tree is NULL.
 */
size_t subtree_height(const binary_tree_t *tree)
{
	size_t height_left = 0;
	size_t height_right = 0;
	size_t height = 0;

	if (tree == NULL)
		return (0);

	height_left = tree->left ? subtree_height(tree->left) + 1 : 0;
	height_right = tree->right ? subtree_height(tree->right) + 1 : 0;
	height = height_left > height_right ? height_left : height_right;
	return (height);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if perfect, 0 otherwise. If tree is NULL, return 0.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int height_left, height_right;
	int perfect = 1;

	if (tree == NULL)
		return (0);

	height_left = subtree_height(tree->left);
	height_right = subtree_height(tree->right);
	if (height_left != height_right)
		return (0);

	if (tree->left != NULL)
		perfect = binary_tree_is_perfect(tree->left);

	if (tree->right != NULL)
		perfect = binary_tree_is_perfect(tree->right);

	return (perfect);
}
