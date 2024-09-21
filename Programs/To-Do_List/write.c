#include "todo.h"

void	write_to_file(t_node *head)
{
	FILE	*file = fopen("todolist.bin", "w");
	t_node	*n = head;

	while (n != NULL)
	{
        fwrite(&n->priority, sizeof(n->priority), 1, file);
        size_t task_len = strlen(n->task) + 1;
        fwrite(&task_len, sizeof(task_len), 1, file);
        fwrite(n->task, sizeof(char), task_len, file);
		n = n->next;
	}
	fclose(file);
}
