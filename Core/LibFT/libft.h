/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   < libft.h >                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 16:28:41 by ibour             #+#    #+#             */
/*   Updated: 2024/08/05 16:28:41 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>

typedef unsigned char	t_byte;

int		ft_isascii(int c);
int		ft_isdigit(int c);

void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, void *src, size_t n);
void	*ft_memccpy(void *dest, void *src, int c, size_t n)

typedef struct s_list
{
	void *content;
	size_t content_size;
	struct s_list *next;
}	t_list;

#endif
