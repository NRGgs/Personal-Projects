#include <unistd.h>

void	putnbr(int n)
{
	if (n < 10)
	{
		char c = n + 48;
		write(1, &c, 1);
		return ;
	}
	putnbr(n / 10);
	putnbr(n % 10);
}

int	main(void)
{
	write(1, "Think of a number 0-100.\nH = Higher, L = Lower, C = Correct\n", 61);
	write(1, "50\n", 4);
	char c[2];
	int n = 50;
	int min = 0;
	int max = 100;
	int guesses = 0;
	read(1, &c, 2);
	while (c[0] != 'C')
	{
		if (c[0] == 'H')
			min = n;
		else if (c[0] == 'L')
			max = n;
		n = (max - min) / 2 + min;
		guesses++;
		putnbr(n);
		write(1, "\n", 2);
		read(1, &c, 2);
	}
	write(1, "Amount of guesses needed: ", 27);
	putnbr(guesses);
	write(1, "\n", 2);
	return (0);
}