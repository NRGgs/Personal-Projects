#include "tictactoe.h"

void	print_grid(char *grid)
{
	int i = 0;
    while (i < 8)
    {
        write(1, grid + i, 3);
        write(1, "  ", 2);
        int j = i;
        while (j < i + 3)
        {
            char c = j + 48 + 1;
            write(1, &c, 1);
            j++;
        }
        write(1, "\n", 1);
        i += 3;
    }
}

void    print_interface(char *grid)
{
    system("clear");
    write(1, "Pick a number 0-9\n", 19);
    print_grid(grid);
}
