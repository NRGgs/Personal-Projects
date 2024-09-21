#include "todo.h"

void	error_malloc(void)
{
	write(1, "An error has occurred whilst allocating memory\n", 46);
}

void	error_read(void)
{
	write(1, "An error has occurred whilst retrieving the list\n", 50);
}
