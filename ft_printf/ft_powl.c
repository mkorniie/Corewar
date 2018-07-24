/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_powl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 11:33:11 by mkorniie          #+#    #+#             */
/*   Updated: 2018/02/05 11:33:13 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

uintmax_t	ft_powl(long num, long deg)
{
	long		i;
	uintmax_t	res;

	i = 0;
	res = 1;
	if (deg == 0)
		return (1);
	while (i < deg)
	{
		res *= num;
		i++;
	}
	return (res);
}
