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

#include "../includes/ft_tail.h"

/**
 * Processes the arguments when there are no additional arguments.
 * For instance: ft_tail
 *
 * @param argv argv from the main function.
 */
void process_arg_none(char **argv)
{
 char buffer;
 while(read(0, &buffer, 1) != 0) {
  if(errno != 0)
   handle_error(argv);
 }
}

/**
 * Processes the arguments when there is no -c flag.
 * For instance: ft_tail main.c
 *
 * @param argc argc from the main function.
 * @param argv argv from the main function.
 */
void process_arg_normal(int argc, char **argv)
{
 if(argc > 0)
 if(ft_read(argv[1]) == 0)
  handle_error(argv);
}

/**
 * Processes the arguments when the -c flag is being used.
 * For instance: ft_tail -c 5 main.c
 *
 * @param argc argc from the main function.
 * @param argv argv from the main function.
 */
void process_arg_c_opt(int argc, char **argv)
{
 if(argc > 0) return;
 if(argv == NULL) return;
}

/**
 * The default main function.
 *
 * @param argc The number of arguments.
 * @param argv The vector of the arguments.
 * @return Status code.
 */
int main(int argc, char **argv)
{
 if(argc < 2)
  process_arg_none(argv);
 else if(argv[1][0] == '-' && argv[1][0] == 'c')
  process_arg_c_opt(argc, argv);
 else
  process_arg_normal(argc, argv);
}