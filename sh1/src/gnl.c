/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vtarreau <vtarreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 12:12:38 by vtarreau          #+#    #+#             */
/*   Updated: 2015/02/13 12:12:55 by vtarreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static t_fd_list	*ft_get_buffer(int const fd)
{
	static t_fd_list	*lst = NULL;
	t_fd_list			*tmp;
	t_fd_list			*tmp2;

	tmp = lst;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp = tmp->next;
	}
	tmp = (t_fd_list*)ft_memalloc(sizeof(t_fd_list));
	if (!tmp)
		return (NULL);
	if (!(tmp->buffer = (char*)ft_memalloc(sizeof(char) * (BUFF_SIZE + 1))))
		return (NULL);
	tmp->next = NULL;
	tmp->fd = fd;
	if (!lst)
		return ((lst = tmp));
	tmp2 = lst;
	while (tmp2->next)
		tmp2 = tmp2->next;
	tmp2->next = tmp;
	return (tmp);
}

static void			ft_resize_buff(char **buffer, int n)
{
	int	i;

	i = 0;
	while (i < BUFF_SIZE)
	{
		if (i + n < BUFF_SIZE)
			(*buffer)[i] = (*buffer)[i + n + 1];
		else
			(*buffer)[i] = '\0';
		++i;
	}
}

static int			ft_locate_eol(char *line)
{
	int	len;

	len = -1;
	while (line[++len] != '\n' && line[len] != '\0')
		;
	return (len);
}

static int			ft_addbuffer(char **line, char **buffer, int n, int fd)
{
	int		lline;
	char	*tmp;
	int		n_save;

	n_save = n;
	lline = ft_get_buffer(fd)->lline;
	tmp = *line;
	(*line) = (char*)ft_memalloc(sizeof(char) * (lline + n + 1));
	ft_get_buffer(fd)->lline = lline + n;
	if (!*line)
		return (-1);
	lline = -1;
	while (++lline > -1 && tmp && tmp[lline])
		(*line)[lline] = tmp[lline];
	free(tmp);
	while (n--)
		(*line)[lline + n] = (*buffer)[n];
	ft_resize_buff(buffer, n_save);
	return (0);
}

int					get_next_line(int const fd, char **line)
{
	char				**buf;
	int					len;
	int					f;

	if (!(buf = &(ft_get_buffer(fd)->buffer)) || !BUFF_SIZE || !line)
		return (-1);
	ft_get_buffer(fd)->lline = 0;
	*line = NULL;
	while (f != -1)
	{
		if (!(*buf)[0] && (len = read(fd, *buf, BUFF_SIZE)) != BUFF_SIZE)
		{
			if (len == -1)
				return (-1);
			f = (ft_strchr(*buf, '\n') != NULL);
			len = ft_locate_eol(*buf);
			f = (ft_addbuffer(line, buf, len, fd) == -1 ? -1 : f);
			return ((f == -1 ? -1 : f || ft_strlen(*buf) || ft_strlen(*line)));
		}
		if ((len = ft_locate_eol(*buf)) != -2 && (*buf)[len] == '\0')
			f = ft_addbuffer(line, buf, len, fd);
		else if ((*buf)[len] == '\n')
			return (1 + (f = ft_addbuffer(line, buf, len, fd)));
	}
	return (-1);
}
