/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 19:47:28 by ibour             #+#    #+#             */
/*   Updated: 2024/07/24 19:47:29 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_UTILS_H
# define FT_STRING_UTILS_H

# include "ft_boolean.h"
# include <stdlib.h>

t_bool	ft_is_whitespace(char c);
t_bool	ft_is_number(char c);
t_bool	ft_is_operator(char c);

int		ft_str_length(char *str);
char	*ft_str_duplicate(char *src);
char	*ft_str_n_duplicate(char *str, int n);
char	*ft_str_copy(char *dest, char *src);
char	*ft_str_n_copy(char *dest, char *src, int n);

#endif
