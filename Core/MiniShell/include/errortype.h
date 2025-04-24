/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errortype.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 21:12:16 by ibour             #+#    #+#             */
/*   Updated: 2025/04/18 17:01:05 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORTYPE_H

# define ERRORTYPE_H

# define ERROR_UNKNOWN 0
# define ERROR_UNKNOWN_MSG "Unknown error."

# define ERROR_SYNTAX 1
# define ERROR_SYNTAX_MSG "./minishell"

# define ERROR_MALLOC 2
# define ERROR_MALLOC_MSG "Memory allocation error."

# define ERROR_INIT_DATA 3
# define ERROR_INIT_DATA_MSG "Data initialization failed."

# define ERROR_INIT_ENV 4
# define ERROR_INIT_ENV_MSG "Environment initialization failed."

# define ERROR_INIT_TEMP 5
# define ERROR_INIT_TEMP_MSG "Temp file initialization failed."

# define ERROR_INIT_STD 6
# define ERROR_INIT_STD_MSG "Standard in-out initialization failed."

# define ERROR_EXIT_STD 7
# define ERROR_EXIT_STD_MSG "Exiting standard in-out failed."

# define ERROR_FORK 8
# define ERROR_FORK_MSG "Failed to fork."

# define ERROR_GETCWD 9
# define ERROR_GETCWD_MSG "Failed to get current working directory."

#endif
