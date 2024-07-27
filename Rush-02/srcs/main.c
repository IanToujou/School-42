/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 14:15:24 by ibour             #+#    #+#             */
/*   Updated: 2024/07/27 14:15:25 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "../includes/ft_dictionary.h"
#include "../includes/ft_io.h"
#include "../includes/ft_convert.h"

t_error	process_dictionary(char *to_convert, t_dict *dict)
{
	unsigned long		number;
	t_bool				put_space;

	number = ft_atoi_strict(to_convert);
	if (number == (unsigned long) -1)
		return (invalid_number);
	if (!ft_itow(dict, number, 0, false))
		return (fail_convert);
	put_space = false;
	ft_itow(dict, number, &put_space, true);
	return (none);
}

void	handle_error(t_error error)
{
	if (error == none)
		return ;
	if (error == parse)
		ft_putstr(ERROR, "Dict Error");
	else
		ft_putstr(ERROR, "Error");
	ft_putstr(ERROR, "\n");
}

t_error	process_args(int argc, char **argv, char **convert, t_dict *dict)
{
	if (argc == 3)
	{
		*dict = ft_load(argv[1]);
		*convert = argv[2];
	}
	else if (argc == 2)
	{
		*dict = ft_load_default();
		*convert = argv[1];
	}
	else
		return (generic);
	return (none);
}

int	main(int argc, char **argv)
{
	t_error	error;
	t_dict	dictionary;
	char	*to_convert;

	error = process_args(argc, argv, &to_convert, &dictionary);
	if (error == none && !dictionary.valid) {
		write(1, "\na\n", 3);
		error = parse;
	}
	if (error == none) {
		write(1, "\nb\n", 3);
		error = process_dictionary(to_convert, &dictionary);
	}
	handle_error(error);
	if (error == none) {
		write(1, "\nc\n", 3);
		ft_putstr(OUT, "\n");
	}
	if (dictionary.valid && error == none) {
		write(1, "\nd\n", 3);
		ft_free(&dictionary);
	}
	if (error)
		return (1);
	return (0);
}
