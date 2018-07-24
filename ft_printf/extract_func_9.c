/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_func_9.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 11:30:29 by mkorniie          #+#    #+#             */
/*   Updated: 2018/02/05 11:30:31 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_dssize_tcnv(va_list ap)
{
	ssize_t	temp;

	temp = va_arg(ap, size_t);
	return (ft_litoa(temp));
}

char	*ft_osize_tcnv(va_list ap)
{
	size_t	temp;

	temp = va_arg(ap, size_t);
	return (ft_ubase(temp, 8, "01234567"));
}

char	*ft_usize_tcnv(va_list ap)
{
	size_t	temp;

	temp = va_arg(ap, size_t);
	return (ft_ulitoa(temp));
}

char	*ft_xsize_tcnv(va_list ap)
{
	size_t	temp;

	temp = va_arg(ap, size_t);
	return (ft_ubase(temp, 16, "0123456789abcdef"));
}

char	*ft_xcsize_tcnv(va_list ap)
{
	size_t	temp;

	temp = va_arg(ap, size_t);
	return (ft_ubase(temp, 16, "0123456789ABCDEF"));
}
