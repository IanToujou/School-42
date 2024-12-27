/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util_gnl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibour <support@toujoustudios.net>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 05:06:25 by ibour             #+#    #+#             */
/*   Updated: 2024/12/27 05:16:35 by ibour            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/fdf.h"

static char	*ft_strchrs(const char *s, int c)
{
	if (!s)
		return (NULL);
	return (ft_strchr(s, c));
}

static char	*ft_strsubchr(const char *s, char c)
{
	char	*ptr;

	if (!(ptr = ft_strchr(s, c)))
		return (NULL);
	return (ft_substr(s, 0, ptr - s));
}

static t_file	*new_file(const int fd)
{
	t_file *new;

	new = (t_file *) malloc(sizeof(t_file));
	if (new)
	{
		new->fd = fd;
		new->str = NULL;
	}
	return (new);
}

static t_file	*get_file(const int fd, t_file **head)
{
	t_file *lst;

	if (!(*head))
		return (*head = new_file(fd));
	lst = *head;
	while (lst->next && lst->fd != fd)
		lst = lst->next;
	return ((lst->fd == fd) ? lst : (lst->next = new_file(fd)));
}

static int		str_divide(char **str, char **line)
{
	char	*new;
	char	*div;

	if (!(*line = ft_strsubchr(*str, '\n')))
		return (-1);
	div = ft_strchrs(*str, '\n');
	div++;
	if (!ft_strlen(div))
	{
		free(*str);
		*str = NULL;
		return (1);
	}
	new = ft_strdup(div);
	free(*str);
	*str = new;
	return ((new) ? 1 : -1);
}

int	ft_util_gnl(const int fd, char **line)
{
	static t_file	*head = NULL;
	t_file			*f;
	char			buff[BUFFER_SIZE + 1];
	ssize_t			size;
	char			*tmp;

	if (fd < 0 || !line || read(fd, buff, 0) < 0 || !(f = get_file(fd, &head)))
		return (-1);
	while (!ft_strchrs(f->str, '\n'))
	{
		size = read(fd, buff, BUFFER_SIZE);
		if (!size)
		{
			if (!(*line = f->str))
				return (0);
			f->str = NULL;
			return (1);
		}
		buff[size] = '\0';
		tmp = f->str;
		f->str = ft_strjoin(f->str, buff);
		free(tmp);
		if (!f->str)
			return (-1);
	}
	return (str_divide(&(f->str), line));
}