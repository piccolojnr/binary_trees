#include "binary_trees.h"

/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: double pointer to the root node of the BST to insert the value
 * @value: value to store in the node to be inserted
 *
 * Return: pointer to the created node, or NULL on failure
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node = NULL;
	bst_t *temp = NULL;
	bst_t *temp2 = NULL;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		temp2 = binary_tree_node((binary_tree_t *)(*tree), value);
		new_node = (bst_t *)temp2;
		*tree = new_node;
	}
	else
	{
		temp = *tree;
		if (value < temp->n)
		{
			if (temp->left)
				new_node = bst_insert(&temp->left, value);
			else
			{
				temp2 = binary_tree_node((binary_tree_t *)temp, value);
				new_node = temp->left = (bst_t *)temp2;
			}
		}
		else if (value > temp->n)
		{
			if (temp->right)
				new_node = bst_insert(&temp->right, value);
			else
			{
				temp2 = binary_tree_node((binary_tree_t *)temp, value);
				new_node = temp->right = temp2;
			}
		}
		else
			return (NULL);
	}
	return (new_node);
}
