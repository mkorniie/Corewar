/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_labellist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 15:00:06 by mkorniie          #+#    #+#             */
/*   Updated: 2018/07/05 15:00:08 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_label	*ft_newlabel(void)
{
	t_label *res;

	res = (t_label*)malloc(sizeof(t_label));
	res->has_label = -1;
	res->label_name = NULL;
	res->commands_head = NULL;
	res->next = NULL;
    return (res);
}

void	ft_addtotail(t_label *new)
{
	t_label *tmp;

	if ((g_file.head) == NULL)
		g_file.head = new;
	else
	{
		tmp = g_file.head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

t_label * ft_addlabel(char *name)
{
	t_label *new;
	int len;

	new = ft_newlabel();
	new->has_label = (name == NULL? 0 : 1);
	new->label_name = name;
	len = ft_strlen(name);
	if (name != NULL)
		name[len - 1] = '\0';
	ft_addtotail(new);
	return (new);
}