#include "todo.h"

t_node	*read_from_file(void)
{
	FILE	*file = fopen("todolist.bin", "rb");
	t_node	*child = NULL;
	t_node	*head = malloc(sizeof(t_node));
	head = NULL;

	while (1)
	{
		t_node	*n = malloc(sizeof(t_node));
		if (n == NULL)
		{
			error_malloc();
			return (NULL);
		}
		// Reading priority value
		if (fread(&n->priority, (sizeof(n->priority)), 1, file) != 1)
		{
			free(n);
			break;
		}
		// Reading length of the task string
		size_t task_len = 0;
		if (fread(&task_len, sizeof(task_len), 1, file) != 1)
		{
			free(n);
			error_read();
			break;
		}
		// Reading task string
		n->task = malloc(task_len * sizeof(char));
		if (n->task == NULL)
		{
			free(n);
			error_malloc();
			break;
		}
		if (fread(n->task, sizeof(char), task_len, file) != task_len)
		{
			free_node(n);
			error_read();
			break;
		}
		// Insertion of node into list
		insert_node(n, child, NULL);
		child = n;
		if (head == NULL)
			head = n;
	}
	fclose(file);
	return (head);
}
