#include "todo.h"

void	start_screen(void)
{
	system("clear");
	write(1, "To-do list program, by N. Mattos Oudejans\n", 43);
	write(1, "\nPress Enter to continue...\n", 29);
	getchar();
}

void	invalid_option(t_node *head)
{
	system("clear");
	write(1, "It seems you've chosen an invalid option,\nTry again.\n", 54);
	write(1, "\nPress Enter to continue...\n", 29);
	getchar();
	main_menu(head);
}

void	options(t_node *head, char c)
{
	switch (c)
	{
	case '1':
		view_list(head);
		break;
	case '2':
		add_to_list(head);
		break;
	case '3':
		remove_from_list(head);
		break;
	default:
		invalid_option(head);
		break;
	}
}

void	main_menu(t_node *head)
{
	system("clear");
	write(1, "Select one of the following options:\n", 38);
	write(1, "1 | View my list\n", 18);
	write(1, "2 | Add to my list\n", 20);
	write(1, "3 | Remove from my list\n", 25);
	options(head, getchar());
}

int	main(void)
{
	// t_node *head = malloc(sizeof(t_node));
	// head = init_node(head, "the head?", 1);
	// t_node *node1 = malloc(sizeof(t_node));
	// node1 = init_node(node1, "node 2...", 2);
	// insert_node(node1, head, NULL);
	// t_node *node2 = malloc(sizeof(t_node));
	// node2 = init_node(node2, "third node!", 3);
	// insert_node(node2, node1, NULL);
	// write_to_file(head);
	t_node *head = read_from_file();
	start_screen();
	main_menu(head);
}
