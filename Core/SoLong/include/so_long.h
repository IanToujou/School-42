/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 12:56:12 by ibour             #+#    #+#             */
/*   Updated: 2024/11/06 13:18:28 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

# include <stdlib.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../lib/mlx/mlx.h"
# include "../lib/libft/include/libft.h"

typedef struct s_mlx_data {
	void	*data;
	void	*window;
	void	*textures[5];
	void	*map;
}	t_mlx_data;

#endif