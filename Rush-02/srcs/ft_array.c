/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 19:47:28 by ibour             #+#    #+#             */
/*   Updated: 2024/07/24 19:47:29 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_array.h"
#include "../includes/ft_string_utils.h"

char	*ft_extend_array(char *o, char *str, unsigned int ol, unsigned int l)
{
	char	*dest;

	dest = malloc((l + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	if (o != NULL)
		ft_str_n_copy(dest, o, ol);
	ft_str_n_copy(dest + ol, str, (unsigned int)(l - ol));
	return (dest);
}
