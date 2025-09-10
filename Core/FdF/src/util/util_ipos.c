/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_ipos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 18:25:14 by ibour             #+#    #+#             */
/*   Updated: 2025/09/10 18:25:38 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

t_ipos	util_ipos_new(const int i, const int j)
{
	t_ipos	res;

	res.i = i;
	res.j = j;
	return (res);
}
