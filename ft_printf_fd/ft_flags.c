/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 11:32:10 by mkorniie          #+#    #+#             */
/*   Updated: 2018/02/05 11:32:14 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_zero(char *res, int wp[3], char x)
{
	size_t	len;
	int		f;

	if (res == NULL || wp[0] == -1)
		return (res);
	if (wp[1] != -1 && ft_strchr("diouxX", x) != NULL)
		return (res);
	len = ft_strlen(res);
	if ((unsigned long)wp[0] <= len)
		return (res);
	len = wp[0] - wp[2] - len + 1;
	if (x == 'p')
		res = ft_strdupfreearg(res + 2, res);
	f = (res[0] == '-' ? 1 : 0);
	wp[2] = (len - 1) * (-1);
	if (f == 1)
		res = ft_strdupfreearg(res + 1, res);
	while (--len > 0)
		res = ft_strjoinfree("0", res, 2);
	if (f == 1)
		res = ft_strjoinfree("-", res, 2);
	if (x == 'p')
		res = ft_strjoinfree("0x", res, 2);
	return (res);
}

char	*ft_hash(char *res, int wp[3], char x)
{
	int		adj;

	adj = (wp[2] < 0 ? wp[2] * (-1) : 0);
	if (x == 'o' || x == 'O')
	{
		if (ft_strlen(res) == 0 || res[adj] != '0')
		{
			res = ft_strjoinfree("0", res, 2);
		}
	}
	else if (x == 'x' || x == 'X')
	{
		if (ft_strlen(res) == 0)
			return (res);
		if (ft_atoi(res) != 0)
		{
			res = ft_strjoinfree((x == 'x' ? "0x" : "0X"), res, 2);
		}
	}
	return (res);
}

char	*ft_space(char *res, int wp[3], char x)
{
	int		adj;

	adj = (wp[2] < 0 ? wp[2] * (-1) : 0);
	if (res == NULL || ft_strchr("aAdeEfFgGi", x) == NULL)
		return (res);
	if (res[0] != '-')
		res = ft_strjoinfree(" ", res, 2);
	return (res);
}

char	*ft_plus(char *res, int wp[3], char x)
{
	char	*temp;
	int		adj;

	adj = (wp[2] < 0 ? wp[2] * (-1) : 0);
	if (res == NULL || ft_strchr("aAdeEfFgGi", x) == NULL)
		return (res);
	if (res[0] != '-')
		res = ft_strjoinfree("+", res, 2);
	return (res);
}

char	*ft_leftadj(char *res, int wp[3], char x)
{
	size_t len;

	if (res == NULL || x == 'n' || wp[0] == -1)
	{
		return (res);
	}
	len = ft_strlen(res);
	if ((unsigned long)wp[0] > len)
		len = wp[0] - len + 1;
	else
		return (res);
	while (--len > 0)
	{
		res = ft_strjoinfree(res, " ", 1);
	}
	return (res);
}
