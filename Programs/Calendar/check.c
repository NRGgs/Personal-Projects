#include "calendar.h"

bool	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	else
		return (false);
}

bool	is_space(char c)
{
	if (c == ' ')
		return (true);
	else
		return (false);
}


bool	valid_year(char *buffer, t_calendar *calendar)
{
	if (count_length(buffer) > 9)
		return (false);

	int i = 0;
	int sum = 0;
	while (buffer[i] != '\n')
	{
		if (is_digit(buffer[i]) == false && is_space(buffer[i]) == false)
			return (false);
		else if (is_digit(buffer[i]) == true)
			sum = (sum * 10) + (buffer[i] - 48);
		i++;
	}
	if (sum > MAX_YEAR && sum > 0)
		return (false);
	calendar->year = sum;
	return (true);
}

bool	valid_month(char *buffer, t_calendar *calendar)
{
	if (count_length(buffer) > 2)
		return (false);

	int i = 0;
	int sum = 0;
	while (buffer[i] != '\n')
	{
		if (is_digit(buffer[i]) == false && is_space(buffer[i]) == false)
			return (false);
		else if (is_digit(buffer[i]) == true)
			sum = (sum * 10) + (buffer[i] - 48);
		i++;
	}
	if (sum > MAX_MONTH && sum > 0)
		return (false);
	calendar->month = sum;
	return (true);
}
