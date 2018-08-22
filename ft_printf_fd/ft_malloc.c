/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 16:09:10 by mkorniie          #+#    #+#             */
/*   Updated: 2018/03/21 16:10:52 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		*ft_mallocintpzero(int len)
{
	int *res;

	res = (int *)malloc(sizeof(int) * len);
	res[len - 1] = 0;
	return (res);
}

char	*ft_malloccharpzero(int len)
{
	char *res;

	res = (char *)malloc(sizeof(char) * len);
	res[len - 1] = 0;
	return (res);
}
