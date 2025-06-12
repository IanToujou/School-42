/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 13:36:29 by ibour             #+#    #+#             */
/*   Updated: 2025/06/12 13:43:27 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H

# define ERROR_H

# define ERR_NONE 0
# define ERR_UNKNOWN 1
# define ERR_MALLOC 2

void	error_throw(int error);

#endif
