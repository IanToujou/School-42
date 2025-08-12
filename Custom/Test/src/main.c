/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 12:41:43 by ibour             #+#    #+#             */
/*   Updated: 2025/08/12 12:44:44 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "../lib/ggcollect/include/gg_collect.h"

int main()
{
	t_gg_data	*data = NULL;
	char		*str;

	gg_init(data);
	str = gg_malloc(data, 3);
	str[0] = 'A';
	str[1] = 'B';
	str[2] = 'C';

	printf("%c\n", str[0]);
	printf("%c\n", str[1]);
	printf("%c\n", str[2]);

	gg_free_all(data);
}