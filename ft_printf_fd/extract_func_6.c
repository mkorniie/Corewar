/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_func_6.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 11:29:41 by mkorniie          #+#    #+#             */
/*   Updated: 2018/02/05 11:29:43 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_hdcnv(va_list ap)
{
	char	*res;
	short	temp;

	temp = va_arg(ap, int);
	res = ft_itoa(temp);
	return (res);
}

char	*ft_hocnv(va_list ap)
{
	char			*res;
	unsigned short	temp;

	temp = va_arg(ap, int);
	res = ft_ubase(temp, 8, "01234567");
	return (res);
}

char	*ft_hucnv(va_list ap)
{
	char			*res;
	unsigned short	temp;

	temp = va_arg(ap, int);
	res = ft_itoa(temp);
	return (res);
}

char	*ft_hxcnv(va_list ap)
{
	char			*res;
	unsigned short	temp;

	temp = va_arg(ap, int);
	res = ft_ubase(temp, 16, "0123456789abcdef");
	return (res);
}

char	*ft_hxccnv(va_list ap)
{
	char			*res;
	unsigned short	temp;

	temp = va_arg(ap, int);
	res = ft_ubase(temp, 16, "0123456789ABCDEF");
	return (res);
}
