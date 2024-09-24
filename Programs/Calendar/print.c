#include "calendar.h"

void	print_month(t_calendar *calendar)
{
	t_node	*today = calendar->head;
	int		column = 0;

	printf("%d/%d\n",calendar->month, calendar->year);
	printf("Mon\tTue\tWed\tThu\tFri\tSat\tSun\n");

	while (today->day != column)
	{
		if (column == SUNDAY)
			printf("\n");
		else
			printf("\t");
		column++;
	}
	while (today->next != NULL)
	{
		if (today->day == SUNDAY)
			printf("%d\n", today->nth_day);
		else
			printf("%d\t", today->nth_day);
		today = today->next;
	}
	printf("%d\n", today->nth_day);
}
