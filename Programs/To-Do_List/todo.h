#ifndef TODO_H
#define TODO_H

#include <stdio.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAXREAD 1000

typedef struct s_node
{
	char			*task;
	int				priority;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

/*	Show the main menu screen in the terminal
*/
void	main_menu(t_node *head);

/*	Count the length of the given string.
*/
int		count_length(char *str);

/*	Compare the given strings
*/
int		my_strcmp(char *s1, char *s2);

/*	Free the given node's memory
*/
void	free_node(t_node *n);

/*	Assign values to the node
*/
t_node	*init_node(t_node *n, char *task, int priority);

/*	Insert a node between the child and parent node
*/
void	insert_node(t_node *n, t_node *child, t_node *parent);

/*	Delete the given node
*/
t_node	*delete_node(t_node *n);

void	free_list(t_node *head);

/*	Write entire list to a "todolist"
*/
void	write_to_file(t_node *head);

/*	Read from "todolist.bin" and create a list using its data
*/
t_node	*read_from_file(void);

void	view_list(t_node *head);

void	add_to_list(t_node *head);

void	remove_from_list(t_node *head);

/*	Check whether the str is a single digit follow by a newline
*/
bool	isvalid(char *str);

void	error_malloc(void);

void	error_read(void);

t_node *sort(t_node *head);

#endif
