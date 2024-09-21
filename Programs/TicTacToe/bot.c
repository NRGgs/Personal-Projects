#include "tictactoe.h"

int current_turn(char *grid)
{
    int turns = 1;
    int i = 0;
    while (grid[i] != '\0')
    {
        if (grid[i] == 'O')
            turns++;
        i++;
    }
    return (turns);
}

void    first_turn(char *grid)
{
    if (grid[CENTRE] == 'X')
        grid[0] = 'O';
    else
        grid[CENTRE] = 'O';
}

bool	is_winning_move(char *grid, int i)
{
	grid[i] = 'O';
	if (check_columns(grid) == BOT
		|| check_rows(grid) == BOT
		|| check_diagonal(grid) == BOT)
	{
		grid[i] = '_';
		return (true);
	}
	grid[i] = '_';
	return (false);
}


bool	can_win(char *grid)
{
	int i = 0;
	while (grid[i] != '\0')
	{
		if (grid[i] == '_')
		{
			if (is_winning_move(grid, i) == true)
			{
				grid[i] = 'O';
				return (true);
			}
		}
		i++;
	}
	return (false);
}

bool	is_losing_move(char *grid, int i)
{
	grid[i] = 'X';
	if (check_columns(grid) == PLAYER
		|| check_rows(grid) == PLAYER
		|| check_diagonal(grid) == PLAYER)
	{
		grid[i] = 'O';
		return (true);
	}
	grid[i] = '_';
	return (false);
}

bool	can_lose(char *grid)
{
	int i = 0;
	while (grid[i] != '\0')
	{
		if (grid[i] == '_')
		{
			if (is_losing_move(grid, i) == true)
				return (true);
		}
		i++;
	}
	return (false);
}

bool	try_fork(char *grid)
{
	int i = 0;
	int opportunities = 0;
	while (grid[i] != '\0')
	{
		if (grid[i] == '_')
		{
			if (is_winning_move(grid, i) == true)
				opportunities++;
		}
		i++;
	}
	if (opportunities > 1)
		return (true);
	return (false);
}

bool	can_fork(char *grid)
{
	int i = 0;
	while (grid[i] != '\0')
	{
		if (grid[i] == '_')
		{
			grid[i] = 'O';
			if (try_fork(grid) == true)
				return (true);
			grid[i] = '_';
		}
		i++;
	}
	return (false);
}

bool	try_corner(char *grid)
{
	int i = 0;
	while (grid[i] != '\0')
	{
		if (grid[i] == '_' && (i == 0 || i == 2 || i == 6 || i == 8))
		{
			grid[i] = 'O';
			return (true);
		}
		i++;
	}
	return (false);
}

bool	try_edge(char *grid)
{
	int i = 0;
	while (grid[i] != '\0')
	{
		if (grid[i] == '_' && (i == 1 || i == 3 || i == 5 || i == 7))
		{
			grid[i] = 'O';
			return (true);
		}
		i++;
	}
	return (false);
}

void	bot_turn(char *grid)
{
    int turn = current_turn(grid);
    if (turn == 1)
    {
    	first_turn(grid);
        return ;
    }
    if (can_win(grid) == true)
		return ;
	if (can_lose(grid) == true)
		return ;
	if (can_fork(grid) == true)
		return ;
	if (try_corner(grid) == true)
		return ;
	if (try_edge(grid) == true)
		return ;
}
