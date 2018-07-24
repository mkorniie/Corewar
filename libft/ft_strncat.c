/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 21:27:17 by mkorniie          #+#    #+#             */
/*   Updated: 2017/11/02 21:28:25 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t size_1;
	size_t size_2;

	size_1 = ft_strlen(s1);
	size_2 = ft_strlen(s2);
	if (n > size_2)
		n = size_2;
	i = size_1;
	while (i < (size_1 + n))
	{
		s1[i] = s2[i - size_1];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
