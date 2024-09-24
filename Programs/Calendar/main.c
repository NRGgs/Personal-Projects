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
	t_calendar	*calendar = NULL;

	start_screen();

	calendar = allocate_calendar(calendar);
	if (calendar == NULL)
		return (ERROR);

	if (ask_input(calendar) == ERROR)
	{
		free_calendar(calendar);
		return (ERROR);
	}
	create_month(calendar);
	print_month(calendar);

	free_calendar(calendar);
	return (0);
}
