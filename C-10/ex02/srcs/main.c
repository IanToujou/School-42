/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 13:46:34 by ibour             #+#    #+#             */
/*   Updated: 2024/07/25 13:46:36 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

char	**two_args(int *argc, char **argv, int *octet)
{
	int		i;
	char	**args;

	*octet = 0;
	i = 1;
	while (argv[1][++i] && argv[1][i] >= '0' && argv[1][i] <= '9')
		*octet = *octet * 10 + (argv[1][i] - '0');
	if (*argc > 2)
	{
		args = malloc(sizeof(char*) * *argc);
		args[0] = argv[0];
		i = 1;
		while (++i < *argc)
			args[i - 1] = ft_strdup(argv[i]);
		args[i - 1] = 0;
		*argc += 1;
		return (args);
	}
	args = malloc(sizeof(char*) * 2);
	args[0] = argv[0];
	args[1] = "stdin";
	no_args_stdin(*octet, args);
	return (0);
}

char	**three_args(int argc, char **argv, int octet)
{
	int		i;
	char	**args;

	if (argc > 3)
	{
		args = malloc(sizeof(char*) * (argc - 1));
		args[0] = argv[0];
		i = 2;
		while (++i < argc)
			args[i - 2] = ft_strdup(argv[i]);
		args[i - 2] = 0;
	}
	else
	{
		args = malloc(sizeof(char*) * 2);
		args[0] = argv[0];
		args[1] = "stdin";
		no_args_stdin(octet, args);
		return (0);
	}
	return (args);
}

int	main(int argc, char** argv)
{
	int		yo_mama;
	char	**args;

	if (argc == 1 || argv[1][0] != '-' || argv[1][0] != 'c')
		no_args(argv);
	else if(argv[1][0] == '-' && argv[1][1] == 'c')
	{
		if (argc == 2) {
			print_help(argv[0]);
			return (0);
		}
		if (argv[1][2] != '\0')
			args = two_args(&argc, argv, &yo_mama);
		else if ((yo_mama = ft_atoi(argv[2])) != -1)
			args = three_args(argc, argv, yo_mama);
		else
		{
			print_illegal(argv[0], argv[2]);
			return (1);
		}
		if (args != 0)
			print_file(argc, args, yo_mama);
	}
}
