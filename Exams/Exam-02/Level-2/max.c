/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:53:45 by ibour             #+#    #+#             */
/*   Updated: 2024/12/06 17:09:48 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int max(int *tab, unsigned int len) {

	unsigned int i = 0;
	int result = 0;

	result = tab[i];
	while (i < len) {
		if (tab[i] > result)
			result = tab[i];
		i++;
	}

	return (result);

}