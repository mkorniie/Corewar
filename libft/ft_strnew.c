/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 11:11:20 by mkorniie          #+#    #+#             */
/*   Updated: 2017/11/13 11:11:41 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	void			*str;
	char			*c;
	unsigned char	zero;

	zero = '\0';
	str = malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	str = ft_memset(str, zero, size + 1);
	c = str;
	return (c);
}
