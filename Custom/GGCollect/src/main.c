/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 07:30:57 by ibour             #+#    #+#             */
/*   Updated: 2025/05/15 22:54:05 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

#include "../include/ggcollect.h"

void	print_test(const char *msg)
{
	printf("%s\n", msg);
}

int	main(void)
{
	__asm__ (
		"movq %0, %%rcx\n\t"
		"subq $32, %%rsp\n\t"
		"call print_test\n\t"
		"addq $32, %%rsp\n\t"
		:
		: "r"("hiii")
		: "rcx");
	return (0);
}
