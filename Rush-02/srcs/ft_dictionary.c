/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dictionary.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 19:47:28 by ibour             #+#    #+#             */
/*   Updated: 2024/07/24 19:47:29 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_dictionary.h"

t_dict	ft_load_default(void)
{
	return (ft_load(ENGLISH_DICTIONARY));
}

t_dict	ft_load(char *path)
{
	int					size;
	t_dict_entry		*entries;
	t_dict				dictionary;

	dictionary = (t_dict){0, path, false, 0};
	size = ft_count_valid_line(path);
	if (size == -1)
		return (dictionary);
	entries = malloc((size + 1) * sizeof(t_dict_entry));
	if (!entries)
		return (dictionary);
	dictionary.size = size;
	dictionary.entries = entries;
	dictionary.valid = ft_load_valid_line(path, size, &dictionary);
	if (dictionary.valid)
		ft_sort_dictionary(&dictionary);
	return (dictionary);
}

void	ft_free(t_dict *dictionary)
{
	int		index;

	index = 0;
	while (index < dictionary->size)
	{
		free(dictionary->entries[index].str);
		index++;
	}
}
