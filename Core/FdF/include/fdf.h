/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 09:33:19 by ibour             #+#    #+#             */
/*   Updated: 2025/07/17 09:38:12 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H
# define WIDTH 1280
# define HEIGHT 720

# include "../lib/libft/include/libft.h"
# include "../lib/mlx/mlx.h"
# include <X11/X.h>

typedef struct s_data {
	void	*mlx_ptr;
	void	*win_ptr;
}	t_data;

void	init_mlx(t_data *data);

#endif