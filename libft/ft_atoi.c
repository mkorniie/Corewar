/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:07:25 by mkorniie          #+#    #+#             */
/*   Updated: 2017/11/16 15:07:27 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

int			ft_atoi(const char *str)
{
	int i[4];

	i[0] = -1;
	i[1] = 1;
	i[3] = 0;
	while (ft_isdigit(str[++i[0]]) != 1)
	{
		if (ft_iswsp(str[i[0]]) == 0)
		{
			if (str[i[0]] == '-' || str[i[0]] == '+')
			{
				if (ft_isdigit(str[i[0] + 1]) != 1)
					return (0);
				i[1] = (str[i[0]] == '-' ? -1 : 1);
			}
			else
				return (0);
		}
	}
	i[2] = ft_numsize((char*)(str + i[0]), i[1]);
	while (ft_isdigit(str[i[0]]) == 1 && i[2] == 1)
		i[3] = (i[3] * 10) + (i[1]) * (str[i[0]++] - 48);
	return (i[2] == 1 ? i[3] : i[2]);
}
