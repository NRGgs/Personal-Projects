#include "todo.h"

void	swap(t_node *a, t_node *b)
{
	t_node *temp = a->next;
	a->next = b->next;
	b->next = temp;
	if (a->next != NULL)
        a->next->prev = a;
    if (b->next != NULL)
		b->next->prev = b;
	temp = a->prev;
	a->prev = b->prev;
	b->prev = temp;
	if (a->prev != NULL)
		a->prev->next = a;
	if (b->prev != NULL)
		b->prev->next = b;
}

bool	is_sorted(t_node *head)
{
	t_node *n = head;
	while (n->next != NULL && n->priority <= n->next->priority)
		n = n->next;
	if (n->next == NULL)
		return (true);
	return (false);
}

t_node	*sort(t_node *head)
{
	t_node	*x = head;

	while (is_sorted(head) == false)
	{
		t_node *y = x;
		while (y != NULL && y->next != NULL && y->priority > y->next->priority)
		{
			swap(y, y->next);
			y = y->next;
		}
	}
	while (x->prev != NULL)
		x = x->prev;
	head = x;
	return (head);
}
