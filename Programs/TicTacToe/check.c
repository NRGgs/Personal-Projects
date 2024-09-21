#include "tictactoe.h"

int check_columns(char *grid)
{
	int i = 0;
	while (i < 7)
	{
		if (grid[i] == grid[i + 1] && grid[i] == grid[i + 2])
		{
			if (grid[i] == 'X')
				return (PLAYER);
			if (grid[i] == 'O')
				return (BOT);
		}
		i += 3;
	}
	return (UNDECIDED);
}

int check_rows(char *grid)
{
	int i = 0;
	while (i < 3)
	{
		if (grid[i] == grid[i + 3] && grid[i] == grid[i + 6])
		{
			if (grid[i] == 'X')
				return (PLAYER);
			if (grid[i] == 'O')
				return (BOT);
		}
		i += 1;
	}
	return (UNDECIDED);
}

int check_diagonal(char *grid)
{
	if ((grid[0] == grid[CENTRE] && grid[0] == grid[8])
		|| (grid[2] == grid[CENTRE] && grid[2] == grid[6]))
	{
		if (grid[CENTRE] == 'X')
			return (PLAYER);
		if (grid[CENTRE] == 'O')
			return (BOT);
	}
	return (UNDECIDED);
}

bool    grid_full(char *grid)
{
	int i = 0;
	while (grid[i] != '\0')
	{
		if (grid[i] == '_')
			return (false);
		i++;
	}
	return (true);
}

bool	isvalid(char *grid, char *c)
{
	if (c[1] != '\n' || c[0] < '1' || c[0] > '9')
		return (false);
	if (grid[c[0] - 49] != '_')
		return (false);
	return (true);
}
