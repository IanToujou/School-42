/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 12:06:17 by ibour             #+#    #+#             */
/*   Updated: 2025/04/18 12:06:44 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_parse	ft_init_parse_data(void)
{
	t_parse	data;

	data.quotes = ft_init_quote();
	data.i = 0;
	data.begin_str = 0;
	data.pipe = 0;
	data.flag = false;
	data.size = 0;
	data.token_amount = 0;
	data.index_token = 0;
	return (data);
}
