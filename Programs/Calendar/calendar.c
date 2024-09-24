#include "calendar.h"

bool		leap_year(int year)
{
	if (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0))
		return (false);
	else
		return (true);
}

int			get_day_count(t_calendar *calendar)
{
	if (calendar->month == FEBRUARY)
	{
		if (leap_year(calendar->year) == true)
			return (29);
		else
			return (28);
	}
	switch (calendar->month)
	{
	case APRIL:
		return (30);
	case JUNE:
		return (30);
	case SEPTEMBER:
		return (30);
	case NOVEMBER:
		return (30);
	}
	return (31);
}

int			get_yearcode(t_calendar *calendar)
{
	int x = calendar->year % 100;
	return ((x + (x / 4)) % 7);
}

int			get_monthcode(t_calendar *calendar)
{
	switch (calendar->month)
	{
	case JANUARY:
		return (0);
	case FEBRUARY:
		return (3);
	case MARCH:
		return (3);
	case APRIL:
		return (6);
	case MAY:
		return (1);
	case JUNE:
		return (4);
	case JULY:
		return (6);
	case AUGUST:
		return (2);
	case SEPTEMBER:
		return (5);
	case OCTOBER:
		return (0);
	case NOVEMBER:
		return (3);
	}

	return (5);
}

int			get_centurycode(t_calendar *calendar)
{
	int	x = calendar->year / 100;
	return (((6 - 2 * (x % 4)) % 7));
}

int			get_day(t_calendar *calendar, t_node *today)
{
	int	yearcode = get_yearcode(calendar);
	int	monthcode = get_monthcode(calendar);
	int	centurycode = get_centurycode(calendar);
	int leapcode = 0;
	if (leap_year(calendar->year) == true && (calendar->month == JANUARY || calendar->month == FEBRUARY))
		leapcode = 1;

	int	day = (yearcode
			+ monthcode
			+ centurycode
			+ today->nth_day
			- leapcode
			- 1) % 7;

	return (day);
}

t_calendar	*create_month(t_calendar *calendar)
{
	t_node	*today = NULL;
	t_node	*yesterday = NULL;
	int		current_day = 1;
	int		days_in_month = get_day_count(calendar);

	while (current_day <= days_in_month)
	{
		today = allocate_node(today);
		today->nth_day = current_day;
		today->day = get_day(calendar, today);
		today->next = NULL;

		if (current_day == 1)
			calendar->head = today;
		else
			yesterday->next = today;
		yesterday = today;
		today = today->next;
		current_day++;
	}
	return (calendar);
}
