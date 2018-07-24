/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_func_0.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 19:03:09 by mkorniie          #+#    #+#             */
/*   Updated: 2018/02/05 11:19:53 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_scnv(va_list ap)
{
	char *res;

	res = va_arg(ap, char*);
	if (res == NULL)
		return (ft_strdup("(null)"));
	if (ft_strlen(res) == 0)
	{
		res = (char*)malloc(sizeof(char) * 1);
		res[0] = '\0';
		return (res);
	}
	return (ft_strdup(res));
}

char	*ft_sccnv(va_list ap)
{
	char	*res;
	wchar_t	*temp;
	int		i;

	if ((temp = va_arg(ap, wchar_t*)) == NULL)
		return (ft_strdup("(null)"));
	if (g_curr != 0)
		g_curr++;
	ft_addustring();
	if (ft_strlen(temp) == 0)
		return (ft_strdup(""));
	res = ft_unicode(temp[0], 1);
	if (g_error == 1)
		return (NULL);
	i = 0;
	while (temp[++i] != '\0')
		res = ft_strjoinfree(res, ft_unicode(temp[i], 1), 3);
	return (res);
}

char	*ft_pcnv(va_list ap)
{
	char	*res;
	size_t	temp;

	temp = va_arg(ap, size_t);
	res = ft_ubase(temp, 16, "0123456789abcdef");
	res = ft_strjoinfree("0x", res, 2);
	return (res);
}

char	*ft_dcnv(va_list ap)
{
	char	*res;
	int		temp;

	temp = va_arg(ap, int);
	res = ft_itoa(temp);
	return (res);
}

char	*ft_dccnv(va_list ap)
{
	char *res;
	long temp;

	temp = va_arg(ap, long);
	res = ft_litoa(temp);
	return (res);
}
