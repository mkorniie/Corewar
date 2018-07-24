/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 11:12:23 by mkorniie          #+#    #+#             */
/*   Updated: 2017/11/13 11:12:31 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	char *str1;
	char *str2;

	if (s1 == NULL || s2 == NULL)
		return (0);
	if (n >= ft_strlen(s1))
		n = ft_strlen(s1);
	if (n >= ft_strlen(s2))
		n = ft_strlen(s2);
	str1 = (char*)malloc(n + 1);
	str1 = (char*)ft_memset(str1, 48, n);
	str2 = (char*)malloc(n + 1);
	str2 = (char*)ft_memset(str2, 48, n);
	str1 = ft_strncpy(str1, s1, n);
	str2 = ft_strncpy(str2, s2, n);
	return (ft_strequ(str1, str2));
}
