#include <unistd.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool	is_valid(char c)
{
	if (!(c >= 'a' && c <= 'z') && !(c >= 'A' && c <= 'Z'))
	{
		write(1, "Try guessing a single letter\n", 23);
		return (false);
	}
	return (true);
}

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

int	*add_tried(int *tried, char c)
{
	tried[c - 97] = 1;
	return (tried);
}

int	count_length(char *str)
{
	int i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	print_tried(int *tried)
{
	int	i = 0;
	char c = 0;

	while (i < 26)
	{
		if (tried[i] == 1)
		{
			c = i + 97;
			write(1, &c, 1);
		}
		i++;
	}
	write(1, "\n", 2);
}

void	print_all(int *tried, char *hint, int attempts)
{
	write(1, "So far, you've guessed the letters: ", 37);
	print_tried(tried);
	write(1, "You have ", 10);
	putnbr(attempts);
	write(1, " guesses left\n", 15);
	write(1, "Word: ", 7);
	write(1, hint, count_length(hint) + 1);
	write(1, "\n", 1);
}

char	*init_hint(char *hint, char *word)
{
	int word_length = count_length(word);
	hint = malloc((word_length + 1) * sizeof(char));
	int i = 0;
	while (i < word_length)
	{
		hint[i] = '_';
		i++;
	}
	return (hint);
}

char	*add_hint(char *hint, char *word, char c)
{
	int i = 0;
	while (word[i] != '\0')
	{
		if (word[i] == c)
			hint[i] = c;
		i++;
	}
	return (hint);
}

bool	in_word(char c, char *word)
{
	int i = 0;
	while (word[i] != '\0')
	{
		if (word[i] == c)
			return (true);
		i++;
	}
	return (false);
}

bool	word_guessed(char *s1, char *s2)
{
	int i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0')
		i++;
	if (s1[i] == '\0')
		return (true);
	return (false);
}

int	main(void)
{
	char c[2];
	int attempts = 5;
	int *tried = malloc(26 * sizeof(int));
	char *word = "apples";
	char *hint;

	// word = choose_word(word);
	hint = init_hint(hint, word);
	write(1, hint, count_length(hint) + 1);
	write(1, "\n", 1);
	while (attempts > 0)
	{
		read(1, &c, 2);
		if (is_valid(c[0]) == true)
		{
			if (in_word(c[0], word) == true)
				hint = add_hint(hint, word, c[0]);
			else
				attempts--;
			if (word_guessed(hint, word) == true)
			{
				write(1, "You guessed the word!\n", 23);
				write(1, hint, count_length(hint) + 1);
				write(1, "\n", 1);
				break;
			}
			tried = add_tried(tried, c[0]);
			system("clear");
			print_all(tried, hint, attempts);
		}
	}
	free(tried);
	free(hint);
}