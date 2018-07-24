/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_func_8.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 11:30:13 by mkorniie          #+#    #+#             */
/*   Updated: 2018/02/05 11:30:16 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_dintmax_tcnv(va_list ap)
{
	intmax_t	temp;

	temp = va_arg(ap, intmax_t);
	return (ft_litoa(temp));
}

char	*ft_ouintmax_tcnv(va_list ap)
{
	uintmax_t	temp;

	temp = va_arg(ap, intmax_t);
	return (ft_ubase(temp, 8, "01234567"));
}

char	*ft_uuintmax_tcnv(va_list ap)
{
	uintmax_t	temp;

	temp = va_arg(ap, intmax_t);
	return (ft_ulitoa(temp));
}

char	*ft_xuintmax_tcnv(va_list ap)
{
	uintmax_t	temp;

	temp = va_arg(ap, intmax_t);
	return (ft_ubase(temp, 16, "0123456789abcdef"));
}

char	*ft_xcuintmax_tcnv(va_list ap)
{
	uintmax_t	temp;

	temp = va_arg(ap, intmax_t);
	return (ft_ubase(temp, 16, "0123456789ABCDEF"));
}
