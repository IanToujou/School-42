/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 13:47:28 by ibour             #+#    #+#             */
/*   Updated: 2024/07/30 13:47:29 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

/**
 * Handles multiple arguments as an input.
 *
 * @param argc The argument count.
 * @param argv The argument vector.
 */
void    mult_arguments(t_grid *grid, t_solution *sol, int argc, char **argv)
{
    int index;

    index = 0;
    while (index < argc) {
        if (load_grid(argv[index], grid))
            process_grid(grid, sol);
        else
            write(ERR, "map error\n", 10);
        index++;
        if (index != argc)
            write(OUT, "\n", 1);
        free_grid(grid);
    }
}

/**
 * Handles no arguments as an input, defaulting to
 * the default in.
 *
 * @param grid The grid that will be processed.
 * @param solution Alcohol. Alcohol is always a solution.
 */
void    no_arguments(t_grid *grid, t_solution *solution)
{
    if (parse_grid(IN, grid))
        process_grid(grid, solution);
    else
        write(ERR, "map error\n", 10);
    free_grid(grid);
}

/**
 * Do I really need to explain the main function?
 *
 * @param argc The argument count.
 * @param argv The argument vector.
 * @return The status code in case this program fucks up.
 */
int	main(int argc, char **argv)
{
    t_grid		grid;
    t_solution  solution; // Can also be alcohol. Alcohol is always the solution.

    if (argc < 2)
        no_arguments(&grid, &solution);
    else
        mult_arguments(&grid, &solution, argc, argv);
    return (0);
}