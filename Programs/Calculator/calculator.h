#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <stdio.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int	determine_calculation(char **input);
int addition(int a, int b);
int subtraction(int a, int b);
int division(int a, int b);
int	multiplication(int a, int b);
int	squareroot(int a, int i);
int	power(int a, int p);
int	factorial(int a);
int	logarithm(int base, int a);

void	use_stdin(void);

char	**allocate_input(void);
void	free_input(char **input);

int	length(char *str);
int	count_arguments(char **input);
int	my_atoi(char *nbr);
void	putnbr(int nbr);
int	my_strcmp(char	*s1, char *s2);

bool	is_valid(char **input);

#endif