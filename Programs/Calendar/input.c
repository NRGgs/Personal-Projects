#include "calendar.h"

int	get_year(t_data *data)
{
	char buffer[1000];
	printf("%s", ASK_YEAR_MSG);
	if (read(1, buffer, MAX_BUFFER) == 0)
		return (ERROR);
	if (valid_year(buffer, data) == false)
		return (ERROR);

	return (data->year);
}

int	get_month(t_data *data)
{
	char buffer[1000];
	printf("%s", ASK_MONTH_MSG);
	if (read(1, buffer, MAX_BUFFER) == 0)
		return (ERROR);
	if (valid_month(buffer, data) == false)
		return (ERROR);

	return (data->month);
}

/* 	Ask what month/year to print.
	If only year is given, print entire year.
*/
int		ask_input(t_data *data)
{
	do
	{
		data->year = get_year(data);
	} while (data->year == ERROR);

	do
	{
		data->month = get_month(data);
	} while (data->month == ERROR);

	return (VALID);
}
