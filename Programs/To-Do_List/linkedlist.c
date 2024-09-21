#include "todo.h"

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

t_node	*delete_node(t_node *n)
{
	// If head of list
	if (n->prev == NULL && n->next != NULL)
	{
		t_node *head = n->next;
		n->next->prev = NULL;
		free_node(n);
		return (head);
	}
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
	return (NULL);
}

void	free_list(t_node *head)
{
	t_node *n = head;
	t_node *current = head;
	while (n != NULL)
	{
		n = current;
		current = current->next;
		delete_node(n);
	}
}
