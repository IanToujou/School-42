/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 13:10:11 by ibour             #+#    #+#             */
/*   Updated: 2025/01/06 08:49:11 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philosophers.h"

int	ft_validate_args(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (-1);
	// check if numbers
	// check out of bounds


}

int main(const int argc, char **argv) {
	t_data	*data;

	if (ft_validate_args(argc, argv) == -1)
		ft_throw_error(ERROR_SYNTAX);
}
