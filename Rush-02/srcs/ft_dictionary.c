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

#include "../includes/ft_io.h"

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
	if (size == -1) {
		ft_putstr(OUT, "size is -1\n");
		return (dictionary);
	}
	ft_putstr(OUT, "allocating\n");
	entries = malloc((size + 1) * sizeof(t_dict_entry));
	if (entries == NULL) {
		ft_putstr(OUT, "malloc\n");
		return (dictionary);
	}
	ft_putstr(OUT, "setting values\n");
	dictionary.size = size;
	dictionary.entries = entries;
	dictionary.valid = ft_load_valid_line(path, size, &dictionary);
	if (dictionary.valid)
		ft_sort_dictionary(&dictionary);
	return (dictionary);
}

void	ft_free(const t_dict *dict)
{
	int		index;

	index = 0;
	while (index < dict->size)
	{
		free(dict->entries[index].str);
		index++;
	}
}
