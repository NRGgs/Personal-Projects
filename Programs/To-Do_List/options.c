#include "todo.h"

void	view_list(t_node *head)
{
	system("clear");
	head = sort(head);
	t_node *current = head;
    int n = 1;
    write(1, "number\t| prio\t| task\n\n", 23);
    while (current != NULL) {
        printf("%d\t| %d\t| %s\n", n, current->priority, current->task);
        n++;
        current = current->next;
    }
}

int get_number_input(void)
{
	char c[MAXREAD];
	read(1, &c, MAXREAD);
	while (isvalid(c) == false)
	{
		write(1, "Please enter a valid number!\n", 29);
		read(1, &c, MAXREAD);
	}
	return (atoi(c));
}

void	add_to_list(t_node *head)
{
	char input[MAXREAD];
	read(1, input, MAXREAD);
	int i = 0;
	while (input[i] != '\n')
		i++;
	input[i] = '\0';

	int priority = get_number_input();
	t_node *n = malloc(sizeof(t_node));
	if (n == NULL)
	{
		error_malloc();
		return ;
	}
	if (init_node(n, input, priority) == NULL)
	{
		error_malloc();
		return ;
	}

	t_node *tail = head;
	while (tail->next != NULL)
		tail = tail->next;
	insert_node(n, tail, NULL);
	write_to_file(head);
	read_from_file();
}

void	remove_from_list(t_node *head)
{
	view_list(head);
	int nth_node = get_number_input();
	int i = 1;
	t_node *n = head;
	while (i < nth_node && n != NULL)
	{
		n = n->next;
		i++;
	}
	if (i != nth_node)
	{
		write(1, "No item with your chosen index exists\n", 39);
		remove_from_list(head);
		return ;
	}
	t_node *ishead = delete_node(n);
	if (ishead != NULL)
		head = ishead;
	write_to_file(head);
}
