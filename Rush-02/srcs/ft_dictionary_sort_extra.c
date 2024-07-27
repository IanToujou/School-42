/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dictionary_sort_extra.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 19:47:28 by ibour             #+#    #+#             */
/*   Updated: 2024/07/24 19:47:29 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_dictionary.h"

int	ft_sort_dict_f_normal(t_dict_entry *a, t_dict_entry *b)
{
	return (a->normal > b->normal);
}

int	ft_sort_dict_f_value(t_dict_entry *a, t_dict_entry *b)
{
	return (a->value > b->value);
}
