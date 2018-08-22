/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_presicion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 19:07:59 by mkorniie          #+#    #+#             */
/*   Updated: 2018/03/21 19:08:01 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_scunicode(char *res, int pres)
{
	int i;
	int sum;

	i = 0;
	sum = 0;
	while (sum <= pres)
	{
		sum += g_unistrings[g_curr][i];
		i++;
	}
	sum -= g_unistrings[g_curr][i - 1];
	return (ft_strndupfree(res, sum));
}

char	*ft_sgpconvs(char *res, int pres, char x, int len)
{
	if (x == 's' || x == 'g' || x == 'G')
		if (pres < len)
			res = ft_strndupfree(res, pres);
	if (x == 'S')
	{
		if (pres < len)
			res = ft_scunicode(res, pres);
		g_curr++;
	}
	if (x == 'p')
		res = ft_strjoinfree("0x", res, 2);
	return (res);
}

char	*ft_apply_pres(char *res, int pres, int len, int sign)
{
	char *temp;
	char *fchar;

	temp = (sign == 1 ? ft_strdup(res + 1) : ft_strdup(res));
	while ((--pres - len + 1) > 0)
		temp = ft_strjoinfree("0", temp, 2);
	if (sign == 1)
	{
		fchar = ft_chartostr(res[0]);
		res = ft_strjoinfree(fchar, temp, 3);
	}
	else
	{
		free(res);
		res = temp;
	}
	return (res);
}

char	*ft_presicion(char *res, int pres, char x)
{
	int		len;
	int		sign;

	if (res == NULL || pres == -1)
		return (res);
	sign = (res[0] == '-' ? 1 : 0);
	len = ft_strlen(res) - sign;
	if (ft_strchr("dioOuxXp", x) != NULL)
	{
		if (x == 'p')
			res = ft_strdupfreearg(res + 2, res);
		if (x == 'p' && pres == 2)
			return (ft_strdupfreearg("0x", res));
		if (pres == 0 && res[0] == '0')
			return (ft_strdupfreearg("", res));
		if (pres > len)
			res = ft_apply_pres(res, pres, len, sign);
	}
	res = ft_sgpconvs(res, pres, x, len);
	return (res);
}
