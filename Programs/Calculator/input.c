#include "calculator.h"

char	*copy_stdin(char *dest, char *src)
{
	int len = 0;
	int i = 0;

	len = length(src);
	dest = malloc((len + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (i < len)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

bool	read_is_empty(char *str)
{
	int i = 0;
	while (str[i] != '\n')
	{
		if (str[i] != ' ')
			return (false);
	}
	return (true);
}

char	**read_stdin(void)
{
	char str[64];
	int y = 0;

	char **input = allocate_input();
	if (input == NULL)
		return (NULL);
	read(1, str, 64);
	while (read_is_empty(str) == false)
	{
		input[y] = copy_stdin(input[y], str);
		y++;
		read(1, str, 64);
	}
	input[y] = NULL;
	return (input);
}

void	use_stdin(void)
{
	char **input;

	input = read_stdin();
	if (input == NULL)
	{
		free_input(input);
		return ;
	}
	if (is_valid(input) == false)
	{
		free_input(input);
		use_stdin();
	}
	int result = determine_calculation(input);
	putnbr(result);
	write(1, "\n", 1);
	free_input(input);
}