#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int	rng(void)
{
	srand(time(0));
	return (rand());
}

int	main(void)
{
	printf("%d\n", rng());
	return (0);
}
