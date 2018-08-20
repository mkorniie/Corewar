/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_argtype.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 16:53:13 by mkorniie          #+#    #+#             */
/*   Updated: 2018/08/20 16:53:15 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_isind(char *arg_line)
{
	t_arg *curr;

	if (arg_line[0] == LABEL_CHAR)
		if (ft_line_consists_of(arg_line + 1, LABEL_CHARS))
		{
			curr = ft_addgarg(arg_line, T_IND);
			curr->char_value = ft_strdup(arg_line + 1);
			curr->val_type = CHAR_TYPE;
			return (T_IND);
		}
	if (ft_ispmnumline(arg_line))
	{
		curr = ft_addgarg(arg_line, T_IND);
		curr->int_value = ft_overflow(arg_line);
		curr->val_type = 0;
		return (T_IND);
	}
	return (0);
}

int		ft_isdir(char *arg_line)
{
	t_arg *curr;

	if ((arg_line[0]) == DIRECT_CHAR)
	{
		if (arg_line[1] == LABEL_CHAR)
			if (ft_line_consists_of(arg_line + 2, LABEL_CHARS))
			{
				curr = ft_addgarg(arg_line, T_DIR);
				curr->char_value = ft_strdup(arg_line + 2);
				curr->val_type = CHAR_TYPE;
				return (T_DIR);
			}
		if (ft_ispmnumline(arg_line + 1))
		{
			curr = ft_addgarg(arg_line, T_DIR);
			curr->int_value = ft_overflow(arg_line + 1);
			curr->val_type = T_IND;
			return (T_DIR);
		}
	}
	return (0);
}

int		ft_isreg(char *arg_line)
{
	int		num;
	t_arg	*curr;

	if (arg_line[0] == 'r')
	{
		if (ft_lineispint(arg_line + 1))
		{
			num = ft_atoi(arg_line + 1);
			if ((num > 0) && (num <= REG_NUMBER))
			{
				curr = ft_addgarg(arg_line, T_REG);
				curr->int_value = num;
				curr->val_type = T_IND;
				return (T_REG);
			}
			else
				ft_exit_number_line(INVAL_REG_NUM, NULL);
		}
		else
			ft_exit_number_line(REG_NUM_NOT_PINT, NULL);
	}
	return (0);
}

int		ft_find_argtype(char *arg_line)
{
	if (ft_isreg(arg_line) != 0)
		return (T_REG);
	else if (ft_isdir(arg_line) != 0)
		return (T_DIR);
	else if (ft_isind(arg_line) != 0)
		return (T_IND);
	ft_exit_number_line(NOT_AN_ARG_ERR, arg_line);
	return (1);
}
