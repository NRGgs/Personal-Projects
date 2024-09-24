#include "calendar.h"

/*	Print a start screen
*/
void	start_screen(void)
{
	system("clear");
	printf("%sPress 'Enter' to continue...\n", START_MSG);
	getchar();
}

void	full_year(t_calendar *calendar)
{
	int i = 1;
	while (i <= MAX_MONTH)
	{
		calendar->month = i;
		create_month(calendar);
		print_month(calendar);
		if (i < MAX_MONTH)
			printf("\n");
		i++;
	}
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
	system("clear");
	if (calendar->month == 0)
		full_year(calendar);
	else
	{
		create_month(calendar);
		print_month(calendar);
	}

	free_calendar(calendar);
	return (0);
}
