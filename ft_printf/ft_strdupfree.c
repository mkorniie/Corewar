/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 18:10:51 by mkorniie          #+#    #+#             */
/*   Updated: 2017/10/31 18:48:04 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_strdupfree(char *s1)
{
	char	*s2;
	int		len;

	len = ft_strlen(s1);
	s2 = (char*)malloc(sizeof(char) * (len + 1));
	if (s2 == NULL)
		return (NULL);
	s2[len] = '\0';
	s2 = ft_strcpy(s2, s1);
	free(s1);
	return (s2);
}

char	*ft_strdupfreearg(char *s1, char *fr)
{
	char	*s2;
	int		len;

	len = ft_strlen(s1);
	s2 = (char*)malloc(sizeof(char) * (len + 1));
	if (s2 == NULL)
		return (NULL);
	s2[len] = '\0';
	s2 = ft_strcpy(s2, s1);
	free(fr);
	return (s2);
}
