#include <stdlib.h>

typedef struct s_node
{
	char			*task;
	int				priority;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

int	count_length(char *str)
{
	int i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	free_node(t_node *n)
{
	free(n->task);
	free(n);
}

t_node	*init_node(t_node *n, char *task, int priority)
{
	n->task = malloc((count_length(task) + 1) * sizeof(char));
	if (n->task == NULL)
		return (free(n), NULL);
	n->task = task;
	n->priority = priority;
	return (n);
}

void	insert_node(t_node *n, t_node *child, t_node *parent)
{
	n->next = parent;
	n->prev = child;
	if (parent != NULL)
		parent->prev = n;
	if (child != NULL)
		child->next = n;
}

void	delete_node(t_node *n)
{
	// If head of list
	if (n->prev == NULL && n->next != NULL)
		n->next->prev = NULL;
	// If tail of list
	else if (n->prev != NULL && n->next == NULL)
		n->prev->next = NULL;
	// If in middle of list
	else if (n->prev != NULL && n->next != NULL)
	{
		n->prev->next = n->next;
		n->next->prev = n->prev;
	}
	free_node(n);
}
