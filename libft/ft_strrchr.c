/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 21:36:57 by mkorniie          #+#    #+#             */
/*   Updated: 2017/11/02 21:42:45 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*holder;
	int		i;

	i = 0;
	holder = 0;
	if (c == 0)
		return ((char*)(s + ft_strlen(s)));
	while (ft_strchr(s, c) != 0)
	{
		holder = ft_strchr(s, c);
		if (c != '\0')
			s = holder + 1;
	}
	return (holder);
}
