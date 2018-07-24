/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validflag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 14:35:31 by mkorniie          #+#    #+#             */
/*   Updated: 2018/03/18 14:35:39 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_isvalid(char x)
{
	char	*all;
	int		i;

	all = "sSpdDioOuUxXcCeEfFgGaAn%hljz#0-+ 123456789.";
	i = -1;
	while (all[++i] != '\0')
		if (x == all[i])
			return (i);
	return (-1);
}

int		ft_isspecifier(char x)
{
	char	*all;
	int		i;

	all = "sSpdDioOuUxXcCeEfFgGaAn%";
	i = -1;
	while (all[++i] != '\0')
		if (x == all[i])
			return (i);
	return (-1);
}

char	*ft_invalidconv(int i, char *temp)
{
	char	*res;
	int		*wp;
	int		zeroflag;

	if (i > 1)
	{
		res = ft_strndup(temp, i + 1);
		zeroflag = ft_isflag(res, '0');
		wp = ft_widthpres(res, zeroflag);
		if (wp[0] > 1)
		{
			res = ft_strjoinfree(res, "^", 1);
			free(wp);
			return (res);
		}
		free(wp);
	}
	return (NULL);
}

char	*ft_validflag(char *temp)
{
	int		i;
	int		val_index;

	i = 0;
	if (temp == NULL || ft_strlen(temp) == 1)
		return (NULL);
	while (temp[++i] != '\0')
		if ((val_index = ft_isvalid(temp[i])) == -1)
			return (ft_invalidconv(i, temp));
		else if (val_index < 24)
			return (ft_strndup(temp, i + 1));
	return (NULL);
}
