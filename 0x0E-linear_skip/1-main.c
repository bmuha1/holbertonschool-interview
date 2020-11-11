#include <stdio.h>
#include <stdlib.h>

#include "search.h"

skiplist_t *create_skiplist(int *array, size_t size);
void print_skiplist(const skiplist_t *list);
void free_skiplist(skiplist_t *list);

/**
 * main - Entry point
 *
 * Return: Always EXIT_SUCCESS
 */
int main(void)
{
	skiplist_t *list, *res;
	int array[] = {
		0, 1, 2, 3, 4, 7, 18, 18, 18, 19, 23, 53, 61, 62, 76, 99
	};
	size_t size = sizeof(array) / sizeof(array[0]);

	list = create_skiplist(array, size);
	print_skiplist(list);

	res =  linear_skip(list, 18);
	printf("Found %d at index: %lu\n", 18, res->index);

	free_skiplist(list);
	return (EXIT_SUCCESS);
}
