/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_utils_check.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 19:47:28 by ibour             #+#    #+#             */
/*   Updated: 2024/07/24 19:47:29 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "../includes/ft_boolean.h"
#include "../includes/ft_string_utils.h"

t_bool	ft_is_operator(char c)
{
	return (c == '-' || c == '+');
}

t_bool	ft_is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\r' || c == '\f');
}

t_bool	ft_is_number(char c)
{
	return (c >= '0' && c <= '9');
}
