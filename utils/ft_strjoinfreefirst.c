/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfreefirst.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkorniie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 12:55:54 by mkorniie          #+#    #+#             */
/*   Updated: 2018/07/05 12:55:55 by mkorniie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../asm.h"

char	*ft_strjoinfreefirst(char *to_free, char *to_add)
{
	char		*res;

	res = ft_strjoin(to_free, to_add);
	free(to_free);
	return (res);
}
