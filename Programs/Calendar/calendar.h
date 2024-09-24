#ifndef CALENDAR_H
#define CALENDAR_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

#define START_MSG "Welcome to the calendar app.\n"
#define ASK_YEAR_MSG "Insert a year.\n"
#define ASK_MONTH_MSG "Insert a month.\nLeave empty to display full year.\n"
#define	MAX_BUFFER 100
#define MAX_YEAR 999999
#define MAX_MONTH 12
#define INVALID 0
#define VALID 1
#define ERROR -1


typedef struct s_data
{
	int	year;
	int	month;
} t_data;

t_data	*allocate_data(t_data *data);
void	free_data(t_data *data);

int		ask_input(t_data *data);

int		count_length(char *str);
char	*copy_string(char *source, char *destination);

bool	is_digit(char c);
bool	is_space(char c);

bool	valid_year(char *buffer, t_data *data);
bool	valid_month(char *buffer, t_data *data);

#endif
