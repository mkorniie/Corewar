/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_latoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 11:19:49 by mkorniie          #+#    #+#             */
/*   Updated: 2018/08/04 11:19:51 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../asm.h"

static int	ft_iswsp(unsigned char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	if (c == '\n' || c == '\v')
		return (1);
	if (c == '\r' || c == '\f')
		return (1);
	return (0);
}

long		ft_latoi(const char *str)
{
	long	result;
	int		z;
	int		has_sign;

	z = -1;
	has_sign = 1;
	result = 0;
	while (ft_isdigit(str[++z]) != 1)
		if (ft_iswsp(str[z]) == 0)
		{
			if (str[z] == '-' || str[z] == '+')
			{
				if (ft_isdigit(str[z + 1]) != 1)
					return (0);
				has_sign = (str[z] == '-' ? -1 : 1);
			}
			else
				return (0);
		}
	if (ft_numsize((char*)(str + z), has_sign) != 1)
		return (0);
	while (ft_isdigit(str[z]) == 1)
		result = (result * 10) + (has_sign) * (str[z++] - 48);
	return (result);
}
