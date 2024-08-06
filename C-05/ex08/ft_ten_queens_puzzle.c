/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abredimu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 07:43:39 by abredimu          #+#    #+#             */
/*   Updated: 2024/07/24 08:11:12 by abredimu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdio.h>

int	is_safe(char *array, char character, char current_position)
{
	int	checked_position;
	int	position_difference;

	checked_position = 0;
	while (checked_position < current_position)
	{
		position_difference = current_position - checked_position;
		if (
			array[checked_position] == character
			|| array[checked_position] == character + position_difference
			|| array[checked_position] == character - position_difference
		)
		{
			return (0);
		}
		checked_position++;
	}
	return (1);
}

int	queen_permutations(char *array, int filled_columns)
{
	int	i;
	int	possibilities;

	i = 0;
	possibilities = 0;
	if (filled_columns >= 10)
	{
		write(STDOUT_FILENO, array, 10);
		write(STDOUT_FILENO, "\n", 1);
		return (1);
	}
	i = 0;
	while (i < 10)
	{
		if (is_safe(array, i + '0', filled_columns))
		{
			array[filled_columns] = i + '0';
			possibilities += queen_permutations(array, filled_columns + 1);
		}
		i++;
	}
	return (possibilities);
}

int	ft_ten_queens_puzzle(void)
{
	char	array[10];

	return (queen_permutations(array, 0));
}
/*
int	main(void)
{
	ft_ten_queens_puzzle();
	return (0);
}
*/
