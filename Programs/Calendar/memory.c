#include "calendar.h"

t_calendar	*allocate_calendar(t_calendar *calendar)
{
	calendar = malloc(sizeof(t_calendar));
	if (calendar == NULL)
		return (NULL);

	calendar->head = malloc(sizeof(t_node));
	if (calendar->head == NULL)
	{
		free(calendar);
		return (NULL);
	}

	return (calendar);
}

void		free_calendar(t_calendar *calendar)
{
	free(calendar->head);
	free(calendar);
}

t_node		*allocate_node(t_node *node)
{
	node = malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);

	node->day = EMPTY;
	node->next = NULL;
	return (node);
}

void		free_node(t_node *node)
{
	free(node);
}

void		free_list(t_node *head)
{
	t_node	*current = head;

	while (current->next != NULL)
	{
		t_node	*temp = current;
		current = current->next;
		free(temp);
	}
	free(current);
}
