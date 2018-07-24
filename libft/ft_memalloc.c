/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 10:59:20 by mkorniie          #+#    #+#             */
/*   Updated: 2017/11/13 10:59:34 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *a;

	if (size == 0)
		return (0);
	a = malloc(size);
	if (a == 0)
		return (0);
	ft_bzero(a, size);
	return (a);
}
