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

char *ft_quotetrim(char *raw_name, t_declare *glob_struct)
{
	char	*res;
	char	*quote_char;
	int		line_len;

	res = ft_strchr(raw_name, '"') + 1;
	if ((quote_char = ft_strchr(res, '"')) != NULL)
	{
		glob_struct->line_end = 1;
		if (quote_char[1] != '\0')
		{
			ft_printf("Some syntax error in your bot name. You've put something after quotes!\n");
			ft_exit();
		}
		line_len = ft_strlen(res);
		res = ft_strsub(raw_name, 1, line_len - 1);
		ft_printf("Yaaay! The new name (the whole) is %s\n", res);
		return (res);
	}
	glob_struct->line_end = 0;
	res = ft_strdup(res);
	ft_printf("Yaaay! The new name (a part) is %s\n", res);
	return (res);
}

void	ft_checkfirstline(char *line, t_declare *glob_struct)
{
	char **split;
	char *tmp;
	char *name;
	int len;

	split = ft_sepsplit(line, " \t");
	if (ft_chararrlen(split) == 1)
	{
		ft_printf("Some error when no name string\n");
		ft_exit();
	}
	if (ft_strequ(split[0], glob_struct->cmd_string))
	{
		if (split[1][0] == '\"')
		{
			tmp = ft_strstr(line, split[1]);
			len = ft_strlen(line) - ft_strlen(tmp) - 1;
			name = ft_quotetrim(line + len + 1, glob_struct);
			glob_struct->line = ft_strjoinfreefirst(glob_struct->line, name);
			ft_printf("Now g_file.%s is %s\n", glob_struct->name, glob_struct->line);
		}
		else
		{
			ft_printf("Some error when name is not in quotes or whatever\n");
			ft_exit();
		}
	}
	else
	{
		ft_printf("Some error when no name tag\n");
		ft_exit();
	}
}

char	*ft_addline(char *line, t_declare *glob_struct)
{
	char	*res;
	char	*quote_char;
	int		line_len;

	if ((quote_char = ft_strchr(line, '"')) != NULL)
	{
		glob_struct->line_end = 1;
		if (quote_char[1] != '\0')
		{
			ft_printf("Some syntax error in your bot name. You've put something after quotes!\n");
			ft_exit();
		}
		line_len = ft_strlen(line);
		res = ft_strsub(line, 0, line_len - 1);
		ft_printf("Yaaay! The new name (the whole) is \"%s\"\n", res);
		return (res);
	}
	res = ft_strdup(line);
	ft_printf("Yaaay! The new name (a part) is \"%s\"\n", res);
	return (res);
}

void    ft_lengthcheck(t_declare *glob_struct)
{
	glob_struct->length = ft_strlen(glob_struct->line);
    if (glob_struct->length > glob_struct->max_length)
    {
        ft_printf("Champion %s too long (Max length %d)\n", glob_struct->name, glob_struct->max_length);
        ft_exit();
    }
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
		ft_printf("Now g_file.name is \"%s\"\n", glob_struct->line);
	}
    ft_lengthcheck(glob_struct);
}
