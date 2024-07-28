/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_file.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:06:50 by ibour             #+#    #+#             */
/*   Updated: 2024/07/24 14:06:51 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_FILE_H
# define DISPLAY_FILE_H

# define BUFFER_SIZE 1024

# define MSG_ERR_NAME_MISSING "File name missing.\n"
# define MSG_ERR_TOO_MANY_ARGS "Too many arguments.\n"
# define MSG_ERR_CANNOT_READ "Cannot read file.\n"

# define IN 0
# define OUT 1
# define ERR 2

#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>

void	ft_putchar(int out, char c);
void	ft_putstr(int out, const char *str);

#endif