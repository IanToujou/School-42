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

#ifndef FT_NUM_H
# define FT_NUM_H

# include "ft_boolean.h"

typedef struct t_dict_entry
{
	unsigned long	value;
	char			*str;
	t_bool			normal;
}	t_dict_entry;

typedef struct s_dictionary
{
	int					size;
	char				*path;
	t_bool				valid;
	struct t_dict_entry	*entries;
}	t_dictionary;

typedef enum t_error
{
	none,
	generic,
	parse,
	invalid_number,
	fail_convert
}	t_error;

#endif
