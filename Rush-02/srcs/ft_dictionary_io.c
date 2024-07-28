/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dictionary_io.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 19:47:28 by ibour             #+#    #+#             */
/*   Updated: 2024/07/24 19:47:29 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "../includes/ft_dictionary.h"
#include "../includes/ft_boolean.h"
#include "../includes/ft_io.h"
#include "../includes/ft_string_utils.h"
#include "../includes/ft_convert.h"
#include "../includes/ft_file.h"
#include "../includes/ft_array.h"

void	ft_read_line(t_dict_entry *entry, int fd, t_parse_error *error)
{
	char			buffer[SIZE_1BYTE];
	char			*line;
	unsigned int	byte_read;
	unsigned int	total;

	total = 0;
	line = NULL;
	byte_read = read(fd, buffer, SIZE_1BYTE);
	while (byte_read > 0)
	{
		if (byte_read == (unsigned int) -1)
		{
			entry->str = 0;
			*error = failed;
			break ;
		}
		line = ft_extend_array(line, buffer, total, total + byte_read);
		total += byte_read;
		if (buffer[0] == '\n')
		{
			*error = ft_p_l(entry, line, total);
			byte_read = (unsigned int) -2;
			break ;
		}
		byte_read = read(fd, buffer, SIZE_1BYTE);
	}
	if (byte_read == 0)
		*error = reached_eof;
}

char	*ft_clean_line(char *str)
{
	int		size;
	char	**split;

	split = ft_split_whitespace(str);
	free(str);
	size = 0;
	while (split[size])
		size++;
	return (ft_str_join(size, split, " "));
}

t_parse_error	ft_p_l(t_dict_entry *e, char *line, unsigned int l)
{
	unsigned int	index;
	char			*number;

	index = 0;
	while (ft_is_number(line[index]))
		index++;
	if (line[index] == '\n')
		return (empty_line);
	if (index == 0 || index >= l)
		return (failed);
	number = ft_str_n_duplicate(line, index);
	while (line[index] == ' ')
		index++;
	if (line[index] != ':')
		return (failed);
	index++;
	while (line[index] == ' ')
		index++;
	e->value = ft_atoi_strict(number);
	e->str = ft_clean_line(
			ft_str_n_duplicate(line + index, l - index - 1));
	if (ft_str_length(e->str) == 0)
		return (failed);
	free(number);
	return (parsing_ok);
}

int	ft_count_valid_line(char *path)
{
	int				fd;
	int				count;
	t_dict_entry	*entry;
	t_parse_error	error;

	fd = ft_open(path);
	if (fd < 0)
		return (-1);
	count = 0;
	while (true)
	{
		entry = malloc(sizeof(t_dict_entry));
		error = parsing_ok;
		if (entry == NULL)
			return (-1);
		ft_read_line(entry, fd, &error);
		if (error == failed)
			return (-1);
		if (error == parsing_ok)
			count++;
		if (entry->str == 0 || error == reached_eof)
			break ;
		free(entry);
	}
	ft_close(fd);
	return (count);
}

t_bool	ft_load_valid_line(char *path, int size, t_dict *dict)
{
	int				fd;
	int				index;
	t_dict_entry	*entry;
	t_parse_error	error;

	fd = ft_open(path);
	if (fd < 0)
		return (false);
	index = 0;
	while (index < size)
	{
		error = parsing_ok;
		entry = &dict->entries[index];
		ft_read_line(entry, fd, &error);
		if (error == failed)
			return (false);
		if (error == parsing_ok)
			index++;
		if ((entry->str == 0 || error == reached_eof) && error != empty_line)
			break ;
	}
	ft_close(fd);
	return (true);
}
