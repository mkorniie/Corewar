/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 13:59:25 by mkorniie          #+#    #+#             */
/*   Updated: 2017/12/19 21:11:39 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_line(char *buf, char **target, char **leftover)
{
	char	*st;
	char	*temp_buf;
	int		len;

	temp_buf = buf;
	if ((st = ft_strstr(temp_buf, "\n")) == NULL)
	{
		*leftover = ft_strdup(temp_buf);
		free(temp_buf);
		return (0);
	}
	*leftover = ft_strdup(st + 1);
	len = ft_strlen(temp_buf) - ft_strlen(st);
	st = ft_strndup(temp_buf, len);
	free(temp_buf);
	*target = st;
	return (1);
}

void	ft_find(int fd, t_list **start, t_list **work)
{
	if (*start == NULL)
	{
		*start = ft_lstnew(0, 0);
		(*start)->content = ft_strnew(0);
		(*start)->content_size = fd;
	}
	*work = *start;
	if ((int)(*work)->content_size != fd)
		while ((*work)->next)
		{
			if ((int)(*work)->content_size == fd)
				break ;
			*work = (*work)->next;
		}
	if ((int)(*work)->content_size != fd)
	{
		(*work)->next = ft_lstnew(0, 0);
		(*work) = (*work)->next;
		(*work)->content = ft_strnew(0);
		(*work)->content_size = fd;
	}
}

int		ft_read(t_list **w, char (*buf)[], char **line)
{
	int rr;

	if ((rr = read((*w)->content_size, buf, BUFF_SIZE)) == 0)
	{
		if (ft_strlen((*w)->content) != 0)
		{
			*line = ft_strdup((*w)->content);
			free((*w)->content);
			(*w)->content = "\0";
			return (1);
		}
		return (0);
	}
	if (rr == -1)
		return (-1);
	(*buf)[rr] = '\0';
	return (2);
}

int		get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	char			*r[2];
	int				rr;
	static t_list	*start;
	t_list			*w;

	if (fd < 0 || line == NULL)
		return (-1);
	ft_find(fd, &start, &w);
	while (1)
	{
		if (ft_strlen(w->content) != 0)
			if (ft_line((char*)w->content, &r[0], (char**)(&w->content)) == 1)
			{
				*line = ft_strdup(r[0]);
				free(r[0]);
				return (1);
			}
		if ((rr = ft_read(&w, &buf, line)) != 2)
			return (rr);
		r[1] = w->content;
		w->content = ft_strjoin(r[1], buf);
		free(r[1]);
	}
	return (1);
}
