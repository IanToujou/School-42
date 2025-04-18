/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 09:33:30 by ibour             #+#    #+#             */
/*   Updated: 2025/04/18 17:17:28 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STATUS_H

# define STATUS_H

# define STATUS_OK 0
# define STATUS_MAIN 1
# define STATUS_MALLOC 2
# define STATUS_WRONG_COMMAND 3
# define STATUS_DUP 10
# define STATUS_FORK 11
# define STATUS_OPEN 12
# define STATUS_CLOSE 13
# define STATUS_EXECVE 20
# define STATUS_PATH 21
# define STATUS_PIPE 22
# define STATUS_EXIT 255

#endif
