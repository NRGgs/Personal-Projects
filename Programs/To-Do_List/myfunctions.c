#include "todo.h"

int	count_length(char *str)
{
	int i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	my_strcmp(char *s1, char *s2)
{
	int i = 0;
	while (s1[i] == s2[i] && s2[i] != '\0')
		i++;
	return (s2[i] - s1[i]);
}