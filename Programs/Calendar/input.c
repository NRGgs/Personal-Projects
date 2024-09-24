#include "calendar.h"

int		get_year(t_calendar *calendar)
{
	char buffer[MAX_BUFFER];
	printf("%s", ASK_YEAR_MSG);
	if (read(1, buffer, MAX_BUFFER) == 0)
		return (ERROR);
	if (valid_year(buffer, calendar) == false)
		return (ERROR);

	return (calendar->year);
}

int		get_month(t_calendar *calendar)
{
	char buffer[MAX_BUFFER];
	printf("%s", ASK_MONTH_MSG);
	if (read(1, buffer, MAX_BUFFER) == 0)
		return (ERROR);
	if (valid_month(buffer, calendar) == false)
		return (ERROR);

	return (calendar->month);
}

/* 	Ask what month/year to print.
	If only a year is given, print the entire year.
*/
int		ask_input(t_calendar *calendar)
{
	do
	{
		calendar->year = get_year(calendar);
	} while (calendar->year == ERROR);

	do
	{
		calendar->month = get_month(calendar);
	} while (calendar->month == ERROR);

	return (VALID);
}
