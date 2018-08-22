/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_assembler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 16:22:42 by mkorniie          #+#    #+#             */
/*   Updated: 2018/08/20 16:22:44 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_changestatus(int index, int *status)
{
	if (index == 0)
	{
		if (*status < 1)
		{
			if (*status == -1)
				*status = 0;
		}
		else
			ft_exit_number_line(NAME_ERR, NULL);
	}
	else
	{
		if (*status == (index - 1))
			*status = index;
		else if (*status != index)
			ft_exit_number_line(ORDER_ERR, (index == 1 ? "comment" : "order"));
	}
}

int		ft_empty_or_comment(char *line)
{
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == COMMENT_CHAR)
			return (TRUE);
		else if ((line[i] == ' ') || (line[i] == '\t'))
			i++;
		else
			return (FALSE);
	}
	return (TRUE);
}

char	*ft_deletecomment(char *line)
{
	int		len;
	char	*comm_start;
	char	*tmp;

	if ((comm_start = ft_strchr(line, COMMENT_CHAR)) != NULL)
	{
		tmp = line;
		len = ft_strlen(line) - ft_strlen(comm_start);
		line = ft_strsub(line, 0, len);
		free(tmp);
	}
	return (line);
}

int		ft_get_next_line(int fd, char **line)
{
	int		res;
	char	*tmp;

	if (g_line_counter > 0)
		free(*line);
	res = get_next_line(fd, line);
	if (res > 0)
	{
		g_line_counter++;
		tmp = ft_strjoinfreefirst(g_file.content, *line);
		g_file.content = ft_strjoinfreefirst(tmp, "\n");
		*line = ft_deletecomment(*line);
	}
	return (res);
}

void	ft_to_assembler(char *filename)
{
	char	*line;
	int		status;
	int		fd;

	status = -1;
	fd = ft_open(filename);
	while (ft_get_next_line(fd, &line) > 0)
	{
		if (ft_strstr(line, NAME_CMD_STRING) || g_file.name->line_end == 0)
		{
			ft_changestatus(0, &status);
			ft_addsequence(line, g_file.name);
		}
		else if (ft_strstr(line, C_S) || g_file.comment->line_end == 0)
		{
			ft_changestatus(1, &status);
			ft_addsequence(line, g_file.comment);
		}
		else if (!ft_empty_or_comment(line))
		{
			ft_changestatus(2, &status);
			ft_addcommands(line);
		}
	}
}
