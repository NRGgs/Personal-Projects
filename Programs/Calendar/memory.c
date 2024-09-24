#include "calendar.h"

t_data	*allocate_data(t_data *data)
{
	data = malloc(sizeof(t_data));
	if (data == NULL)
		return (NULL);

	return (data);
}

void	free_data(t_data *data)
{
	free(data);
}
