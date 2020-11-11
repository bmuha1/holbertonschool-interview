#include "search.h"

/**
 * linear_skip - Search for a value in a sorted skip list of integers
 * @list: Pointer to the head of the skip list
 * @value: The value to search for
 *
 * Return: Pointer to the first node where value is located
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *end;

	if (!list)
		return (NULL);

	while (list && list->express)
	{
		printf("Value checked at index [%d] = [%d]\n",
		       (int) list->express->index, list->express->n);
		if (value > list->express->n)
			list = list->express;
		else
			break;
	}

	end = list;
	if (list->express)
		end = end->express;
	else
		while (end->next)
			end = end->next;
	printf("Value found between indexes [%d] and [%d]\n",
		    (int) list->index, (int) end->index);

	while (list->index <= end->index)
	{
		printf("Value checked at index [%d] = [%d]\n",
		       (int) list->index, list->n);
		if (value == list->n)
			return (list);
		if (!list->next)
			break;
		list = list->next;
	}
	return (NULL);
}
