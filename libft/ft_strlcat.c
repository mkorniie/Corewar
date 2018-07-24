/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 21:28:46 by mkorniie          #+#    #+#             */
/*   Updated: 2017/11/02 21:30:49 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t i;
	size_t size_1;

	size_1 = ft_strlen(dst);
	i = size_1;
	if (dstsize == 0)
		return (size_1);
	while (i < (dstsize - 1))
	{
		dst[i] = src[i - size_1];
		i++;
	}
	if (size_1 < dstsize)
		dst[i] = '\0';
	if (size_1 >= dstsize)
		return (ft_strlen(src) + dstsize);
	if ((ft_strlen(src) + size_1) >= dstsize)
		return (ft_strlen(src) + size_1);
	return (size_1 + ft_strlen(src));
}
