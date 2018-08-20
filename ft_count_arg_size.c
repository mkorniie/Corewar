/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_arg_size.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 16:26:46 by mkorniie          #+#    #+#             */
/*   Updated: 2018/08/20 16:26:50 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_recurs(int *flag, t_label *label, t_comline *command, int i)
{
	(*flag) = 1;
	command->args[i]->int_value = ft_count_label(label, command, i);
	(*flag) = 0;
}

int		ft_countargsize(t_label *label, t_comline *command)
{
	int			res;
	int			i;
	static int	flag;

	res = 0;
	command->command->codage_octal == 1 ? res += CODAGE_SIZE : FALSE;
	i = -1;
	while (++i < command->command->n_of_args)
		if (command->args[i]->arg_type == T_REG)
			res += 1;
		else if (command->args[i]->arg_type == T_DIR)
		{
			res += (command->command->label_size == 0 ? 4 : 2);
			if ((command->args[i]->char_value != NULL) && (flag == 0))
				ft_recurs(&flag, label, command, i);
		}
		else if (command->args[i]->arg_type == T_IND)
		{
			res += 2;
			if ((command->args[i]->char_value != NULL) && (flag == 0))
				ft_recurs(&flag, label, command, i);
		}
	return (res);
}
