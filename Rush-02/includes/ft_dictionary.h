/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 19:47:28 by ibour             #+#    #+#             */
/*   Updated: 2024/07/24 19:47:29 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DICTIONARY_H
# define FT_DICTIONARY_H

# include "ft_boolean.h"
# include <stdlib.h>
# define ENGLISH_DICTIONARY "numbers.dict"

typedef struct t_dict_entry
{
	unsigned long	value;
	char			*str;
	t_bool			normal;
}	t_dict_entry;

typedef struct s_dict
{
	int					size;
	char				*path;
	t_bool				valid;
	t_dict_entry		*entries;
}	t_dict;

typedef enum t_error
{
	none,
	generic,
	parse,
	invalid_number,
	fail_convert
}	t_error;

typedef enum t_parse_error
{
	parsing_ok,
	empty_line,
	failed,
	reached_eof
}	t_parse_error;

t_dict			ft_load_default(void);
t_dict			ft_load(char *path);
void			ft_free(t_dict *dict);

void			ft_read_line(t_dict_entry *entr, int fd, t_parse_error *err);
char			*ft_clean_line(char *str);
t_parse_error	ft_process_line(t_dict_entry *e, char *line, unsigned int l);
int				ft_count_valid_line(char *path);
t_bool			ft_load_valid_line(char *path, int size, t_dict *dict);

void			ft_swap_dictionary_entry(t_dict_entry *a, t_dict_entry *b);
void			ft_update_normal_flag(t_dict *dict);
void			ft_do_sort_dict(t_dict *dict, int start, int end,
					int (*func)(t_dict_entry*, t_dict_entry*));
void			ft_sort_dictionary(t_dict *dict);

int				ft_sort_dict_f_normal(t_dict_entry *a, t_dict_entry *b);
int				ft_sort_dict_f_value(t_dict_entry *a, t_dict_entry *b);

#endif
