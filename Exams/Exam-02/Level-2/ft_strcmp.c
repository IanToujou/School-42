/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:54:02 by ibour             #+#    #+#             */
/*   Updated: 2024/11/28 17:54:40 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2) {
	int i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i]) {
		i++;
	}
	return s1[i] - s2[i];
}