/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_func_4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/05 11:29:10 by mkorniie          #+#    #+#             */
/*   Updated: 2018/02/05 11:29:13 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_acnv(va_list ap)
{
	char	*res;
	double	temp;

	temp = va_arg(ap, double);
	res = ft_strdup("[double]]");
	return (res);
}

char	*ft_accnv(va_list ap)
{
	char	*res;
	double	temp;

	temp = va_arg(ap, double);
	res = ft_strdup("[double]");
	return (res);
}

char	*ft_ncnv(va_list ap)
{
	char	*res;
	int		*temp;

	temp = va_arg(ap, int*);
	res = ft_strdup("[int*]");
	return (res);
}
