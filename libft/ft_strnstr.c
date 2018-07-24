/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 21:59:46 by mkorniie          #+#    #+#             */
/*   Updated: 2017/11/09 14:22:50 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*occur;
	size_t	l;

	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	if (len > ft_strlen(haystack))
		len = ft_strlen(haystack);
	if (len == 0 || ft_strlen(needle) > len)
		return (NULL);
	occur = ft_strstr(haystack, needle);
	if (occur == NULL)
		return (NULL);
	l = ft_strlen(haystack) - ft_strlen(occur) + ft_strlen(needle);
	if (l <= len)
		return (occur);
	return (NULL);
}
