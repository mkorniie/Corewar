/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readcommands_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 19:11:15 by mkorniie          #+#    #+#             */
/*   Updated: 2018/08/20 19:11:16 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		ft_freegetcmd(char **no_sep_split, char *sepline)
{
	free(sepline);
	ft_freechararr(no_sep_split);
}

int			ft_arg_byte(char **no_sep_split, int op_index, int start)
{
	int i;
	int arg_byte;
	int arg_type;

	i = -1;
	arg_byte = 0;
	while ((++i) < g_op_tab[op_index].n_of_args)
	{
		arg_type = ft_find_argtype(no_sep_split[i + start]);
		if ((arg_type & g_op_tab[op_index].args[i]) != arg_type)
			ft_exit_number_line(ARG_TYPE_ERR, no_sep_split[i + start]);
		else
		{
			if (arg_type == T_IND)
				arg_type = IND_CODE;
			arg_type = arg_type << (6 - (i * 2));
			arg_byte = arg_byte | arg_type;
		}
	}
	return (arg_byte);
}

int			ft_get_cmd_byte(int op_index, char *line, int has_label)
{
	int		arrlen;
	int		args_byte;
	char	**no_sep_split;
	char	*sepline;

	sepline = ft_new_line_with_separators();
	no_sep_split = ft_sepsplit(line, sepline);
	arrlen = ft_chararrlen(no_sep_split);
	arrlen -= (has_label == 1 ? 2 : 1);
	if (arrlen == g_op_tab[op_index].n_of_args)
	{
		args_byte = ft_arg_byte(no_sep_split, op_index, has_label + 1);
		if (args_byte != 0)
		{
			ft_freegetcmd(no_sep_split, sepline);
			return (args_byte);
		}
		else
			ft_exit_number_line(WRONG_ARG_TYPES, line);
	}
	else
		ft_exit_number_line(WRONG_N_OF_ARGS, line);
	ft_freegetcmd(no_sep_split, sepline);
	return (0);
}

void		ft_addarguments(t_comline *current_command)
{
	int len;
	int i;

	len = current_command->command->n_of_args;
	i = 0;
	while (i < len)
	{
		current_command->args[i] = g_arg[i];
		i++;
	}
	free(g_arg);
}

t_comline	*ft_addnewcomline(void)
{
	t_comline *new;

	new = ft_newcomline();
	ft_addtocomltail(new);
	return (new);
}
