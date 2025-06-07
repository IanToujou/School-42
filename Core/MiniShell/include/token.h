/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwelfrin <mwelfrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 00:31:42 by ibour             #+#    #+#             */
/*   Updated: 2025/06/07 15:05:16 by mwelfrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_H

# define TOKEN_H

# include "minishell.h"

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
	t_bool			is_quoted;
	char			quote_type;
	struct s_token	*prev;
	struct s_token	*next;
}					t_token;

#endif