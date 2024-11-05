/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 21:46:53 by ibour             #+#    #+#             */
/*   Updated: 2024/11/05 19:54:04 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;

	a = ft_stack_from_args(argc, argv);
	if (!a || ft_stack_check_duplicate(a))
	{
		ft_stack_free(&a);
		ft_handle_error();
	}
	if (!ft_stack_check_sort(a))
		ft_stack_sort(&a);
	ft_stack_free(&a);
	return (0);
}