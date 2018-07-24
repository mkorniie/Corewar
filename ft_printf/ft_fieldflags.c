/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fieldflags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 11:31:32 by mkorniie          #+#    #+#             */
/*   Updated: 2018/02/05 11:31:34 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_fwidth(char *res, int width, int *flg)
{
	size_t len;

	if (res == NULL || width == -1)
		return (res);
	if (flg[4] == 1)
		return (res);
	len = ft_strlen(res);
	if ((unsigned long)width > len)
		len = width - len + 1;
	else
		return (res);
	while (--len > 0)
		res = ft_strjoinfree(" ", res, 2);
	return (res);
}

char	**ft_fieldflags(char **res, char **flags)
{
	int *flg;
	int i;
	int x;
	int *wp;
	int len;

	i = -1;
	while (++i < g_n_of_f)
		if (flags[i] == NULL || res[i] == NULL)
			res[i] = NULL;
		else
		{
			len = ft_strlen(flags[i]);
			flg = ft_findflag(flags[i]);
			wp = ft_widthpres(flags[i], flg[0]);
			wp[2] = ft_changewidth(flg, res[i], flags[i][len - 1]);
			x = -1;
			res[i] = ft_presicion(res[i], wp[1], flags[i][len - 1]);
			while (++x < 5)
				if (flg[x] != -1)
					res[i] = g_ft_flags[x](res[i], wp, flags[i][len - 1]);
			res[i] = ft_fwidth(res[i], wp[0], flg);
			ft_freetwo(flg, wp);
		}
	return (res);
}
