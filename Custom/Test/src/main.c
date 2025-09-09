/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 12:41:43 by ibour             #+#    #+#             */
/*   Updated: 2025/09/09 14:58:35 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "../lib/ggcollect/include/gg_collect.h"

typedef struct s_test {
	char *value;
	void *ptr;
} t_test;

int main()
{
	t_gg_data	*data = gg_init();
	t_test *test = gg_malloc(data, sizeof(t_test));

	test->value = gg_malloc(data, 1000);
	test->ptr = gg_malloc(data, 1000);

	gg_free_all(data);
}