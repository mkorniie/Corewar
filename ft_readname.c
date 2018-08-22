/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readname.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 17:37:07 by mkorniie          #+#    #+#             */
/*   Updated: 2018/07/04 17:37:09 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*ft_quotetrim(char *raw_name, t_declare *glob_struct)
{
	char	*res;
	char	*quote_char;
	int		line_len;

	res = ft_strchr(raw_name, '"') + 1;
	if ((quote_char = ft_strchr(res, '"')) != NULL)
	{
		glob_struct->line_end = 1;
		if (quote_char[1] != '\0')
			ft_exit_number_line(BOT_NAME_ERR, NULL);
		line_len = ft_strlen(res);
		res = ft_strsub(raw_name, 1, line_len - 1);
		return (res);
	}
	glob_struct->line_end = 0;
	res = ft_strdup(res);
	return (res);
}

void	ft_checkfirstline(char *line, t_declare *glob_struct)
{
	char	**split;
	char	*tmp;
	char	*name;
	int		len;

	split = ft_sepsplit(line, " \t");
	if (ft_chararrlen(split) == 1)
		ft_exit_number_line(NO_NAME, NULL);
	if (ft_strequ(split[0], glob_struct->cmd_string))
	{
		if (split[1][0] == '\"')
		{
			tmp = ft_strstr(line, split[1]);
			len = ft_strlen(line) - ft_strlen(tmp) - 1;
			name = ft_quotetrim(line + len + 1, glob_struct);
			glob_struct->line = ft_strjoinfreefirst(glob_struct->line, name);
			free(name);
		}
		else
			ft_exit_number_line(NAME_QUOTE_ERR, NULL);
	}
	else
		ft_exit_number_line(NO_NAME_TAG, line);
	ft_freechararr(split);
}

int		ft_invalidsymbafterquote(char *afterquote)
{
	int i;

	i = 0;
	while (afterquote[i] != '\0')
	{
		if (ft_strchr(" \t", afterquote[i]) == NULL)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

char	*ft_addline(char *line, t_declare *glob_struct)
{
	char	*res;
	char	*quote_char;
	int		line_len;

	if ((quote_char = ft_strchr(line, '"')) != NULL)
	{
		glob_struct->line_end = 1;
		if (ft_invalidsymbafterquote(quote_char + 1))
			ft_exit_number_line(BOT_NAME_ERR, NULL);
		line_len = ft_strlen(line);
		res = ft_strsub(line, 0, line_len - 1);
		return (res);
	}
	res = ft_strdup(line);
	return (res);
}

void	ft_addsequence(char *read_line, t_declare *glob_struct)
{
	char *res;

	if (glob_struct->line_end == -1)
		ft_checkfirstline(read_line, glob_struct);
	else
	{
		res = ft_addline(read_line, glob_struct);
		glob_struct->line = ft_strjoinfreefirst(glob_struct->line, "\n");
		glob_struct->line = ft_strjoinfreefirst(glob_struct->line, res);
		free(res);
	}
	if (ft_strlen(glob_struct->line) > glob_struct->max_length)
		ft_exit_number_line(LONG_NAME_ERR, glob_struct->name);
}
