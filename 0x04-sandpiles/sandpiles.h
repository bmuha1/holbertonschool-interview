#ifndef _SANDPILES_H_
#define _SANDPILES_H_

#include <stdio.h>

void add_piles(int grid1[3][3], int grid2[3][3]);
int is_stable(int grid[3][3]);
void topple(int grid[3][3]);
void sandpiles_sum(int grid1[3][3], int grid2[3][3]);

#endif /* _SANDPILES_H_ */
