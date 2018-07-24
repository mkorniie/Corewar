/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_func_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 11:26:17 by mkorniie          #+#    #+#             */
/*   Updated: 2018/02/05 11:26:22 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_xcnv(va_list ap)
{
	unsigned int	temp;

	temp = va_arg(ap, unsigned int);
	return (ft_ubase(temp, 16, "0123456789abcdef"));
}

char	*ft_xccnv(va_list ap)
{
	unsigned int	temp;

	temp = va_arg(ap, unsigned int);
	return (ft_ubase(temp, 16, "0123456789ABCDEF"));
}

char	*ft_ccnv(va_list ap)
{
	char temp;

	temp = va_arg(ap, int);
	if (temp == 0)
		return (ft_strdup("zero"));
	else
		return (ft_chartostr(temp));
}

char	*ft_cccnv(va_list ap)
{
	wchar_t	temp;

	temp = va_arg(ap, wchar_t);
	if (temp == 0)
		return (ft_strdup("zero"));
	return (ft_unicode(temp, 0));
}

char	*ft_ecnv(va_list ap)
{
	double	temp;

	temp = va_arg(ap, double);
	return (ft_strdup("[double]"));
}
