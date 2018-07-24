/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 11:04:24 by mkorniie          #+#    #+#             */
/*   Updated: 2017/11/13 11:04:27 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printlst(t_list **alst)
{
	if (alst == NULL || *alst == NULL)
		return ;
	while ((*alst)->next != NULL)
	{
		if ((*alst)->content != NULL)
			ft_putstr((char*)((*alst)->content));
		else
			ft_putstr("NULL");
		ft_putstr("\n");
		alst = &((*alst)->next);
	}
	if ((*alst)->content != NULL)
		ft_putstr((char*)((*alst)->content));
	else
		ft_putstr("NULL");
	ft_putstr("\n");
}
