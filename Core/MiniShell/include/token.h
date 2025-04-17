/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 00:31:42 by ibour             #+#    #+#             */
/*   Updated: 2025/04/18 00:32:39 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H

# define TOKEN_H

# define TOKEN_CMD 1
# define TOKEN_ARG 2
# define TOKEN_TRUNC 3
# define TOKEN_APPEND 4
# define TOKEN_INPUT 5
# define TOKEN_DOBINP 6
# define TOKEN_PIPE 7

typedef struct s_token
{
	char			*str;
	int				type;
	struct s_token	*prev;
	struct s_token	*next;
}	t_token;

#endif
