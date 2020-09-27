#include "slide_line.h"

/**
 * slide_line - Slide and merge an array of integers
 * @line: Pointer to the array of integers
 * @size: Number of elements in array
 * @direction: SLIDE_LEFT or SLIDE_RIGHT
 * Return: 1 on success, 0 otherwise
 */
int slide_line(int *line, size_t size, int direction)
{
	size_t i;
	int change = 0;

	if (direction == SLIDE_LEFT)
	{
		slide_left(line, size);
		for (i = 1; i < size && line[i] != 0; i++)
		{
			if (line[i - 1] == line[i])
			{
				line[i - 1] *= 2;
				line[i] = 0;
				change = 1;
			}
		}
		if (change)
			slide_left(line, size);
	}
	else if (direction == SLIDE_RIGHT)
	{
		slide_right(line, size);
		for (i = size - 1; i > 0 && line[i - 1] != 0; i--)
		{
			if (line[i - 1] == line[i])
			{
				line[i] *= 2;
				line[i - 1] = 0;
				change = 1;
			}
		}
		if (change)
			slide_right(line, size);
	}
	else
	{
		return (0);
	}

	return (1);
}

/**
 * slide_left - Slide an array of integers to the left
 * @line: Pointer to the array of integers
 * @size: Number of elements in array
 */
void slide_left(int *line, size_t size)
{
	int i, temp, current = 0;

	for (i = 0; i < (int) size && current < (int) size; i++)
	{
		while (line[current] != 0)
			current++;
		if (line[i] != 0 && i > current)
		{
			temp = line[i];
			line[i] = line[current];
			line[current] = temp;
		}
	}
}

/**
 * slide_right - Slide an array of integers to the right
 * @line: Pointer to the array of integers
 * @size: Number of elements in array
 */
void slide_right(int *line, size_t size)
{
	int i, temp, current = size - 1;

	for (i = size - 1; i >= 0 && current >= 0; i--)
	{
		while (current > 0 && line[current] != 0)
			current--;
		if (line[i] != 0 && i < (int) current)
		{
			temp = line[i];
			line[i] = line[current];
			line[current] = temp;
		}
	}
}
