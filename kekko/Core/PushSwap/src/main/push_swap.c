/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 08:34:07 by ibour             #+#    #+#             */
/*   Updated: 2024/11/06 09:44:09 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int	ft_atoi_alt(const char *str)
{
	int				mod;
	long long int	i;

	i = 0;
	mod = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f'
		|| *str == '\v' || *str == '\r')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			mod = -1;
		str++;
	}
	ft_atoi_check_valid(*str);
	while (*str)
	{
		if (!ft_isdigit(*str))
			ft_handle_error();
		i = i * 10 + (*str - 48);
		str++;
	}
	if ((mod * i) > 2147483647 || (mod * i) < -2147483648)
		ft_handle_error();
	return (mod * i);
}

static void	ft_free_str(char **tab)
{
	char	*tmp;

	if (!tab)
		return ;
	while (*tab)
	{
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
		ft_stack_add_back(&stack, ft_stack_new(ft_atoi_alt(tab[i])));
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
		ft_stack_add_back(&stack, ft_stack_new(ft_atoi_alt(tab[i])));
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
		ft_handle_error();
	if (argc == 2)
		stack = ft_stack_from_str(argv[1]);
	else
		stack = ft_stack_from_tab(argc, argv);
	return (stack);
}
