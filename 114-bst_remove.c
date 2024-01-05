#include "binary_trees.h"

/**
 * bst_min_val - finds the minimum value in a BST
 * @root: pointer to the root node of the BST
 *
 * Return: pointer to the node containing the minimum value, or NULL if the tree is empty.
 */
bst_t *bst_min_val(bst_t *root)
{
	if (root == NULL)
		return (NULL);

	while (root->left != NULL)
		root = root->left;

	return (root);
}

/**
 * bst_remove - removes a node from a BST
 * @root: pointer to the root node of the BST to remove a node from
 * @value: value to remove in the BST
 *
 * Return: pointer to the new root node of the tree after removing the desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);

	if (value > root->n)
		root->right = bst_remove(root->right, value);

	if (value == root->n)
	{
		if (root->left == NULL && root->right == NULL)
			return (NULL);

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
		else
		{
			bst_t *temp = bst_min_val(root->right);
			root->n = temp->n;
			root->right = bst_remove(root->right, temp->n);
		}
	}
	return (root);
}
