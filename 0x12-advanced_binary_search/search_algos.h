#ifndef SEARCH_ALGOS_H
#define SEARCH_ALGOS_H

#include <stdio.h>

void print_array(int *array, unsigned int start, unsigned int end);
int binary_search_recursive(int *array, int low, int high, int value);
int advanced_binary(int *array, size_t size, int value);

#endif /* SEARCH_ALGOS_H */
