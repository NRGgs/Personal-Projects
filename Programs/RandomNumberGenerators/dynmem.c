#include <stdlib.h>
#include <stdio.h>

long int	rng(void)
{
	int *p;
	p = (int*)malloc(sizeof(int));
	return ((long int)p);
}

int	main(void)
{
	printf("%ld\n", rng());
	return (0);
}
