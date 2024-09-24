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

#define JANUARY 1
#define FEBRUARY 2
#define MARCH 3
#define APRIL 4
#define MAY 5
#define JUNE 6
#define JULY 7
#define AUGUST 8
#define SEPTEMBER 9
#define OCTOBER 10
#define NOVEMBER 11
#define DECEMBER 12

#define MONDAY 0
#define SUNDAY 6
#define EMPTY 7

typedef struct s_node
{
	int				nth_day;
	int				day;
	struct s_node	*next;
} t_node;

typedef struct s_calendar
{
	int		year;
	int		month;
	t_node	*head;
} t_calendar;

t_calendar	*allocate_calendar(t_calendar *calendar);
void		free_calendar(t_calendar *calendar);
t_node		*allocate_node(t_node *node);
void		free_node(t_node *node);
void		free_list(t_node *head);

int			ask_input(t_calendar *calendar);

int			count_length(char *str);
bool		stringcompare(char *a, char *b);

bool		is_digit(char c);
bool		is_space(char c);

bool		valid_year(char *buffer, t_calendar *calendar);
bool		valid_month(char *buffer, t_calendar *calendar);

t_calendar	*create_month(t_calendar *calendar);

void		print_month(t_calendar *calendar);

#endif
