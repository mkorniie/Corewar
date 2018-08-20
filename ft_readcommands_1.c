/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readcommands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 12:54:01 by mkorniie          #+#    #+#             */
/*   Updated: 2018/07/05 12:54:03 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_addcmdline(char **split, char *line)
{
	int			cmd_op_index;
	t_comline	*current_command;
	int			cmd_byte;

	cmd_op_index = ft_command_index(split[g_haslabel]);
	g_arg = ft_newargarray(op_tab[cmd_op_index].n_of_args);
	cmd_byte = ft_get_cmd_byte(cmd_op_index, line, g_haslabel);
	ft_right_seps(line, op_tab[cmd_op_index]);
	current_command = ft_addnewcomline();
	current_command->line = ft_cmdline(line, split[g_haslabel]);
	current_command->args_byte = cmd_byte;
	current_command->command = &(op_tab[cmd_op_index]);
	ft_addarguments(current_command);
}

char	*ft_addcharafter(char *line, int i, char ch)
{
	char			*new_line;
	unsigned int	line_len;

	line_len = ft_strlen(line);
	new_line = ft_strnew(line_len + 1);
	new_line = ft_strncpy(new_line, line, i + 1);
	new_line[i + 1] = ch;
	ft_strcpy(new_line + i + 2, line + i + 1);
	return (new_line);
}

char	*ft_spacebeforedirfree(char *line)
{
	int		i;
	char	*tmp;

	i = -1;
	while (line[++i] != '\0')
	{
		if (line[i] == DIRECT_CHAR && line[i + 1] != '\0')
		{
			if (i > 0 && (!ft_strchr(" \t", line[i - 1])))
			{
				tmp = ft_addcharafter(line, i - 1, ' ');
				free(line);
				return (tmp);
			}
			return (line);
		}
	}
	return (line);
}

char	*ft_spaceafterlabelfree(char *line)
{
	int				start;
	int				i;
	char			*chunk;

	i = -1;
	start = 0;
	while (line[++i] != '\0')
	{
		if (ft_strchr(" \t", line[i]))
			start++;
		if (line[i] == LABEL_CHAR && line[i + 1] != '\0')
		{
			chunk = ft_strsub(line, start, i);
			if (ft_line_consists_of(chunk, LABEL_CHARS) != 0)
				if (!ft_strchr(" \t", line[i + 1]))
				{
					free(chunk);
					return (ft_addcharafter(line, i, ' '));
				}
			free(chunk);
			return (ft_strdup(line));
		}
	}
	return (ft_strdup(line));
}

void	ft_addcommands(char *line)
{
	char	**split;
	t_label	*curr_label;
	char	*work_line;

	work_line = ft_spaceafterlabelfree(line);
	work_line = ft_spacebeforedirfree(work_line);
	split = ft_sepsplit(work_line, " \t");
	if (split == NULL)
		ft_exit_number_line(WRONG_N_OF_ARGS, work_line);
	if ((curr_label = ft_validfirst(split)) != NULL)
	{
		g_curr_label = curr_label;
		if (ft_chararrlen(split) > 1)
			ft_addcmdline(split, work_line);
		ft_freechararr(split);
		free(work_line);
	}
	else
	{
		ft_freechararr(split);
		ft_exit_number_line(INVALID_FIRST_ARG, work_line);
	}
}
