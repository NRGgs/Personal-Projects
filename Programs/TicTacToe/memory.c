#include "tictactoe.h"

char	*init_grid(char *grid)
{
	grid = malloc((9 + 1) * sizeof(char));
	if (grid == NULL)
		return (NULL);
	int i = 0;
	while (i < 9)
	{
		grid[i] = '_';
		i++;
	}
	grid[i] = '\0';
	return (grid);
}
