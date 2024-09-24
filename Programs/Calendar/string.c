#include "calendar.h"

int		count_length(char *str)
{
	int count = 0;
	int i = 0;

	while (str[i] != '\n' && str[i] != '\0')
	{
		if (is_digit(str[i]) == true)
			count++;
		i++;
	}
	return (count);
}
