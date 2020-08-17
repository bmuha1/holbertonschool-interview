#include "sandpiles.h"

/**
 * print_grid - print a grid
 * @grid: the grid to print
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * add_piles - add the second pile to the first
 * @grid1: the first grid
 * @grid2: the second grid
 */
void add_piles(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j];
}

/**
 * is_stable - determine if the grid is stable
 * @grid: the grid to check
 *
 * Return: 1 if stable, 0 otherwise
 */
int is_stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid[i][j] > 3)
				return (0);

	return (1);
}

/**
 * topple - any piles > 3 spill over to neighboring cells
 * @grid: the grid
 */
void topple(int grid[3][3])
{
	int i, j;
	int increment[3][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				grid[i][j] -= 4;
				if (i > 0)
					increment[i - 1][j]++;
				if (i < 2)
					increment[i + 1][j]++;
				if (j > 0)
					increment[i][j - 1]++;
				if (j < 2)
					increment[i][j + 1]++;
			}
		}
	}

	add_piles(grid, increment);
}

/**
 * sandpiles_sum - compute the sum of two sandpiles
 * @grid1: the first grid
 * @grid2: the second grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	add_piles(grid1, grid2);
	while (!is_stable(grid1))
	{
		printf("=\n");
		print_grid(grid1);
		topple(grid1);
	}
}
