#include "calculator.h"

int	length(char *str)
{
	int i = 0;
	while (str[i] != '\n')
		i++;
	return (i);
}

int	count_arguments(char **input)
{
	int	y = 0;

	while (input[y] != NULL)
		y++;
	return (y);
}

int	my_atoi(char *nbr)
{
	int i = 0;
	int sign = 1;
	int sum = 0;

	if (nbr[0] == '-')
	{
		sign = -1;
		i++;
	}
	while (nbr[i] != '\0')
	{
		sum = (sum * 10) + (nbr[i] - 48);
		i++;
	}
	return (sum * sign);
}

void	putnbr(int nbr)
{
	if (nbr < 10)
	{
		char c = nbr + 48;
		write(1, &c, 1);
		return ;
	}
	putnbr(nbr / 10);
	putnbr(nbr % 10);
}

int	my_strcmp(char	*s1, char *s2)
{
	int i = 0;
	while (s1[i] == s2[i] && s2[i] != '\0')
		i++;
	return (s2[i] - s1[i]);
}