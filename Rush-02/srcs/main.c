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

#include "../includes/ft_num.h"
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
		*dict = load_dictionary(argv[1]);
		*convert = argv[2];
	}
	else if (argc == 2)
	{
		*dict = load_dictionary_default();
		*convert = argv[1];
	}
	else
		return (generic);
	return (none);
}

int	main(int argc, char **argv)
{
	t_error			error;
	t_dict			dictionary;
	char			*to_convert;

	error = process_args(argc, argv, &to_convert, &dictionary);
	if (error == none && !dictionary.valid)
		error = parse;
	if (error == none)
		error = process_dictionary(to_convert, &dictionary);
	handle_error(error);
	if (error == none)
		ft_putstr(OUT, "\n");
	if (dictionary.valid)
		argv[0] = 0;
	if (error)
		return (1);
	return (0);
}
