/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 10:57:40 by mkorniie          #+#    #+#             */
/*   Updated: 2017/11/13 11:21:36 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *next;

	if (alst == NULL || del == NULL || *alst == NULL)
		return ;
	next = (*alst)->next;
	while (next != NULL)
	{
		ft_lstdelone(alst, del);
		(*alst) = next;
		next = (*alst)->next;
	}
	ft_lstdelone(alst, del);
}
