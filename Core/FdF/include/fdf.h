/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 21:12:20 by ibour             #+#    #+#             */
/*   Updated: 2024/12/11 17:39:34 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "errortype.h"

# include "../lib/libft/include/libft.h"
# include "../lib/mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>

# define WINDOW_NAME "FdF"
# define WINDOW_SIZE 900

# define UINT u_int32_t

typedef struct s_map {
	double **array;
}	t_map;

typedef struct s_data {
	t_map	*map;
}	t_data;

void	ft_throw_error(int error);

int	ft_init_data(t_data **data);

#endif
