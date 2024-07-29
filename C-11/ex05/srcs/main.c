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

#include "../includes/do_op.h"

int	process_args(char **argv)
{
	int num1;
	int num2;
	int result;

	num1 = ft_atoi(argv[1]);
	num2 = ft_atoi(argv[3]);
	if(num2 == 0 && (argv[2][0] == OP_DIV || argv[2][0] == OP_MOD))
		return (-1);
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
	} else
		result = 0;
	return (ft_putnbr(OUT, result));
}

int	main(int argc, char **argv)
{
	if(argc == 4)
	{
		if(process_args(argv) == -1)
		{
			if(argv[2][0] == OP_DIV)
				ft_putstr(ERR, "Division by 0.");
			else if(argv[2][0] == OP_MOD)
				ft_putstr(ERR, "Modulo by 0.");
		}
	}
	return (0);
}
