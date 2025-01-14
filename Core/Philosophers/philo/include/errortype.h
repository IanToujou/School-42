/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errortype.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 21:12:16 by ibour             #+#    #+#             */
/*   Updated: 2025/01/14 17:04:51 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERRORTYPE_H

# define ERRORTYPE_H

# define ERROR_UNKNOWN 0
# define ERROR_UNKNOWN_MSG "Unknown error."

# define ERROR_SYNTAX 1
# define ERROR_SYNTAX_MSG "Syntax error. Usage: ./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [<number_of_times_each_philosopher_must_eat>]"

# define ERROR_SYNTAX_NUM 2
# define ERROR_SYNTAX_NUM_MSG "Syntax error. All the arguments need to be valid integer or long numbers."

# define ERROR_SYNTAX_LIMIT 3
# define ERROR_SYNTAX_LIMIT_MSG "Syntax error. All the arguments need to be within the bounds of a long."

# define ERROR_MALLOC 4
# define ERROR_MALLOC_MSG "Memory allocation error."

# define ERROR_INIT_DATA 5
# define ERROR_INIT_DATA_MSG "Data initialization failed."

#endif
