/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 08:57:18 by ibour             #+#    #+#             */
/*   Updated: 2024/07/20 08:57:20 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

void	ft_putchar(char c);

void	ft_putstring(char* str);

void	handle_error();

bool check_input_format(char *input);

bool check_input_format_recursive(char *input, int i);

void print_grid_rec(int grid[4][4], int i, int j)
{
    char c;
    if (i < 4)
    {
        if (j < 4)
        {
            c = grid[i][j] + '0';
            ft_putchar(c);
            if (j < 4 - 1)
                ft_putchar(' ');
            print_grid_rec(grid, i, j + 1);
        }
        else
        {
            ft_putchar('\n');
            print_grid_rec(grid, i + 1, 0);
        }
    }
}

void print_grid(int grid[4][4])
{
    print_grid_rec(grid, 0, 0);
}

// Función para verificar si el número se puede colocar en la posición
int is_safe_rec(int grid[4][4], int row, int col, int num, int x)
{
    if (x < 4)
    {
        if (grid[row][x] == num || grid[x][col] == num)
        {
            return 0;
        }
        return is_safe_rec(grid, row, col, num, x + 1);
    }
    return 1;
}

int is_safe(int grid[4][4], int row, int col, int num)
{
    return is_safe_rec(grid, row, col, num, 0);
}

// Función para contar los edificios visibles desde una dirección
int count_visible_rec(int *line, int size, int i, int max_height, int count)
{
    if (i < size)
    {
        if (line[i] > max_height)
        {
            max_height = line[i];
            count++;
        }
        return count_visible_rec(line, size, i + 1, max_height, count);
    }
    return count;
}

int count_visible(int *line, int size)
{
    return count_visible_rec(line, size, 0, 0, 0);
}

// Función para copiar una columna de la cuadrícula a un array
void copy_col_rec(int grid[4][4], int col, int line[4], int i)
{
    if (i < 4)
    {
        line[i] = grid[i][col];
        copy_col_rec(grid, col, line, i + 1);
    }
}

// Función para copiar una fila de la cuadrícula a un array
void copy_row_rec(int grid[4][4], int row, int line[4], int i)
{
    if (i < 4)
    {
        line[i] = grid[row][i];
        copy_row_rec(grid, row, line, i + 1);
    }
}

// Función para copiar una columna invertida de la cuadrícula a un array
void copy_col_rev_rec(int grid[4][4], int col, int line[4], int i)
{
    if (i < 4)
    {
        line[i] = grid[4 - i - 1][col];
        copy_col_rev_rec(grid, col, line, i + 1);
    }
}

// Función para copiar una fila invertida de la cuadrícula a un array
void copy_row_rev_rec(int grid[4][4], int row, int line[4], int i)
{
    if (i < 4)
    {
        line[i] = grid[row][4 - i - 1];
        copy_row_rev_rec(grid, row, line, i + 1);
    }
}

// Función para verificar las restricciones de visibilidad
int check_visibility_rec(int grid[4][4], int clues[4][4], int i)
{
    int line[4];
    int visible_count;

    if (i < 4)
    {
        // Verificar pista superior
        copy_col_rec(grid, i, line, 0);
        visible_count = count_visible(line, 4);
        if (clues[0][i] != 0 && visible_count != clues[0][i])
            return 0;

        // Verificar pista inferior
        copy_col_rev_rec(grid, i, line, 0);
        visible_count = count_visible(line, 4);
        if (clues[1][i] != 0 && visible_count != clues[1][i])
            return 0;

        // Verificar pista izquierda
        copy_row_rec(grid, i, line, 0);
        visible_count = count_visible(line, 4);
        if (clues[2][i] != 0 && visible_count != clues[2][i])
            return 0;

        // Verificar pista derecha
        copy_row_rev_rec(grid, i, line, 0);
        visible_count = count_visible(line, 4);
        if (clues[3][i] != 0 && visible_count != clues[3][i])
            return 0;

        return check_visibility_rec(grid, clues, i + 1);
    }
    return 1;
}

int check_visibility(int grid[4][4], int clues[4][4])
{
    return check_visibility_rec(grid, clues, 0);
}

// Función para resolver la cuadrícula usando backtracking
int solve_grid_rec(int grid[4][4], int clues[4][4], int row, int col, int num)
{
    if (row == 4)
    {
        return check_visibility(grid, clues);
    }
    if (col == 4)
    {
        return solve_grid_rec(grid, clues, row + 1, 0, 1);
    }
    if (grid[row][col] != 0)
    {
        return solve_grid_rec(grid, clues, row, col + 1, 1);
    }
    if (num > 4)
    {
        return 0;
    }
    if (is_safe(grid, row, col, num))
    {
        grid[row][col] = num;
        if (solve_grid_rec(grid, clues, row, col + 1, 1))
        {
            return 1;
        }
        grid[row][col] = 0;
    }
    return solve_grid_rec(grid, clues, row, col, num + 1);
}

int solve_grid(int grid[4][4], int clues[4][4], int row, int col)
{
    return solve_grid_rec(grid, clues, row, col, 1);
}

int parse_clues_rec(char *input, int clues[4][4], int i, int j, int index)
{
    if (i < 4)
    {
        if (j < 4)
        {
            if (input[index] < '1' || input[index] > '4')
                return 0;
            clues[i][j] = input[index] - '0';
            return parse_clues_rec(input, clues, i, j + 1, index + 2);
        }
        return parse_clues_rec(input, clues, i + 1, 0, index);
    }
    return 1;
}

int parse_clues(char *input, int clues[4][4])
{
    return parse_clues_rec(input, clues, 0, 0, 0);
}

int	main(int argc, char **argv)
{
	int grid[4][4] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
	if (argc != 2)
	{
		handle_error();
		return (0);
	}
	if (!check_input_format(argv[1])) {
		handle_error();
		return (0);
	}
	int clues[4][4];
	if (!parse_clues(argv[1], clues))
	{
		handle_error();
		return (0);
	}

	if (solve_grid(grid, clues, 0, 0))
	{
		print_grid(grid);
	}
	else
		handle_error();
	return 0;
}
