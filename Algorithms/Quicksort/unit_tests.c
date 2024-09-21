#include <unistd.h>
#include <stdio.h>

void	swap(int *arr, int i, int j);
int		choose_pivot(int *arr, int left, int right);
void	quicksort(int *arr, int left, int right);

void	test_swap(void)
{
	int a[2] = {1, 2};
	int b[2] = {2, 1};
	swap(a, 0, 1);
	int i = 0;
	while (a[i] == b[i] && i <= 1)
		i++;
	if (i != 2)
	{
		write(1, "Failed test 1\n", 15);
		return ;
	}

	int c[4] = {1, 2, 3, 4};
	int d[4] = {1, 2, 4, 3};
	swap(c, 2, 3);
	i = 0;
	while (c[i] == d[i] && i <= 3)
		i++;
	if (i != 4)
	{
		write(1, "Failed test 2\n", 15);
		return ;
	}
}

void	test_pivot(void)
{
	int a[2] = {1, 2};
	choose_pivot(a, 0, 1);
}

void	test_quicksort(void)
{
	int	a[2] = {2, 1};
	int b[2] = {1, 2};
	quicksort(a, 0, 1);
	// for (int j = 0; j < 2; j++)
	// 	printf("%d\n", a[j]);
	int i = 0;
	while (a[i] == b[i] && i <= 1)
		i++;
	if (i != 2)
	{
		write(1, "Failed test 1\n", 15);
		return ;
	}

	int c[3] = {2, 1, 3};
	int d[3] = {1, 2, 3};
	quicksort(c, 0, 2);
	i = 0;
	while (c[i] == d[i] && i <= 2)
		i++;
	if (i != 3)
	{
		write(1, "Failed test 2\n", 15);
		return ;
	}

	// printf("STARTING TEST 3-----------------\n");
	int e[11] = {7, 5, 1, 3, 10, 6, 3, 8, 2, 9, 4};
	int f[11] = {1, 2, 3, 3, 4, 5, 6, 7, 8, 9, 10};
	quicksort(e, 0, 10);
	// for (int j = 0; j < 11; j++)
	// 	printf("%d\n", e[j]);
	i = 0;
	while (e[i] == f[i] && i <= 5)
		i++;
	if (i != 6)
	{
		write(1, "Failed test 3\n", 15);
		return ;
	}

	int x[3] = {1, 2, 3};
	int y[3] = {1, 2, 3};
	quicksort(x, 0, 2);
	i = 0;
	while (x[i] == y[i] && i <= 1)
		i++;
	if (i != 2)
	{
		write(1, "Failed test 4\n", 15);
		return ;
	}
}

int main(void)
{
	test_swap();
	write(1, "Passed swap\n", 13);
	// test_pivot();
	// write(1, "Passed pivot\n", 14);
	test_quicksort();
	write(1, "Passed quicksort\n", 18);
	return (0);
}
