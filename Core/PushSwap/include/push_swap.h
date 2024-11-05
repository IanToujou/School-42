/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 18:07:09 by ibour             #+#    #+#             */
/*   Updated: 2024/11/05 19:53:31 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/libft/include/libft.h"
# include <stdlib.h>

typedef struct s_stack
{
	long			num;
	long			index;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

void	ft_handle_error();

t_stack	*ft_stack_from_args(int argc, char **argv);

t_stack	*ft_stack_new(int content);
t_stack	*ft_stack_last(t_stack *stack);
void	ft_stack_add_back(t_stack **stack, t_stack *new);
void	ft_stack_free(t_stack **stack);
int		ft_stack_size(t_stack *stack);
int		ft_stack_min(t_stack *stack_a);
int		ft_stack_max(t_stack *stack_a);
int		ft_stack_index(t_stack *stack, int num);
int		ft_stack_place_a(t_stack *stack_a, int num_push);
int		ft_stack_place_b(t_stack *stack_b, int num_push);
int		ft_stack_check_duplicate(t_stack *stack);
int		ft_stack_check_sort(t_stack *stack_a);

void	ft_stack_sort(t_stack **stack_a);
t_stack	**ft_stack_sort_a(t_stack **stack_a, t_stack **stack_b);
t_stack	*ft_stack_sort_b(t_stack **stack_a);
void	ft_stack_sort_until_three(t_stack **stack_a, t_stack **stack_b);
void	ft_stack_sort_mini(t_stack **stack_a);

void	ft_algo_ra(t_stack **stack_a, int j);
void	ft_algo_rr(t_stack **stack_a, t_stack **stack_b, int j);
void	ft_algo_rb(t_stack **stack_b, int j);
void	ft_algo_sa(t_stack **stack_a, int j);
void	ft_algo_sb(t_stack **stack_b, int j);
void	ft_algo_ss(t_stack **stack_a, t_stack **stack_b, int j);
void	ft_algo_pb(t_stack **stack_a, t_stack **stack_b, int j);
void	ft_algo_pa(t_stack **stack_a, t_stack **stack_b, int j);
void	ft_algo_rra(t_stack **stack_a, int j);
void	ft_algo_rrb(t_stack **stack_b, int j);
void	ft_algo_rrr(t_stack **stack_a, t_stack **stack_b, int j);
void	ft_algo_rrr_sub(t_stack **stack_b, int j);

int		ft_algo_rotate_ab(t_stack *stack_a, t_stack *stack_b);
int		ft_algo_rotate_ba(t_stack *stack_a, t_stack *stack_b);
int		ft_algo_push_rarb(t_stack **stack_a, t_stack **stack_b, int c, char s);
int		ft_algo_push_rrarrb(t_stack **stack_a, t_stack **stack_b, int c, char s);
int		ft_algo_push_rrarb(t_stack **stack_a, t_stack **stack_b, int c, char s);
int		ft_algo_push_rarrb(t_stack **stack_a, t_stack **stack_b, int c, char s);

int		ft_util_check_rarb(t_stack *stack_a, t_stack *stack_b, int c);
int		ft_util_check_rrarrb(t_stack *stack_a, t_stack *stack_b, int c);
int		ft_util_check_rrarb(t_stack *stack_a, t_stack *stack_b, int c);
int		ft_util_check_rarrb(t_stack *stack_a, t_stack *stack_b, int c);
int		ft_util_check_rarb_a(t_stack *stack_a, t_stack *stack_b, int c);
int		ft_util_check_rrarrb_a(t_stack *stack_a, t_stack *stack_b, int c);
int		ft_util_check_rrarb_a(t_stack *stack_a, t_stack *stack_b, int c);
int		ft_util_check_rarrb_a(t_stack *stack_a, t_stack *stack_b, int c);

#endif