/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 20:01:46 by ibour             #+#    #+#             */
/*   Updated: 2024/11/04 13:14:03 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H

# define MINITALK_H

# ifndef SIGNAL_ONE
#  define SIGNAL_ONE SIGUSR2
# endif

# ifndef SIGNAL_ZERO
#  define SIGNAL_ZERO SIGUSR1
# endif

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>

# include "../lib/libft/include/libft.h"

#endif
