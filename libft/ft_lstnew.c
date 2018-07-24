/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 11:00:36 by mkorniie          #+#    #+#             */
/*   Updated: 2017/11/13 11:00:38 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*lst;
	void	*con;

	lst = malloc(sizeof(t_list));
	if (lst == NULL)
		return (NULL);
	if (content == NULL)
	{
		lst->content = NULL;
		lst->content_size = 0;
	}
	else
	{
		con = malloc(sizeof(*content) * (content_size));
		if (con == NULL)
			return (NULL);
		con = ft_memcpy(con, content, content_size);
		lst->content = con;
		lst->content_size = content_size;
	}
	lst->next = NULL;
	return (lst);
}
