/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 13:46:34 by ibour             #+#    #+#             */
/*   Updated: 2024/07/25 13:46:36 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TAIL_H
# define FT_TAIL_H

# include <errno.h>
# include <unistd.h>
# include <libgen.h>
# include <fcntl.h>

# define BUFFER_SIZE 4096

# define IN 0
# define OUT 1
# define ERR 2

void	ft_putchar(int fd, char c);
void	ft_putstr(int fd, char *str);
void	ft_putstr_buffer(int fd, char *str, int size);
void	handle_error(char **argv);
int		ft_read(char *path);

#endif