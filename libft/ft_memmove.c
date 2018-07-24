/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 20:55:32 by mkorniie          #+#    #+#             */
/*   Updated: 2017/11/02 21:09:29 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t i;

	if (len == 0)
		return (dst);
	if (dst > src)
	{
		i = len;
		while (--i != 0)
			((char*)dst)[i] = ((char*)src)[i];
		((char*)dst)[i] = ((char*)src)[i];
	}
	else
		dst = ft_memcpy(dst, src, len);
	return (dst);
}
