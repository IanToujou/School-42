/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 19:48:28 by ibour             #+#    #+#             */
/*   Updated: 2024/07/29 19:48:29 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DO_OP_H
# define DO_OP_H

# include <unistd.h>

# define OP_ADD '+'
# define OP_SUB '-'
# define OP_MUL '*'
# define OP_DIV '/'
# define OP_MOD '%'

# define IN 0
# define OUT 1
# define ERR 2

int		ft_atoi(char *str);
void	ft_putchar(const int fd, const char c);
void	ft_putstr(const int fd, const char *str);
int		ft_putnbr(const int fd, const int nb);

#endif
