#include "todo.h"

bool	isvalid(char *str)
{
	int i = 0;
	while (str[i] != '\n')
	{
		if (str[i] < '0' || str[i] > '9')
			return (false);
		i++;
	}
	return (true);
}
