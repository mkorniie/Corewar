/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 16:13:32 by mkorniie          #+#    #+#             */
/*   Updated: 2017/10/27 18:27:00 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		root(int nb)
{
	int max;
	int min;

	max = 46340;
	min = 0;
	while (max != (min + 1))
	{
		if ((((max + min) / 2) * ((max + min) / 2)) == nb)
			return ((max + min) / 2);
		if ((((max + min) / 2) * ((max + min) / 2)) > nb)
			max = (max + min) / 2;
		else
			min = (max + min) / 2;
	}
	return (0);
}

int				ft_sqrt(int nb)
{
	if (nb <= 0 || nb > 2147395600)
		return (0);
	if (nb == 1)
		return (1);
	if (nb == 2147395600)
		return (46340);
	return (root(nb));
}
