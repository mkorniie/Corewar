/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 10:59:04 by mkorniie          #+#    #+#             */
/*   Updated: 2017/11/13 10:59:06 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list *sw;

	if (lst == NULL || f == NULL)
		return ;
	f(lst);
	if (lst->next != NULL)
	{
		sw = lst->next;
		while ((lst->next) != NULL)
		{
			f(sw);
			lst = sw;
			sw = lst->next;
		}
	}
}
