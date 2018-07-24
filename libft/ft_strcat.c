/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 21:21:03 by mkorniie          #+#    #+#             */
/*   Updated: 2017/11/02 21:26:52 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strcat(char *s1, const char *s2)
{
	int i;
	int size_1;
	int size_2;

	size_1 = ft_strlen(s1);
	size_2 = ft_strlen(s2);
	i = size_1;
	while (i < (size_1 + size_2))
	{
		s1[i] = s2[i - size_1];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
