/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 11:06:04 by mkorniie          #+#    #+#             */
/*   Updated: 2017/11/13 11:06:14 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	int				size;
	unsigned char	zero;

	if (s == 0)
		return ;
	size = ft_strlen(s);
	zero = '\0';
	s = ft_memset(s, zero, size);
}
