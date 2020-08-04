#include "binary_trees.h"

/**
 * insert - find the correct location to insert new node
 * @root: pointer to the root node
 *
 * Return: pointer to the insertion spot
 */
heap_t *insert(heap_t *root)
{
	heap_t *queue[50];
	heap_t *insert = root;
	int start = 0, end = 0;

	while (insert && insert->left && insert->right)
	{
		queue[start] = insert->left;
		start += 1;
		if (start >= 49)
			start = 0;
		queue[start] = insert->right;
		start += 1;
		if (start >= 49)
			start = 0;
		insert = queue[end];
		end += 1;
		if (end >= 49)
			end = 0;
	}

	return (insert);
}

/**
 * heap_insert - insert a value into a max binary heap
 * @root: double pointer to the root node
 * @value: value to insert
 * Return: pointer to the inserted node or NULL if it fails
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new, *push;
	int tmp;

	if (!root)
		return (NULL);

	if (!*root)
	{
		new = binary_tree_node(*root, value);
		*root = new;
		return (new);
	}

	push = insert(*root);
	new = binary_tree_node(push, value);
	if (push->left == NULL)
		push->left = new;
	else
		push->right = new;

	while (new->parent && new->n > new->parent->n)
	{
		tmp = new->parent->n;
		new->parent->n = new->n;
		new->n = tmp;
		new = new->parent;
	}

	return (new);
}
