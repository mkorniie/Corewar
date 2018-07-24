/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 11:12:44 by mkorniie          #+#    #+#             */
/*   Updated: 2017/11/13 11:14:01 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_is_wspace(char a)
{
	if (a == ' ' || a == '\n')
		return (1);
	if (a == '\t')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	int		start;
	size_t	len;

	if (s == NULL)
		return (NULL);
	start = 0;
	len = ft_strlen(s);
	while (ft_is_wspace(s[start]) != 0 && s[start] != '\0')
		start++;
	if (s[start] == '\0')
		return (ft_strdup(""));
	while (ft_is_wspace(s[len - 1]) != 0)
		len--;
	str = ft_strsub(s, start, len - start);
	return (str);
}
