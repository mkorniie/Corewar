/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 14:40:25 by mkorniie          #+#    #+#             */
/*   Updated: 2018/03/18 14:40:36 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	*ft_strjoinfree(char const *s1, char const *s2, int s_to_delete)
{
	char	*str;
	size_t	len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = ft_strnew(len);
	if (str == NULL)
		return (NULL);
	str = ft_strcat(str, s1);
	str = ft_strcat(str, s2);
	if (s_to_delete == 1)
		free(s1);
	else if (s_to_delete == 2)
		free(s2);
	else if (s_to_delete == 3)
	{
		free(s1);
		free(s2);
	}
	else
		ft_putstr("ft_strjoinfree: invalid s_to_delete. Options: 1, 2, 3\n");
	return (str);
}
