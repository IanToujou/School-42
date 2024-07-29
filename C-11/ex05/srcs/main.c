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

#include <stdio.h>

#include "../includes/do_op.h"

void	process_args(char **argv)
{
	int num1;
	int num2;
	int result;

	num1 = ft_atoi(argv[1]);
	num2 = ft_atoi(argv[3]);
	result = 0;
	if(argv[2][0] == OP_ADD) {
		result = num1 + num2;
	} else if(argv[2][0] == OP_SUB) {
		result = num1 - num2;
	} else if(argv[2][0] == OP_MUL) {
		result = num1 * num2;
	} else if(argv[2][0] == OP_DIV) {
		result = num1 / num2;
	} else if(argv[2][0] == OP_MOD) {
		result = num1 % num2;
	} else {
		result = 0;
	}
	ft_putnbr(OUT, result);
}

int	main(int argc, char **argv)
{
	if(argc == 4)
		process_args(argv);
	return (0);
}
