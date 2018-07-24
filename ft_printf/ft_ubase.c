/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ubase.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 11:33:52 by mkorniie          #+#    #+#             */
/*   Updated: 2018/02/05 11:33:54 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

uintmax_t	ft_powlen(uintmax_t src, uintmax_t len)
{
	uintmax_t i;

	i = 0;
	if (src == 0)
		return (1);
	if (src >= 10000000000000000000LU)
		return (ft_powlen(src / len, len) + 1);
	while ((src / ft_powl(len, i)) > (len - 1))
	{
		i++;
	}
	return (i + 1);
}

char		*ft_ubase(uintmax_t src, uintmax_t len, const char *pattern)
{
	char		*res;
	uintmax_t	plen;
	uintmax_t	size;
	uintmax_t	i;
	uintmax_t	temp;

	plen = ft_strlen(pattern);
	if (plen != len)
		return (NULL);
	i = -1;
	size = ft_powlen(src, len);
	if (!(res = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	res[size] = '\0';
	while (++i < size)
	{
		temp = src / ft_powl(len, size - i - 1);
		res[i] = pattern[temp];
		src -= temp * ft_powl(len, size - i - 1);
	}
	return (res);
}
