#include "calculator.h"

char	**allocate_input(void)
{
	char **input;

	input = malloc(4 * sizeof(char *));
	int y = 0;
	while (y < 4)
		input[y++] = NULL;
	return (input);
}

void	free_input(char **input)
{
	int y = 0;
	while (input[y] != NULL)
	{
		free(input[y]);
		y++;
	}
	free(input);
}