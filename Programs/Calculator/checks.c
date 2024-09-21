#include "calculator.h"

bool	is_number(char	*nbr)
{
	int i = 0;

	if (nbr[0] == '-')
		i++;
	while (nbr[i] != '\0')
	{
		if (!(nbr[i] >= '0' && nbr[i] <= '9'))
			return (false);
		i++;
	}
	return (true);
}

bool	is_valid(char **input)
{
	if (count_arguments(input) == 3)
	{
		char c = input[1][0];
		if (c != '+' && c != '-' && c != '/' && c != '*' && c != '^'
			&& my_strcmp(input[1], "log") != 0)
			return (false);
		if (is_number(input[0]) == false || is_number(input[2]) == false)
			return (false);
		return (true);
	}
	else if (count_arguments(input) == 2)
	{
		if (my_strcmp(input[0], "sqrt") == 0 && is_number(input[1]) == true)
			return (true);
		if (input[1][0] == '!' && is_number(input[0]) == true)
			return (true);
		return (false);
	}
	return (false);
}