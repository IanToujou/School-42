/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:00:51 by ibour             #+#    #+#             */
/*   Updated: 2024/07/15 15:00:52 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	char	*result;

	result = dest;
	while (*result != '\0')
	{
		result++;
	}
	while (*src != '\0')
	{
		*result = *(unsigned char *) src;
		result++;
		src++;
	}
	*result = '\0';
	return (dest);
}
