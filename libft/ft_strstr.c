/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 21:43:47 by mkorniie          #+#    #+#             */
/*   Updated: 2017/11/02 21:59:23 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int			i;
	char		*occur;
	int			cmp_1;
	size_t		len;

	i = 0;
	occur = ft_strchr(haystack, needle[0]);
	len = ft_strlen(needle);
	if (occur == NULL || ft_strlen(occur) < len || len > ft_strlen(haystack))
		return (NULL);
	if (len == 0)
		return ((char *)haystack);
	while (occur != NULL)
	{
		cmp_1 = ft_strncmp(occur, needle, len);
		if (cmp_1 == 0)
			return (occur);
		else
		{
			if (occur == '\0')
				break ;
			occur = ft_strchr(occur + 1, needle[0]);
		}
	}
	return (NULL);
}
