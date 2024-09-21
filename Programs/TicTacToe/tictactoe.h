#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define UNDECIDED -1
#define PLAYER 0
#define BOT 1
#define DRAW 2
#define CENTRE 4

char	*init_grid(char *grid);
void	print_grid(char *grid);
void    print_interface(char *grid);
int     check_columns(char *grid);
int     check_rows(char *grid);
int     check_diagonal(char *grid);
bool    grid_full(char *grid);
bool	isvalid(char *grid, char *c);
int     player_input(char *grid);
void	player_turn(char *grid);
void	bot_turn(char *grid);

#endif