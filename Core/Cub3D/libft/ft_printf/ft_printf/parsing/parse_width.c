/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoesy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 09:14:24 by mpoesy            #+#    #+#             */
/*   Updated: 2024/11/11 10:39:05 by mpoesy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	parse_width(const char **str, int *iswidthsetup)
{
	int	width;

	width = 0;
	if (**str >= '0' && **str <= '9')
	{
		*iswidthsetup = 1;
		width = 0;
		while (**str >= '0' && **str <= '9')
		{
			width = width * 10 + (**str - '0');
			(*str)++;
		}
	}
	return (width);
}
