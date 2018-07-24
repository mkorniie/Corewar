/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 11:11:50 by mkorniie          #+#    #+#             */
/*   Updated: 2017/11/13 11:22:18 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_strndupfree(const char *s1, size_t n)
{
	char *s2;

	if (n > ft_strlen(s1))
		n = ft_strlen(s1);
	s2 = (char*)malloc(sizeof(s1) * (n + 1));
	if (s2 == NULL)
		return (NULL);
	s2[n] = '\0';
	s2 = (char*)ft_memset(s2, 48, n);
	s2 = ft_strncpy(s2, s1, n);
	free(s1);
	return (s2);
}
