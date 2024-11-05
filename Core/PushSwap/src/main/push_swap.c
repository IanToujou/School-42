/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 08:34:07 by ibour             #+#    #+#             */
/*   Updated: 2024/11/05 10:41:47 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	ft_free_str(char **tab)
{
	char	*tmp;

	if (!tab)
		return ;
	while (*tab) {
		tmp = *tab;
		tab++;
		free(tmp);
	}
	*tab = NULL;
}

static t_stack	*ft_stack_from_tab(const int argc, char **tab)
{
	t_stack	*stack;
	int		i;

	stack = NULL;
	i = 1;
	while (i < argc)
	{
		ft_stack_add_back(&stack, ft_stack_new(ft_atoi(tab[i])));
		i++;
	}
	return (stack);
}

static t_stack	*ft_stack_from_str(const char *str)
{
	t_stack	*stack;
	char	**tab;
	int		i;

	stack = NULL;
	i = 0;
	tab = ft_split(str, 32);
	while (tab[i])
	{
		ft_stack_add_back(&stack, ft_stack_new(ft_atoi(tab[i])));
		i++;
	}
	ft_free_str(tab);
	free(tab);
	return (stack);
}

t_stack	*ft_stack_from_args(const int argc, char **argv)
{
	t_stack	*stack;

	stack = NULL;
	if (argc < 2)
		ft_handle_error("Incorrect number of arguments.", 1);
	if (argc == 2)
		stack = ft_stack_from_str(argv[1]);
	else
		stack = ft_stack_from_tab(argc, argv);
	return (stack);
}