#include "dfs.h"

char *read_map(char *filename)
{
	char buffer[MAXBUFFER];
	char **map;

	int fd = open(filename);
	if (fgets(buffer, MAXBUFFER, fd) == NULL)
		return (NULL);
}