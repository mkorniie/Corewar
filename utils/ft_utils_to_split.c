/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_to_split.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 20:23:28 by mkorniie          #+#    #+#             */
/*   Updated: 2018/07/06 20:23:29 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../asm.h"

int			ft_command_index(char *chunk)
{
	int i;

	i = -1;
	while (g_op_tab[++i].name != NULL)
		if (ft_strequ(g_op_tab[i].name, chunk))
			return (i);
	return (-1);
}

char		*ft_new_line_with_separators(void)
{
	char *res;

	res = ft_strnew(3);
	res[0] = ' ';
	res[1] = '\t';
	res[2] = SEPARATOR_CHAR;
	return (res);
}

t_comline	*ft_newcomline(void)
{
	t_comline *new;

	new = (t_comline*)malloc(sizeof(t_comline));
	new->line = NULL;
	new->command = NULL;
	new->args_byte = 0x0;
	new->args[0] = NULL;
	new->args[1] = NULL;
	new->args[2] = NULL;
	new->next = NULL;
	return (new);
}

void		ft_addtocomltail(t_comline *new)
{
	t_comline *tmp;

	if ((g_curr_label->commands_head) == NULL)
		g_curr_label->commands_head = new;
	else
	{
		tmp = g_curr_label->commands_head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}
