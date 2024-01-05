#include "binary_trees.h"

/**
 * binary_tree_rotate_right - rotate a binary tree to the right
 * @tree: the tree to rotate
 *
 * Return: new node
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *new_node;

	if (tree == NULL)
		return (NULL);

	new_node = tree->left;
	tree->left = new_node->right;
	new_node->right = tree;
	new_node->parent = tree->parent;
	tree->parent = new_node;
	if (tree->left)
		tree->left->parent = tree;

	return (new_node);
}
