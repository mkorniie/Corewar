/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_labels.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 14:16:06 by mkorniie          #+#    #+#             */
/*   Updated: 2018/07/13 14:16:07 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		ft_findfilesize(void)
{
	t_label		*lbl_tmp;
	t_comline	*cmd_tmp;
	int			res;

	res = 0;
	lbl_tmp = g_file.head;
	while (lbl_tmp)
	{
		cmd_tmp = lbl_tmp->commands_head;
		while (cmd_tmp)
		{
			res += NAME_SIZE + ft_countargsize(lbl_tmp, cmd_tmp);
			cmd_tmp = cmd_tmp->next;
		}
		lbl_tmp = lbl_tmp->next;
	}
	return (res);
}

t_label	*ft_find_label(char *label_name)
{
	t_label *tmp;

	tmp = g_file.head;
	while (tmp)
	{
		if (ft_strequ(label_name, tmp->label_name))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

int		ft_find_label_dst(t_label *st_lbl, t_comline *cmd,
	char *l_name, t_comline *target)
{
	int			res;
	t_label		*lbl_tmp;
	t_comline	*c_tmp;
	t_label		*target_label;

	res = 0;
	if ((target_label = ft_find_label(l_name)) == NULL)
		ft_exit_number(LABEL_NOT_FOUND, l_name);
	lbl_tmp = st_lbl;
	target = (target == NULL ? target_label->commands_head : target);
	while (lbl_tmp)
	{
		c_tmp = (lbl_tmp == st_lbl && cmd != 0) ? cmd : lbl_tmp->commands_head;
		if ((lbl_tmp == target_label) && (lbl_tmp->commands_head == NULL))
			return (res);
		while (c_tmp)
		{
			if (c_tmp == target)
				return (res);
			res += NAME_SIZE + ft_countargsize(lbl_tmp, c_tmp);
			c_tmp = c_tmp->next;
		}
		lbl_tmp = lbl_tmp->next;
	}
	return (-1 * ft_find_label_dst(target_label, 0, st_lbl->label_name, cmd));
}

int		ft_count_label(t_label *st_label, t_comline *cmd, int index)
{
	int max;
	int dst;
	int res;

	dst = ft_find_label_dst(st_label, cmd, cmd->args[index]->char_value, 0);
	if (dst < 0)
	{
		max = 0xFFFF;
		res = max + dst + 1;
	}
	else
		res = dst;
	return (res);
}
