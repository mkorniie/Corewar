/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_func_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 11:20:09 by mkorniie          #+#    #+#             */
/*   Updated: 2018/02/05 11:20:27 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_icnv(va_list ap)
{
	char	*res;
	int		temp;

	temp = va_arg(ap, int);
	res = ft_itoa(temp);
	return (res);
}

char	*ft_ocnv(va_list ap)
{
	char			*res;
	unsigned int	temp;

	temp = va_arg(ap, int);
	res = ft_ubase(temp, 8, "01234567");
	return (res);
}

char	*ft_occnv(va_list ap)
{
	char			*res;
	unsigned long	temp;

	temp = va_arg(ap, long);
	res = ft_ubase(temp, 8, "01234567");
	return (res);
}

char	*ft_ucnv(va_list ap)
{
	char			*res;
	unsigned int	temp;

	temp = va_arg(ap, int);
	res = ft_ubase(temp, 10, "0123456789");
	return (res);
}

char	*ft_uccnv(va_list ap)
{
	char			*res;
	unsigned long	temp;

	temp = va_arg(ap, long);
	res = ft_ulitoa(temp);
	return (res);
}
