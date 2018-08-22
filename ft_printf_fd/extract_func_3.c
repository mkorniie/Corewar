/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_func_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 11:28:53 by mkorniie          #+#    #+#             */
/*   Updated: 2018/02/05 11:28:58 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_eccnv(va_list ap)
{
	char	*res;
	double	temp;

	temp = va_arg(ap, double);
	res = ft_strdup("[double]");
	return (res);
}

char	*ft_fcnv(va_list ap)
{
	char	*res;
	double	temp;

	temp = va_arg(ap, double);
	res = ft_strdup("[double]");
	return (res);
}

char	*ft_fccnv(va_list ap)
{
	char	*res;
	double	temp;

	temp = va_arg(ap, double);
	res = ft_strdup("[double]");
	return (res);
}

char	*ft_gcnv(va_list ap)
{
	char	*res;
	double	temp;

	temp = va_arg(ap, double);
	res = ft_strdup("[double]");
	return (res);
}

char	*ft_gccnv(va_list ap)
{
	char	*res;
	double	temp;

	temp = va_arg(ap, double);
	res = ft_strdup("[double]");
	return (res);
}
