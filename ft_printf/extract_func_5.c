/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_func_5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 11:29:25 by mkorniie          #+#    #+#             */
/*   Updated: 2018/02/05 11:29:29 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_hhocnv(va_list ap)
{
	char			*res;
	unsigned char	temp;

	temp = va_arg(ap, int);
	res = ft_ubase(temp, 8, "01234567");
	return (res);
}

char	*ft_hhucnv(va_list ap)
{
	char			*res;
	unsigned char	temp;

	temp = va_arg(ap, int);
	res = ft_itoa(temp);
	return (res);
}

char	*ft_hhxcnv(va_list ap)
{
	char			*res;
	unsigned char	temp;

	temp = va_arg(ap, int);
	res = ft_ubase(temp, 16, "0123456789abcdef");
	return (res);
}

char	*ft_hhxccnv(va_list ap)
{
	char			*res;
	unsigned char	temp;

	temp = va_arg(ap, int);
	res = ft_ubase(temp, 16, "0123456789ABCDEF");
	return (res);
}

char	*ft_hhdcnv(va_list ap)
{
	char	*res;
	char	temp;

	temp = va_arg(ap, int);
	res = ft_itoa(temp);
	return (res);
}
