#include "calendar.h"

/*	Print a start screen
*/
void	start_screen(void)
{
	system("clear");
	printf("%sPress 'Enter' to continue...\n", START_MSG);
	getchar();
}

int		main(void)
{
	t_data	*data = NULL;

	start_screen();

	data = allocate_data(data);
	if (data == NULL)
		return (ERROR);

	if (ask_input(data) == ERROR)
	{
		// error_occurred();
		free_data(data);
		return (ERROR);
	}

	// printf("%s\n%s\n", data->year, data->month);

	free_data(data);
	return (0);
}
