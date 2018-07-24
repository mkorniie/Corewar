/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 10:58:53 by mkorniie          #+#    #+#             */
/*   Updated: 2017/11/13 10:58:56 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_nfree(t_list *start)
{
	t_list *next;

	while (start != NULL)
	{
		next = start->next;
		ft_memdel(start->content);
		free(start);
		start = next;
	}
	return (NULL);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *sw;
	t_list *new;
	t_list *holder;

	if (lst == NULL || f == NULL)
		return (NULL);
	new = ft_lstnew(lst->content, lst->content_size);
	if (new == NULL)
		return (NULL);
	new = f(new);
	holder = new;
	lst = lst->next;
	while (lst != NULL)
	{
		sw = f(lst);
		sw = ft_lstnew(sw->content, sw->content_size);
		if (sw == NULL)
			return (ft_nfree(holder));
		new->next = sw;
		if (lst->next == NULL)
			return (holder);
		lst = lst->next;
		new = sw;
	}
	return (holder);
}
