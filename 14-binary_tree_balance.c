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
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 *
 * Return: balance factor of the tree or 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
    int balance = 0;
    int height_left = 0;
    int height_right = 0;

    if (tree == NULL)
        return (0);

    height_left = tree->left ? subtree_height(tree->left) + 1 : 0;
    height_right = tree->right ? subtree_height(tree->right) + 1 : 0;
    balance = height_left - height_right;

    return (balance);
}
