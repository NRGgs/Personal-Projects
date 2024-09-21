#include "tictactoe.h"

int	player_input(char *grid)
{
	char c[64];
	read(1, &c, 2);
	while (isvalid(grid, c) == false)
	{
        print_interface(grid);
		write(1, "Please enter a valid number!\n", 29);
		read(1, &c, 2);
	}
	return (c[0] - 49);
}

void	player_turn(char *grid)
{
	int pos = player_input(grid);
	grid[pos] = 'X';
}
