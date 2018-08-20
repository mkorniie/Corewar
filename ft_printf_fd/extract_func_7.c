/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_func_7.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 11:29:57 by mkorniie          #+#    #+#             */
/*   Updated: 2018/02/05 11:30:02 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_lxcnv(va_list ap)
{
	unsigned long	temp;

	temp = va_arg(ap, long);
	return (ft_ubase(temp, 16, "0123456789abcdef"));
}

char	*ft_lxccnv(va_list ap)
{
	unsigned long	temp;

	temp = va_arg(ap, long);
	return (ft_ubase(temp, 16, "0123456789ABCDEF"));
}
