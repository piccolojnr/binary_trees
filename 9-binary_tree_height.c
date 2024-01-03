#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: height of the tree or 0 if tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t height_left = 0;
    size_t height_right = 0;
    size_t height = 0;

    if (tree == NULL)
        return (0);

    height_left = tree->left ? binary_tree_height(tree->left) + 1 : 0;
    height_right = tree->right ? binary_tree_height(tree->right) + 1 : 0;
    height = height_left > height_right ? height_left : height_right;
    return (height);
}
