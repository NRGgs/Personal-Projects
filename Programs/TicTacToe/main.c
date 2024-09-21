#include "tictactoe.h"

int	game_status(char *grid)
{
    int columns = check_columns(grid);
    int rows = check_rows(grid);
    int diagonal = check_diagonal(grid);

    if (columns == UNDECIDED && rows == UNDECIDED && diagonal == UNDECIDED)
    {
        if (grid_full(grid) == false)
            return (UNDECIDED);
        else
            return (DRAW);
    }
    if (columns == BOT || rows == BOT || diagonal == BOT)
		return (BOT);
	if (columns == PLAYER || rows == PLAYER || diagonal == PLAYER)
        return (PLAYER);
	return (UNDECIDED);
}

void    end_message(char *grid, int result)
{
    system("clear");
    print_grid(grid);
    switch (result)
    {
    case PLAYER:
        write(1, "Congratulations, you won the game!\n", 36);
        break;
    case BOT:
        write(1, "Unfortunately, the bot beat you...\n", 36);
        break;
    default:
        write(1, "The game ended in a draw!\n", 27);
        break;
    }
}

int	main(void)
{
    int result = UNDECIDED;
	char *grid = NULL;
	grid = init_grid(grid);
	if (grid == NULL)
		return (-1);

    print_interface(grid);
	while (result == UNDECIDED)
	{
		player_turn(grid);
		bot_turn(grid);
        print_interface(grid);
        result = game_status(grid);
	}
    end_message(grid, result);
    free(grid);
	return (0);
}
