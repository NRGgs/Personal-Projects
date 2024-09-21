#include "calculator.h"

int	determine_calculation(char **input)
{
	if (count_arguments(input) == 3)
	{
		int a = my_atoi(input[0]);
		int b = my_atoi(input[2]);

		if (my_strcmp(input[1], "log") == 0)
			return (logarithm(a, b));
		switch (input[1][0])
		{
			case '+':
				return (addition(a, b));
			case '-':
				return (subtraction(a, b));
			case '/':
				return (division(a, b));
			case '*':
				return (multiplication(a, b));
			case '^':
				return (power(a, b));
		}
	}
	if (count_arguments(input) == 2)
	{
		if (my_strcmp(input[0], "sqrt") == 0)
			return (squareroot(my_atoi(input[1]), 0));
		if (input[1][0] == '!')
			return (factorial(my_atoi(input[0])));
	}
	free_input(input);
	return (0);
}

int addition(int a, int b)
{
	return (a + b);
}

int subtraction(int a, int b)
{
	return (a - b);
}

int division(int a, int b)
{
	return (a / b);
}

int	multiplication(int a, int b)
{
	return (a * b);
}

int	squareroot(int a, int i)
{
	if (i * i == a)
		return (i);
	if (i * i > a)
		return (0);
	return (squareroot(a, i + 1));
}

int	power(int a, int p)
{
	if (p == 0)
		return (1);
	return (a * power(a, p - 1));
}

int	factorial(int a)
{
	if (a == 0)
		return (1);
	if (a < 0)
		return (a);
	return (a * factorial(a - 1));
}

int	logarithm(int base, int a)
{
	int p = 0;
	while (power(base, p) < a)
		p++;
	if (power(base, p) == a)
		return (p);
	return (0);
}
